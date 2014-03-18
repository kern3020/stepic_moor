#include "bk_tree.h"

void BkTree::find_matches(const string &seq, int tolerance, 
			  shared_ptr<KmerNode> node,  
			  shared_ptr<vector<KmerNode>> matches,  int depth) {
  int nd = node->distance(seq);
  if (nd <= tolerance) {
    matches->push_back(*node);
  }

  int lower_bound = nd - tolerance; 
  int upper_bound = nd + tolerance; 
  for (int i = lower_bound; i <= upper_bound; i++){
    if (node->hasChild(i)) {
      this->find_matches(seq, tolerance, node->getChild(i), matches, ++depth); 
    }
  }
}

shared_ptr<vector<KmerNode>> BkTree::find_matches(const string &seq, int tolerance) {
  auto results = make_shared<vector<KmerNode>>();
  int depth = 0; 
  if (this->root) { 
    this->find_matches(seq, tolerance, this->root, results, depth);
  }
  return results;
}

void BkTree::insert(string seq, int pos) {
  transform(seq.begin(), seq.end(), seq.begin(), ::toupper);
  if (this->root == nullptr) { 
    this->root = make_shared<KmerNode>(seq, pos);
  } else {
    this->insert(seq, pos, root);
  }
}

void BkTree::insert(string seq, int pos, shared_ptr<KmerNode> node) {
  if (seq == node->getName()) {
    node->inc(pos);
  } else {
    int d = node->distance(seq);
    if (!node->hasChild(d) ) {
      node->insertChild(d, make_shared<KmerNode>(seq, pos));
    } else {
      this->insert(seq, pos, node->getChild(d));
    }
  }
}

void BkTree::print() {
  if (this->root != nullptr) { 
    this->print(*this->root, -1, 0); 
  }
}

void BkTree::print(KmerNode &node, int distance, int ident_level) {
  if (distance == -1 ) {  // 
    cout << string(ident_level, '\t') << node << endl;  // print self
  } else {
    cout << string(ident_level, '\t') << "d: " << distance << " " << node << endl;  // print self
  }

  // print children
  ident_level += 1; 
  for (auto &elem : node.childrenIterator()) { 
    this->print(*elem.second, elem.first, ident_level);
  }
}
