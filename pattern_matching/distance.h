#ifndef DISTANCE_H
#define DISTANCE_H

#include <string>

using  namespace std;

class Distance {
 public:
  virtual int distance (const string &s1, const string &s2) = 0;
}; 

class Hamming : public Distance {
 public: 
  virtual int distance (const string &s1, const string &s2);
};


/**
   This implementation of levensthein distance is very readable and
   directly maps to the algorithm. Performance may be an issue. If so,
   keep this version around. The unit tests can use it to compare
   against the optimize version.
 */

class LevenstheinReference : public Distance {
  /**
     internally call to recursively compute levensthein distance. 
  */
  int distance(const string &s, int len_s, const string &t, int len_t);
  
 public:
  virtual int distance (const string &s1, const string &s2);
};

/**
   Use dynamic programming to compute the edit distance(shortest path)
   between to strings. 
 */
class SeqAlignDP {
  string seq1;
  string seq2;
  int nrows; 
  int ncols;
  int *matrix; 
 public:
  SeqAlignDP(const string &s1, const string &s2);
  ~SeqAlignDP();
  int distance();
  void print(); 
}; 

#endif
