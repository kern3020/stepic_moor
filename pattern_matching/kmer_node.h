#ifndef KMER_NODE_H
#define KMER_NODE_H

#include <algorithm>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

using namespace std;

/**
   K-mer is a K length sequence. So, I 9-mer is a sequence of length
   9. This class will be used in a bk-tree to find sequences of the
   genome which repeat. 
 */

class KmerNode {

  string name; // name of k-mer
  vector<int> positions;
  int count;
  map< int, shared_ptr<KmerNode> > children; 

 public:

  KmerNode(const string &name, int pos) { 
    this->name = name;
    transform(this->name.begin(), this->name.end(), this->name.begin(), ::toupper);
    this->positions.push_back( pos);
    this->count = 1;
  }

  int getCount() { return count; } 
  const string &getName() { return  name;  } 
  
  /**
     Return KmerNode associated with key or NULL if key is not used.  
   */ 
  const shared_ptr<KmerNode> getChild(int key);
  bool hasChild(int key); 
  void insertChild(int key, std::shared_ptr<KmerNode> node);

  /**
     When a kmer is found multiple times, increment the count and
     store the position.
   */
  void inc(int pos); 

  /*
    Provide iterators to allow for callee to access to postions where this node was found. 
   */ 
  pair<vector<int>::iterator,vector<int>::iterator> iteratorPair();

  /**
     Return the Hamming distance between two equal length strings. 
   */
  static int hamming(string n1, string n2);


  // operators 
  bool operator==(const KmerNode &other) const;
  bool operator!=(const KmerNode &other) const;
  friend ostream& operator<<(ostream& ost,  KmerNode& node);

};

#endif
