#include "gtest/gtest.h"
#include "kmer_node.h"

TEST(KmerNodeText, Children) {
  KmerNode n1("ACGT", 43);
  KmerNode n2("TGCA", 26);
  int d = KmerNode::hamming(n1.getName(), n2.getName());
  n1.insertChild(d, n2);
  KmerNode *n2r = n1.getChild(d); 
  EXPECT_EQ(n2r->getName(), n2.getName());
}

TEST(KmerNodeText, Distances) {
  KmerNode n1("ACGTTCTC", 23);
  KmerNode n2("ACATTATC", 441);
  EXPECT_EQ(2, KmerNode::hamming(n1.getName(), n2.getName()));
}

TEST(KmerNodeText, SimpleEquality) {
  KmerNode n1("ACGTTCTC", 23);
  KmerNode n2("ACGTTCTC", 441);
  KmerNode n3("TTCTCACAGAG", 352);
  EXPECT_EQ(n1,n2);
  EXPECT_NE(n1,n3);
}
