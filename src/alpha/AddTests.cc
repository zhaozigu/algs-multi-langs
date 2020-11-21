#include "gtest/gtest.h"

#include "myadd.hpp"

TEST(testAdd, sampleAdd)
{
  EXPECT_EQ(15, add(5, 10));
}