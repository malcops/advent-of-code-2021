#include "Day1.hpp"
#include "gtest/gtest.h"


TEST(Day1, Part1){
    auto data = parse_input();
    ASSERT_EQ(part_one(data), 1791);
}

TEST(Day1, Part2){
    auto data = parse_vector();
    ASSERT_EQ(part_two(data), 1822);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}
