#include "Day2.hpp"
#include "gtest/gtest.h"

TEST(TestDay2, example){
    auto input = parse_input("Day2/example.txt");
    auto position = part_one(input);
    ASSERT_EQ(std::get<0>(position) * std::get<1>(position), 150);
}

TEST(TestDay2, part1){
    auto input = parse_input("Day2/input.txt");
    auto position = part_one(input);
    ASSERT_EQ(std::get<0>(position) * std::get<1>(position), 1580000);
}

TEST(TestDay2, part2example){
    auto input = parse_input("Day2/example.txt");
    auto position = part_two(input);
    ASSERT_EQ(std::get<0>(position) * std::get<1>(position), 900);
}

TEST(TestDay2, part2){
    auto input = parse_input("Day2/input.txt");
    auto position = part_two(input);
    ASSERT_EQ(std::get<0>(position) * std::get<1>(position), 1251263225);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}
