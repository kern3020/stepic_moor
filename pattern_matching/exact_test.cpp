#include "gtest/gtest.h"
#include "exact.h"

TEST(ExactTest, SimpleCommonCase) {
  list<int> exp;
  exp.push_front(9);
  EXPECT_EQ(exp, exact_match("BARB", "FOOBUBBABBARBIZBAZ"));
}
