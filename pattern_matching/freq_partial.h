#ifndef FREQ_PARTIAL_H
#define FREQ_PARTIAL_H

#include <string>

using namespace std;

/**
   Given a large sequence(call text) print all occurences of a small
   sequence(call pattern) within edit distance d. We are hunting for
   the DnaA boxes for the origin of replication. 
 */

void freqPartial(string seq, int k, int d);

#endif
