from __future__ import division

import os
import sys 

import matplotlib.pyplot as plt

from Bio import SeqIO

'''
I am hunting for the origin of replication(s) in W.glossinidia. 
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

def plot_gc(filename, title):
    for rec in SeqIO.parse(filename, 'fasta'):
        pts = compute_gc(rec.seq)
        plt.plot(pts)
    plt.title(title)
    plt.xlabel("position")
    plt.ylabel('GC skew')

def main(argv):
    fig = plt.figure()
    plot_gc('data/W.glossinidia.fasta', 'GC skew - W.glossinidia')
    plt.show()

if __name__ == '__main__':
    main(sys.argv)
