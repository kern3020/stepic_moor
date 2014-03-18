#include "kmer_node.h"


bool KmerNode::hasChild(int distance) {
  return  (this->children.find(distance) != this->children.end() ? true : false );  
}

const shared_ptr<KmerNode> KmerNode::getChild(int distance) {
  return (this->hasChild(distance) ? this->children[distance] : nullptr);
}

void KmerNode::insertChild(int distance, std::shared_ptr<KmerNode> node) {
  this->children[distance] = node;
}

void KmerNode::inc(int pos) {
  this->count += 1; 
  this->positions.push_back(pos);
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
       vector<int>::iterator> p =  node.positionIteratorPair();
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

