#include "Day7.hpp"
#include "gtest/gtest.h"

TEST(TestDay7, part1example){
    auto input = parseNumbers("Day7/example.txt");
    ASSERT_EQ(part1(input), 37);
}

TEST(TestDay7, part1){
    auto input = parseNumbers("Day7/input.txt");
    ASSERT_EQ(part1(input), 336701);
}

TEST(TestDay7, part2example){
    auto input = parseNumbers("Day7/example.txt");
    ASSERT_EQ(part2(input), 168);
}

TEST(TestDay7, part2){
    auto input = parseNumbers("Day7/input.txt");
    ASSERT_EQ(part2(input), 95167302);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}
