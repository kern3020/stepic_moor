#include <algorithm>
#include <cassert>

#include "distance.h"

int Hamming::distance (const string &s1, const string &s2) {
  int deltas = 0; 
  assert(s1.length() == s2.length());
  int s = s1.length();
  for (int i = 0; i < s; i++) {
    if (s1[i] != s2[i]) {
      deltas += 1;
    }
  }
  return deltas;
}


int LevenstheinReference::distance(const string &s, int len_s, const string &t, int len_t) {
  if (len_s == 0 ) return len_t;
  if (len_t == 0 ) return len_s; 

  int cost = s[len_s - 1] == t[len_t - 1] ? 0 : 1;
  
  return min({ 
      this->distance(s, len_s - 1, t, len_t) + 1, 
       this->distance(s, len_s, t, len_t - 1 ) + 1 , 
       this->distance(s, len_s - 1, t, len_t - 1 ) + cost
       });
} 

int LevenstheinReference::distance(const string &s1, const string &s2) {
  return this->distance(s1, s1.size(), s2, s2.size());
}
