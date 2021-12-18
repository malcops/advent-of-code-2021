#include "Day8.hpp"
#include "gtest/gtest.h"

TEST(TestDay8, part1example){
    ASSERT_EQ(part1("Day8/example.txt"), 26);
}

TEST(TestDay8, part1){
    ASSERT_EQ(part1("Day8/input.txt"), 303);
}

TEST(TestDay8, part2solveEntry){
    std::vector<std::string> signal = {"acedgfb", "cdfbe", "gcdfa", "fbcad", "dab", "cefabd", "cdfgeb", "eafb", "cagedb", "ab"};
    std::vector<std::string> output = {"cdfeb", "fcadb", "cdfeb", "cdbaf"};
    ASSERT_EQ(solveEntry(signal, output), 5353);

    signal = {"be", "cfbegad", "cbdgef", "fgaecd", "cgeb", "fdcge", "agebfd", "fecdb", "fabcd", "edb"};
    output = {"fdgacbe", "cefdb", "cefbgd", "gcbe"};
    ASSERT_EQ(solveEntry(signal, output), 8394);

    // signal = {"edbfga", "begcd", "cbg", "gc", "gcadebf", "fbgde", "acbgfd", "abcde", "gfcbed", "gfec"};
    // output = {"fdgacbe", "cefdb", "cefbgd", "gcbe"};
    // ASSERT_EQ(solveEntry(signal, output), 9781);
}

TEST(TestDay8, difference){

    std::set<char> four = {'a', 'b', 'e', 'f'};
    std::set<char> nine = {'a', 'b', 'c', 'd', 'e', 'f'};
    std::set<char> pot = {'b', 'c', 'd', 'e', 'f'};
    auto diff = difference(nine, pot);
    ASSERT_EQ(diff.size(), 1);

    std::set<char> one = {'a', 'b'};
    auto diff2 = difference(one, pot);
    ASSERT_EQ(diff2.size(), 1);

    std::set<char> eight = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    std::set<char> zero = {'a', 'b', 'c', 'd', 'e', 'g'};
    auto diff3 = difference(zero, eight);
    ASSERT_EQ(diff3.size(), 0);
}

TEST(TestDay8, part2example){
    ASSERT_EQ(part2("Day8/example.txt"), 61229);
}

TEST(TestDay8, part2){
    ASSERT_EQ(part2("Day8/input.txt"), 961734);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}
