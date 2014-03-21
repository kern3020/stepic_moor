#include <algorithm>
#include <cassert>
#include <iostream>

#include "distance.h"

using namespace std;

int Hamming::distance () {
  int deltas = 0; 
  assert(this->seq1.length() == this->seq2.length());
  int s = this->seq1.length();
  for (int i = 0; i < s; i++) {
    if (this->seq1[i] != this->seq2[i]) {
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

int LevenstheinReference::distance() {
  return this->distance(this->seq1, this->seq1.size(), 
			this->seq2, this->seq2.size());
}

SeqAlignDP::SeqAlignDP(const string &s1, const string &s2) {
  this->seq1 = s1;
  // number of rows must include length of string plus on for dp. 
  this->nrows = s1.length() + 1; 
  this->seq2 = s2; 
  // number of colums must include length of string plus on for dp. 
  this->ncols = s2.length() + 1;

  // create 2d dimensional array 
  this->matrix = new int [nrows * ncols]; 
}

SeqAlignDP::~SeqAlignDP() {
  delete [] this->matrix;
}

int SeqAlignDP::distance() {
  // initialize 
  for (int i = 0; i < nrows; i++) {
    for (int j = 0; j < ncols ; j++) {
      this->matrix[i*ncols + j] = 0;
    }
  }

  // base condition 
  for (int j = 0; j < ncols; j++) {
    this->matrix[j] = j; 
  }

  for (int i = 0; i < nrows; i++) {
    this->matrix[ncols*i] = i; 
  }

  // compute matrix  
  for (int i = 1; i < nrows ; i++ ) { 
    for (int j = 1; j < ncols; j++ ) {
      // pick minimum move. 
      int down = this->matrix[(i-1)*ncols + j] ;
      down += 1;
      int right = this->matrix[i*ncols + j - 1] ;
      right += 1; 
      int diag = this->matrix[(i-1) * ncols + j - 1] ;
      diag += (seq1[i-1] == seq2[j-1] ? 0 : 1); 
      this->matrix[i*ncols + j] = min ({ down, right, diag });
    }
  }
  return this->matrix[(nrows-1)*(ncols)+(ncols-1)];
}

void SeqAlignDP::print() {
  // print header 
  cout << "D(i,j)\t\t" ;
  for (int j = 0; j < ncols ; j++) {
    cout << '\t' << seq2[j] ;
  }
  cout << endl;

  cout << '\t'; 
  for (int j = 0; j < ncols ; j++) {
    cout << '\t' << j;
  }
  cout << endl;

  for (int j = 0; j < (ncols+2)*8 ; j++) {
    cout << '-';
  }
  cout << endl;
  
  // print matrix itself 
  for (int i = 0; i < nrows; i++) {
    if (i > 0) {
      cout << seq1[i-1]; 
    }
    cout << '\t' << i;
    for (int j = 0; j < ncols ; j++) {
      cout << '\t' << this->matrix[i*ncols + j] ; 
    }
    cout << endl;
  } 
}
