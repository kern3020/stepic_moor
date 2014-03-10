#include "gtest/gtest.h"
#include "bk_tree.h"

#include <memory>

TEST (BkTreeTest, Insert) {
  unique_ptr<BkTree> tree(new BkTree);
  tree->insert("book", 2);
  tree->insert("books", 3);
  tree->insert("cake", 56);
  tree->insert("boo", 156);
  tree->insert("cook", 64);
  tree->insert("boon", 86);
  tree->insert("cape", 33);
  tree->insert("cart", 53);
  tree->print();
  EXPECT_EQ("FOO", "FOO"); 
}
