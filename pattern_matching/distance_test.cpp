#include "gtest/gtest.h"
#include "distance.h"

#include <string>

TEST(DistanceTest, Hamming) {
  string s1("ACGTTCTC");
  string s2("ACATTATC");
  Hamming h;

  EXPECT_EQ(2, h.distance(s1,s2));
}

TEST(DistanceTest, LevenstheinReference) {
  LevenstheinReference l;
  string s1("kitten");
  string s2("sitting");
  EXPECT_EQ(3, l.distance(s1,s2));
 
  string cook ("cook"); 
  string book("book");
  EXPECT_EQ(1, l.distance(cook, book));
  string books("books");
  EXPECT_EQ(2, l.distance(cook, books));

  string water("water");
  string what("what");
  EXPECT_EQ(3, l.distance(water, what));
}

TEST(DistanceTest, SeqAlignDP) { 
  string s1("writers");
  string s2("vintner"); 
  SeqAlignDP dp(s2, s1);
  int d = dp.distance();
  dp.print();
  EXPECT_EQ(5, d);
}
