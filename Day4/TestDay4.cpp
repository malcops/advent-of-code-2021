#include "Day4.hpp"
#include "gtest/gtest.h"

TEST(TestDay4, parse){
    auto input = parse_input("Day4/example.txt");
    auto draws = parseDraws(input);
    ASSERT_EQ(draws.at(0), 7);
    ASSERT_EQ(draws.at(1), 4);
    ASSERT_EQ(draws.at(11), 24);
    auto cards = parseCards(input);
    ASSERT_EQ(cards.size(), 3);
    ASSERT_EQ(cards.at(0).board[0][0], 22);
    ASSERT_EQ(cards.at(0).board[0][4], 0);
    ASSERT_EQ(cards.at(0).board[1][0], 8);
    ASSERT_EQ(cards.at(0).board[4][4], 19);
    ASSERT_EQ(cards.at(1).board[0][0], 3);
    ASSERT_EQ(cards.at(2).board[4][4], 7);
}

TEST(TestDay4, checkForWinner){
    auto input = parse_input("Day4/example.txt");
    Card c = { 0 };
    c.called[0][0] = 1;
    c.called[1][0] = 1;
    c.called[2][0] = 1;
    c.called[3][0] = 1;
    c.called[4][0] = 1;
    ASSERT_EQ(checkForWinner(&c), 1);
}

TEST(TestDay4, part1Example){
    auto input = parse_input("Day4/example.txt");
    ASSERT_EQ(part1(input), 4512);
}

TEST(TestDay4, part1){
    auto input = parse_input("Day4/input.txt");
    ASSERT_EQ(part1(input), 49860);
}

TEST(TestDay4, part2Example){
    auto input = parse_input("Day4/example.txt");
    ASSERT_EQ(part2(input), 1924);
}

TEST(TestDay4, part2){
    auto input = parse_input("Day4/input.txt");
    ASSERT_EQ(part2(input), 24628);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}
