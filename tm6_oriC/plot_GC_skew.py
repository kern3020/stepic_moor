from __future__ import division

import os
import sys 

import matplotlib.pyplot as plt

from Bio import SeqIO

'''
I am hunting for the origin of replication for TM6. The samples
availble have contain about 90% of the expected genome for TM6

this code is helpful to plot the GC skew 
'''

def compute_gc(seq):
    gc_skew = 0
    vals = []
    for i in range(len(seq)):
        if seq[i] == 'C':
            gc_skew -= 1
        elif seq[i] == 'G':
            gc_skew += 1
        vals.append(gc_skew)
    return vals

def plot_gc(filename, title, version):
    rows = 4
    cols = 2
    plt.subplot(rows, cols, version)
    for rec in SeqIO.parse(filename, 'fasta'):
        pts = compute_gc(rec.seq)
        plt.plot(pts)
    plt.title(title)
    plt.xlabel("position")
    plt.ylabel('skew')

def tm6_contig_TM6SC1(version):
    filename = 'data/TM6SC1/ARQD0100000{0}.1.fasta'.format(version)
    title = 'contig {0}: ARQD0100000{0}.1'.format(version)
    plot_gc(filename, title, version)


def main(argv):
    fig = plt.figure()
    for i in range(1, 8):
        tm6_contig_TM6SC1(i)
    fig.tight_layout()
    fig.suptitle("GC Skew - TM6")
    plt.show()

if __name__ == '__main__':
    main(sys.argv)
