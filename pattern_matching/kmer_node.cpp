#include "kmer_node.h"

#include <cassert>

bool KmerNode::hasChild(int key) {
  bool rc = false;
  if (this->children.find(key) != this->children.end()) {
    rc = true;
  }
  return rc; 
}

KmerNode * KmerNode::getChild(int key) {
  KmerNode *rc = NULL;
  if (this->hasChild(key)) {
    rc = this->children[key];
  }
  return rc;
}

void KmerNode::insertChild(int key, KmerNode &node) {
  this->children[key] = &node;
}

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


bool KmerNode::operator==(const KmerNode &other) const {
  bool rc = false;
  if (this->name == other.name) {
     rc = true; 
  }
  return rc;
}

bool KmerNode::operator!=(const KmerNode &other) const {
  return !(*this == other);
}

ostream& operator<<(ostream& ost, const KmerNode& node)
{
        ost<< "<seq: " << node.name << ", count: " << node.count << " >";
        return ost;
}

