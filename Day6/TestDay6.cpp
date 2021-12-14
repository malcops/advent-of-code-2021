#include "Day6.hpp"
#include "gtest/gtest.h"

// TEST(TestDay6, part1example18){
    // inputVector input = parse_input("Day6/example.txt");
    // auto fish = parseLanternfish(input);
    // ASSERT_EQ(part1(&fish, 18), 26);
// }
//
// TEST(TestDay6, part1example80){
    // inputVector input = parse_input("Day6/example.txt");
    // auto fish = parseLanternfish(input);
    // ASSERT_EQ(part1(&fish, 80), 5934);
// }
//
// TEST(TestDay6, part1){
    // inputVector input = parse_input("Day6/input.txt");
    // auto fish = parseLanternfish(input);
    // ASSERT_EQ(part1(&fish, 80), 362346);
// }

TEST(TestDay6, part2example18){
    inputVector input = parse_input("Day6/example.txt");
    auto fish = parseLanternfish(input);
    part2(&fish, 18);
    // ASSERT_EQ(part2(&fish, 18), 26);
}

TEST(TestDay6, part2example80){
    inputVector input = parse_input("Day6/example.txt");
    auto fish = parseLanternfish(input);
    part2(&fish, 80);
    // ASSERT_EQ(part2(&fish, 80), 5934);
}

TEST(TestDay6, part2example256){
    inputVector input = parse_input("Day6/example.txt");
    auto fish = parseLanternfish(input);
    part2(&fish, 256);
    // ASSERT_STREQ(part2(&fish, 256).c_str(), "26984457539");
}

TEST(TestDay6, part2){
    inputVector input = parse_input("Day6/input.txt");
    auto fish = parseLanternfish(input);
    part2(&fish, 256);
    //1639643057051 is correct answer
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}
