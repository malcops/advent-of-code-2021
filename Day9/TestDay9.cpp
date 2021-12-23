#include "Day9.hpp"
#include "gtest/gtest.h"

TEST(TestDay9, part1example){
    auto in= parse_input("Day9/example.txt");
    ASSERT_EQ(part1(in), 15);
}

TEST(TestDay9, part1){
    auto in= parse_input("Day9/input.txt");
    ASSERT_EQ(part1(in), 518);
}

TEST(TestDay9, part2example2){
    // example 2 is first 15 rows of input
    // see column with 5/28.. mistake here somewhere
    auto in= parse_input("Day9/example2.txt");
    ASSERT_EQ(part2(in), 1134);
}

TEST(TestDay9, part2example){
    auto in= parse_input("Day9/example.txt");
    ASSERT_EQ(part2(in), 1134);
}

TEST(TestDay9, part2){
    auto in= parse_input("Day9/input.txt");
    ASSERT_EQ(part2(in), 0); // 4171200 too low
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}
