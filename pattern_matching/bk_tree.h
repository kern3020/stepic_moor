#ifndef BK_TREE_H
#define BK_TREE_H

#include "kmer_node.h"
#include <string>

using namespace std;

/**
   BK trees are designed to find patterns which are similar to other
   tokens which similarity is defined by distance. Distance is defined
   by the KmerNode class.
 */

class BkTree { 
  shared_ptr<KmerNode> root; 

 private: 
  /**
   */
  void find_matches(const string &seq, int tolerance, 
		    shared_ptr<KmerNode> node,  
		    shared_ptr<vector<KmerNode>> matches, int depth);

  /**
     Used internally to recurively insert a node. 
   */
  void insert(string seq, int pos, shared_ptr<KmerNode> node);

  /**
     Used internally to recurively print the tree. 
   */ 
  void print(KmerNode &node, int distance, int ident_level); 

 public: 
 BkTree(): root(nullptr) {} 

  /**
     Given a string 'seq', return a vector of strings within distance
     'tolerance'.
   */
  shared_ptr<vector<KmerNode>> find_matches(const string &seq, int tolerance); 

  /**
     insert a node.
   */
  void insert(string seq, int pos);

  /**
     print entire tree.
   */
  void print();

};

#endif
