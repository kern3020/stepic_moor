import os
import pdb
import sys 

import pylab
import numpy as np
import matplotlib.pyplot as plt

from Bio import Entrez
from Bio import SeqIO

'''
Code used to investigate an open problem posed by: 

Finding Replication Origins in Draft Bacterial Genomes
https://wiki.research.stepic.org/view/Finding_Replication_Origins_in_Draft_Bacterial_Genomes

'''

class Contig(object):
    def __init__(self, seq_id, seq, size):
        self._id = seq_id
        self._seq = seq
        self._size = size

    def __cmp__(self, other):
        rc = 0 
        if self.size() < other.size():
            rc = -1
        elif self.size() > other.size():
            rc = 1
        return rc

    def __str__(self):
        return '<{0}, {1}>'.format(self._size, self._id)

    def seq(self):
        return self._seq

    def size(self):
        return self._size


class Genome(object):
    '''
    With TM6 I initially want to confirm some simple assertions made
    in the paper to confirm.
    '''
    def __init__(self, filename):
        self._length_of_all_contigs = 0
        self._length_of_seven = 1074690
        self._N50 = None
        self._filename = filename
        self._contigs = []

    def compute(self):
        for seq_record in SeqIO.parse(self._filename, "fasta"):
            s = len(seq_record.seq)
            c = Contig(seq_record.id, seq_record.seq, s)
            self._length_of_all_contigs += s
            self._contigs.append(c)
        self._contigs.sort(reverse=True)
        # compute N50 
        fifty_precent_mark = self._length_of_all_contigs/2
        length_to_date = 0
        for i in range(len(self._contigs)):
            length_to_date += self._contigs[i].size()
            # print(length_to_date) ; pdb.set_trace()
            if length_to_date > fifty_precent_mark:
                self._N50 = self._contigs[i].size()

    def _is_mda(self, expected_N50, expected_longest):
        rc = True
        if expected_N50 != self._N50:
            rc = False
        elif expected_longest != self.longest_contig():
            rc = False
        return rc

    def is_mda1(self):
        expected_N50 = 45160
        expected_longest = 329507
        return self._is_mda(expected_N50, expected_longest)

    def is_mda2(self):
        expected_N50 = 42853
        expected_longest = 464047
        return self._is_mda(expected_N50, expected_longest)

    def is_mda3(self):
        expected_N50 = 36106
        expected_longest = 489351
        return self._is_mda(expected_N50, expected_longest)

    def longest_contig(self):
        return self._contigs[0].size() 

    def N50(self):
        return self._N50

    def print_top_n(self, n=25):
        for i in range(n):
            print(self._contigs[i])


def gilford_sequence():
    '''
    This fasta file was provide by Professor Mikhail Gelfand. 
    https://beta.stepic.org/media/attachments/lessons/64/TM6MDA2_iter.fasta
    '''
    filename = "data/TM6MDA2_iter.fasta"
    ge = Genome(filename)
    ge.compute()
    '''
    McLean et al report on three samples: MDA1, MDA2 and MDA3
    Based on table 1, Gelfand's sample is different because
    the statics different.
    '''
    print('longest contig: {0}'.format(ge.longest_contig()))
    print('N50: {0}'.format(ge.N50()))

def fetch_TM6SC1():
    '''
    The genomic data for candidate division TM6 bacterium JCVI TM6SC1 can
    be accessed from NCBI. They were stored as seven separate contigs.
    This function downloads them. 
    '''
    Entrez.email = os.environ.get('ENTREZ_EMAIL')
    data_dir = 'data/TM6SC1'
    if not os.path.isdir(data_dir):
        try:
            os.makedirs(data_dir)
        except OSError as exc: # Python >2.5
            if exc.errno == errno.EEXIST and os.path.isdir(path):
                pass
            else: raise

    for i in range(1, 8): 
        gi = '48438475' + str(i)  # tm6 contigs are 48438475[1..7]
        handle = Entrez.efetch(db="nucleotide", id=gi, rettype="fasta", retmode="text")

        header = handle.readline()  # read header 
        a1 = header.split('|')
        accession_name = a1[3]  # get accession name
        filename = '{0}/{1}.fasta'.format(data_dir, a1[3])
        if not os.path.isfile(filename):
            with open(filename, 'w') as output_handle:
                output_handle.write(header)
                for buf in handle.read():
                    output_handle.write(buf)

def main(argv):
    # gilford_sequence()
    fetch_TM6SC1()

if __name__ == '__main__':
    main(sys.argv)
