#include "kmer_node.h"

#include <cassert>

int KmerNode::hamming(string seq) {
  int deltas = 0; 
  assert(this->name.length() == seq.length());
  int s = this->name.length();
  for (int i = 0; i < s; i++) {
    if (this->name[i] != seq[i]) {
      deltas += 1;
    }
  }
  return deltas; 
}

/**
   This implementation of levensthein distance is very readable and
   directly maps to the algorithm. Performance may be an issue. If so,
   keep this version around. The unit tests can use it to compare
   against the optimize version.
 */

int KmerNode::levensthein(const string &s, int len_s, const string &t, int len_t){
  if (len_s == 0 ) return len_t;
  if (len_t == 0 ) return len_s; 

  int cost = s[len_s - 1] == t[len_t - 1] ? 0 : 1;
  
  return min({ 
      this->levensthein(s, len_s - 1, t, len_t) + 1, 
	this->levensthein(s, len_s, t, len_t - 1 ) + 1 , 
	this->levensthein(s, len_s - 1, t, len_t - 1 ) + cost
	}); 
}

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

