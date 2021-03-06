#ifndef KMER_NODE_H
#define KMER_NODE_H

#include <algorithm>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

using namespace std;

#include "distance.h"

/**
   K-mer is a K length sequence. So, I 9-mer is a sequence of length
   9. This class will be used in a bk-tree to find sequences of the
   genome which repeat. 

   This KmerNode is designed to work with a BK Tree. The edge between
   the parent and child is the edit distance between the names of the
   two nodes. 
 */

class KmerNode {

  string name; // name of k-mer
  vector<int> positions;
  int count;
  map< int, shared_ptr<KmerNode> > children; // edit distance => node

 public:

  KmerNode(const string &kmer_name, int pos) { 
    this->name = kmer_name;
    transform(this->name.begin(), this->name.end(), this->name.begin(), ::toupper);
    this->positions.push_back( pos);
    this->count = 1;
  }

  int getCount() { return count; } 
  const string &getName() { return  name;  } 
  
  /**
     Return KmerNode associated with key or NULL if key is not used.  
   */ 
  const shared_ptr<KmerNode> getChild(int distance);
  bool hasChild(int distance);
  void insertChild(int distance, std::shared_ptr<KmerNode> node);

  /**
     When a kmer is found multiple times, increment the count and
     store the position.
   */
  void inc(int pos);

  /*
    Provide iterators to allow for callee to access to children
   */ 

  map<int, shared_ptr<KmerNode>> childrenIterator() {
    return this->children; 
  }

  /*
    Provide iterators to allow for callee to access to postions where this node was found. 
   */ 
  pair<vector<int>::iterator,vector<int>::iterator> positionIteratorPair() {
    return make_pair(this->positions.begin(), this->positions.end());
  }

  /**
     Computes edit distance. 
   */ 
  int distance(string seq) {
    transform(seq.begin(), seq.end(), seq.begin(), ::toupper);
    unique_ptr <SeqAlignDP> d_ptr ( new SeqAlignDP(this->name, seq) );
    return d_ptr->distance();
  }

  // operators 
  bool operator==(const KmerNode &other) const;
  bool operator!=(const KmerNode &other) const;
  friend ostream& operator<<(ostream& ost,  KmerNode& node);

};

#endif
