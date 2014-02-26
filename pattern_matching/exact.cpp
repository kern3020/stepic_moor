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
  map<char, list<int> > charToSkipDistance; // todo: should it restrict it to genomic alphabet?

  // guard - if either pattern or text is empty, return empty list of indices.
  if (pat.empty() || text.empty() ) {
    return indices_found;  
  }

  // preprocessing - bad character table
  int i = pat.length() -1;
  do {
    char ch  = pat[i];
    charToSkipDistance[ch].push_back(i);
    i--;
  } while (i >= 0);
  
  // print table 
  map<char, list<int> >::iterator pos; 
  for (pos = charToSkipDistance.begin(); pos != charToSkipDistance.end(); ++pos){
    cout << "key: " << pos->first << "\t" 
  	 << "value: " ;
    list<int>::iterator list_pos;
    for(list_pos = pos->second.begin(); list_pos != pos->second.end(); ++list_pos){
       cout << *list_pos << " "; 
    }
    cout << endl;
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
      // found match 
      indices_found.push_front(h);
      if( k + n > m) {
	k = m;
      } else { 
	k = k + n + 1 ;
      }
    } else {
      // apply bad character rule 
      char ch = text[h];
      if (pat.find(ch) == string::npos){
	k += n + 1; 
      } else {
	list<int> indices = charToSkipDistance[ch];
	list<int>::iterator list_pos;
	for(list_pos = indices.begin(); list_pos != indices.end(); ++list_pos){
	  if (*list_pos < i) {
	    k += *list_pos + 1;
	    break; 
	  }
	}
      }
    }
  }

  return indices_found; 
}

