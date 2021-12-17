#include "Day5.hpp"
#include "gtest/gtest.h"

TEST(TestDay5, initialize){
    auto input = parse_input("Day5/example.txt");
    auto lines = parse_lines(input);
    ASSERT_EQ(lines.size(), 10);
    ASSERT_EQ(lines.at(0).x1, 0);
    ASSERT_EQ(lines.at(0).y1, 9);
    ASSERT_EQ(lines.at(0).x2, 5);
    ASSERT_EQ(lines.at(0).y2, 9);
    ASSERT_EQ(lines.at(9).x1, 5);
    ASSERT_EQ(lines.at(9).y1, 5);
    ASSERT_EQ(lines.at(9).x2, 8);
    ASSERT_EQ(lines.at(9).y2, 2);
}

TEST(TestDay5, isLineStraight){
    Line l1 = {1, 2, 3, 4};
    ASSERT_EQ(isLineStraight(&l1), 0);
    Line l2 = {0, 9, 2, 9};
    ASSERT_EQ(isLineStraight(&l2), 1);
}


TEST(TestDay5, part1example){
    auto input = parse_input("Day5/example.txt");
    auto lines = parse_lines(input);
    ASSERT_EQ(part1(lines), 5);
}

TEST(TestDay5, part1){
    auto input = parse_input("Day5/input.txt");
    auto lines = parse_lines(input);
    ASSERT_EQ(part1(lines), 5774);
}

TEST(TestDay5, part2example){
    auto input = parse_input("Day5/example.txt");
    auto lines = parse_lines(input);
    ASSERT_EQ(part2(lines), 12);
}

TEST(TestDay5, part2){
    auto input = parse_input("Day5/input.txt");
    auto lines = parse_lines(input);
    ASSERT_EQ(part2(lines), 18423);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}
