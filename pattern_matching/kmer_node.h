#ifndef KMER_NODE_H
#define KMER_NODE_H

#include <iostream>
#include <map>
#include <string>

using namespace std;

/**
   K-mer is a K length sequence. So, I 9-mer is a sequence of length
   9. This class will be used in a bk-tree to find sequences of the
   genome which repeat. 
 */

class KmerNode {

  string name; // name of k-mer
  int pos;
  int count;
  map<int, KmerNode*> children; 

 public:

 KmerNode(const string &name, int pos) : name(name), pos(pos), count(1) { }

  int getCount() { return count; } 
  const string getName() { return  name;  } 
  
  /**
     Return KmerNode associated with key or NULL if key is not used.  
   */ 
  KmerNode * getChild(int key);
  bool hasChild(int key); 
  void insertChild(int key, KmerNode &node);

  /**
     Return the Hamming distance between two equal length strings. 
   */
  static int hamming(string n1, string n2);

  // operators 
  bool operator==(const KmerNode &other) const;
  bool operator!=(const KmerNode &other) const;
  friend ostream& operator<<(ostream& ost, const KmerNode& node);

};

#endif
