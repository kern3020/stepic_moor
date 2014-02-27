/*
  Exact match of pattern in text. 
 */

#include <algorithm>
#include <cerrno>
#include <cstdlib>
#include <cstring> 
#include <iostream>
#include <list>
#include <map>
#include <string>

using namespace std;

list<int> exact_match(const string &pat, const string &text) {
  list<int> indices_found; // index (or indices) for each match.

  // given a character and index in a pattern, how much should skip it? 
  map<char,int> charToSkipDistance; 

  // guard - if either pattern or text is empty, return empty list of indices.
  if (pat.empty() || text.empty() ) {
    return indices_found;  
  }

  // preprocessing - skip table
  
  for(int i = 0; i < pat.length(); i++) {
    int val = max(1, int(pat.length() - 1 - i));
    charToSkipDistance[pat[i]] = val;
  } 
  
  // print table 
  map<char, int>::iterator pos; 
  for (pos = charToSkipDistance.begin(); pos != charToSkipDistance.end(); ++pos){
    cout << "key: " << pos->first << "\t" 
  	 << "value: " << pos->second << endl;
  }

  // search 
  int n = pat.length() - 1 ; 
  int m = text.length() - 1;
  int k = n; // k is index of the last element in the text
  while (k <= m) {
    int i = n;
    int h = k;
    while (i > 0 && pat[i] == text[h]) {
      i--;
      h--;
    }
    if (i == 0) {
      if (pat[i] == text[h]) {
	// found match 
	indices_found.push_back(h);
      }
      if( k + n > m) {
	k = m;
      } else { 
	k = k + n + 1 ;
      }
    } else {
      // apply skip table
      char ch = text[h];
      if (pat.find(ch) == string::npos){
	k += n + 1; 
      } else {
	k += charToSkipDistance[ch];
      }
    }
  }

  return indices_found; 
}

