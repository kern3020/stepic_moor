#include "gtest/gtest.h"
#include "freq_partial.h"

TEST(FreqPartialTest, seqOneTest) {
  string seq("CACAGTAGGCGCCGGCACACACAGCCCCGGGCCCCGGGCCGCCCCGGGCCGGCGGCCGCCGGCGCCGGCACACCGGCACAGCCGTACCGGCACAGTAGTACCGGCCGGCCGGCACACCGGCACACCGGGTACACACCGGGGCGCACACACAGGCGGGCGCCGGGCCCCGGGCCGTACCGGGCCGCCGGCGGCCCACAGGCGCCGGCACAGTACCGGCACACACAGTAGCCCACACACAGGCGGGCGGTAGCCGGCGCACACACACACAGTAGGCGCACAGCCGCCCACACACACCGGCCGGCCGGCACAGGCGGGCGGGCGCACACACACCGGCACAGTAGTAGGCGGCCGGCGCACAGCC");
  int k = 10;
  int d = 2;
  freqPartial(seq, k, d);
}


/**
  Check the literature. I'll bet the literature it tells us
  specifically where the DnaA binding sites are for e. coli. If so,
  this would make a terrific test to calibrate our algorithm. Compare
  the results of this algorithm on e.coli with the expected results
  from the literature.

http://arep.med.harvard.edu/ecoli_matrices/dat/dnaA.dat

>dnaA_1 rpoH-1
aatttattcacaagc
>dnaA_2 rpoH-2
attttatccacaagt
>dnaA_3 nrd
gagttatccacaaag
>dnaA_4 oriC-R1
ttgttatccacaggg
>dnaA_5 oriC-R2
ggggttatacacaac
>dnaA_6 oriC-R3
ttctttggataacta
>dnaA_7 oriC-R4
gagttatccacagta
>dnaA_10   dnaA
gatttatccacagga

http://regulondb.ccg.unam.mx/operon?term=ECK120014379&format=jsp&organism=ECK12&type=operon#dnaAN-recF_dnaAp1
left pos: 3881958 	
right pos: 3881966 	 	
aagtcctgtgGATAAATCGggaaaatctg

 */
