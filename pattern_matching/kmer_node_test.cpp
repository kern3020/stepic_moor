#include "gtest/gtest.h"
#include "kmer_node.h"

#include <memory>

TEST(KmerNodeTest, Children) {
  auto n1 = make_shared<KmerNode>("ACGT", 43);
  auto n2 = make_shared<KmerNode>("TGCA", 26);
  int d = n1->distance(n2->getName());
  n1->insertChild(d, n2);
  auto n2r = n1->getChild(d);
  EXPECT_EQ(n2r->getName(), n2->getName());
}

TEST(KmerNodeTest, ToUpper) {
  KmerNode n1("acgt", 234);
  EXPECT_EQ("ACGT", n1.getName());
}

TEST(KmerNodeTest, SimpleEquality) {
  KmerNode n1("ACGTTCTC", 23);
  KmerNode n2("ACGTTCTC", 441);
  KmerNode n3("TTCTCACAGAG", 352);
  EXPECT_EQ(n1,n2);
  EXPECT_NE(n1,n3);
}
