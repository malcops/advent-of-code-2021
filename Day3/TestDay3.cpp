#include "Day3.hpp"
#include "gtest/gtest.h"

TEST(TestDay3, example){
    auto input = parse_input("Day3/example.txt");
    auto rates = part_one(input);
    ASSERT_EQ(std::get<0>(rates), 22);
    ASSERT_EQ(std::get<1>(rates), 9);
    ASSERT_EQ(std::get<0>(rates) * std::get<1>(rates), 198);
}

TEST(TestDay3, part1){
    auto input = parse_input("Day3/input.txt");
    auto rates = part_one(input);
    ASSERT_EQ(std::get<0>(rates) * std::get<1>(rates), 4006064);
}


TEST(TestDay3, part2example){
    auto input = parse_input("Day3/example.txt");
    ASSERT_EQ(part2(input), 230);
}

TEST(TestDay3, part2){
    auto input = parse_input("Day3/input.txt");
    ASSERT_EQ(part2(input), 5941884);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}
