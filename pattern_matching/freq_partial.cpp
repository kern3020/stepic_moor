
#include <memory>
#include <set>
#include <string>

#include "gtest/gtest.h"
#include "bk_tree.h"
#include "freq_partial.h"

void freqPartial( string seq, int k, int d) {
  unique_ptr<BkTree> tree(new BkTree); 
  set<string> kmersInText; 
  set<string> kmersConsidered; // cache 
  // populate tree 
  size_t s = seq.size() + 1 - k ; 
  for (int i = 0; i < s; i++) {
    tree->insert(seq.substr(i,k), i);
    kmersConsidered.insert(seq.substr(i,k));
    kmersInText.insert(seq.substr(i,k));
  }

  // find most frequent kmer

  // for each kmer in the sequence
  
  for (const auto &kmer : kmersInText) {
    // consider this kmer
    shared_ptr <vector<KmerNode>> r = tree->find_matches(kmer, 2);
    cout << "Found " << r->size() << " hits for " << kmer << endl;
    for (auto elem : *r) {
      cout << '\t' << elem << endl; 
    }

    // -- 2) consider kmers which are within distance, d, from this kmer
    // -- from the text.

    // -- 3) consider the reverse complement of this kmer. 
    string kmer_rev(kmer);
    transform(kmer_rev.begin(), kmer_rev.end(),
	      kmer_rev.begin(), 
	      [] (char ch) {
		char rc; 
		switch(ch) {
		case 'A':
		  rc = 'T';
		case 'T':
		  rc = 'A';
		case 'G':
		  rc = 'C';
		case 'C':
		  rc = 'G';
		default:
		  rc = ch; 
		}
		return rc; 
	      });
    cout << "reversed: " << kmer_rev << endl; 
    r = tree->find_matches(kmer_rev, 2);
    cout << "Found(reversed) " << r->size() << " hits for " << kmer_rev << endl;
    for (auto elem : *r) {
      cout << '\t' << elem << endl; 
    }

    // -- 4) consider kmers which are within distance, d, of this
    // -- reverse complement strand.


  }
}

