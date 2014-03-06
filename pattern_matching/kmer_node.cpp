#include "kmer_node.h"

#include <cassert>

int KmerNode::hamming(string n1, string n2) {
  int deltas = 0; 
  assert(n1.length() == n2.length());
  for (int i = 0; i < n1.length(); i++) {
    if (n1[i] != n2[i]) {
      deltas += 1; 
    }
  }
  return deltas; 
}

bool KmerNode::hasChild(int key) {
  return  (this->children.find(key) != this->children.end() ? true : false );  
}

const shared_ptr<KmerNode> KmerNode::getChild(int key) {
  return (this->hasChild(key) ? this->children[key] : nullptr);
}

void KmerNode::inc(int pos) {
  this->count += 1; 
  this->positions.push_back(pos);
}

void KmerNode::insertChild(int key, std::shared_ptr<KmerNode> node) {
  this->children[key] = node;
}

bool KmerNode::operator==(const KmerNode &other) const {
  return (this->name == other.name ? true : false) ;
}

bool KmerNode::operator!=(const KmerNode &other) const {
  return !(*this == other);
}

ostream& operator<<(ostream& ost,  KmerNode& node)
{
  ost << "<seq: " << node.name << ", count: " << node.count ;
  pair<vector<int>::iterator, 
       vector<int>::iterator> p =  node.iteratorPair();
  ost << " pos: [";
  bool the_rest = false; 
  for (; p.first != p.second; p.first++) {
    if (the_rest == false) {
      the_rest = true;
    } else {
      ost << ", "; 
    }
    ost << *p.first;
  }
  ost << "] >";
  return ost;
}

pair<vector<int>::iterator,vector<int>::iterator> KmerNode::iteratorPair() {
  return make_pair(this->positions.begin(), this->positions.end());
}
