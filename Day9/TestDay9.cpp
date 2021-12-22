#include "Day9.hpp"
#include "gtest/gtest.h"

TEST(TestDay9, part1example){
    auto in= parse_input("Day9/example.txt");
    ASSERT_EQ(part1(in), 15);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}
