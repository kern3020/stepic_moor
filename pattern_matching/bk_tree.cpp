#include "bk_tree.h"

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
    int d = node->levensthein(seq);
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
