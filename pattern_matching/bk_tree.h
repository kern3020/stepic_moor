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
     insert a node.
   */
  void insert(string seq, int pos);

  /**
     print entire tree.
   */
  void print();

};

#endif
