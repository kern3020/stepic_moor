#include "gtest/gtest.h"
#include "kmer_node.h"

#include <memory>

TEST(KmerNodeTest, Children) {
  auto n1 = make_shared<KmerNode>("ACGT", 43);
  auto n2 = make_shared<KmerNode>("TGCA", 26);
  int d = n1->hamming(n2->getName());
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

TEST(KmerNodeTest, LevenstheinDistance) {
  KmerNode n1("kitten", 33);
  string smitten("sitting");
  EXPECT_EQ(3, n1.levensthein(smitten));
 
  KmerNode n2 ("cook",2); 
  string book("book");
  EXPECT_EQ(1, n2.levensthein(book));
  string books("books");
  EXPECT_EQ(2, n2.levensthein(books));

  KmerNode n3("water",6);
  string what("what");
  EXPECT_EQ(3, n3.levensthein(what));
}

TEST(KmerNodeTest, HammingDistance) {
  KmerNode n1("ACGTTCTC", 432);
  string seq("ACATTATC");
  EXPECT_EQ(2, n1.hamming(seq));
}
