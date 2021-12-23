#include "Day10.hpp"
#include "gtest/gtest.h"

TEST(TestDay10, part1example){
    auto input = parse_input("Day10/example.txt");
    ASSERT_EQ(part1(input), 26397);
}

TEST(TestDay10, part1){
    auto input = parse_input("Day10/input.txt");
    ASSERT_EQ(part1(input), 166191);
}

TEST(TestDay10, part2example){
    auto input = parse_input("Day10/example.txt");
    ASSERT_EQ(part2(input), 288957);
}

TEST(TestDay10, part2){
    auto input = parse_input("Day10/input.txt");
    ASSERT_EQ(part2(input), 1152088313);
}

TEST(TestDay10, isLineCorruptedFalse){

    auto l1 = { '<','(','[','{', '}',']',')','>' };
    ASSERT_EQ(isLineCorrupted(l1), 0);
}

TEST(TestDay10, isLineCorruptedTrue){

    auto l1 = {'(', ']'};
    ASSERT_EQ(isLineCorrupted(l1), 57);

    auto l2 = {'{','(',')','(',')','(',')','>'};
    ASSERT_EQ(isLineCorrupted(l2), 25137);

    std::string ls3 = "<([]){()}[{}])";
    std::vector<char> l3;
    for(auto x=0; x<ls3.size(); x++){
        l3.push_back(ls3.at(x));
    }
    ASSERT_EQ(isLineCorrupted(l3), 3);

    std::string ls4 = "{([(<{}[<>[]}>{[]{[(<()>";
    std::vector<char> l4;
    for(auto x=0; x<ls4.size(); x++){
        l4.push_back(ls4.at(x));
    }
    ASSERT_EQ(isLineCorrupted(l4), 1197);

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}
