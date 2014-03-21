#include "gtest/gtest.h"
#include "distance.h"

#include <string>

TEST(DistanceTest, Hamming) {
  string s1("ACGTTCTC");
  string s2("ACATTATC");
  Hamming h(s1, s2);

  EXPECT_EQ(2, h.distance());
}

TEST(DistanceTest, LevenstheinReference) {
  string s1("kitten");
  string s2("sitting");
  LevenstheinReference l(s1,s2);
  EXPECT_EQ(3, l.distance());
 
  l.setSeq1("cook"); 
  l.setSeq2("book");
  EXPECT_EQ(1, l.distance());
  l.setSeq2("books");
  EXPECT_EQ(2, l.distance());

  l.setSeq1("water");
  l.setSeq2("what");
  EXPECT_EQ(3, l.distance());
}

TEST(DistanceTest, SeqAlignDP) { 
  string s1("writers");
  string s2("vintner"); 
  SeqAlignDP dp(s2, s1);
  int d = dp.distance();
  dp.print();
  EXPECT_EQ(5, d);
}
