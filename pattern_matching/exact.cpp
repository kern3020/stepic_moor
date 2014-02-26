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

using namespace std;

// start with 
// http://en.wikipedia.org/wiki/Boyer%E2%80%93Moore%E2%80%93Horspool_algorithm

list<int> exact_match(const string &pat, const string &text) {
  list<int> indices_found; // index (or indices) for each match.
  int n = pat.length(); 
  int last = n - 1; // position of last char in pattern
  int m = text.length();

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
  

  return indices_found; 

}

