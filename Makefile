CC=g++
GTEST_FLAGS=-lgtest -lpthread
COMMON_INC=.
COMMON_SRC=Common.cpp

day1:
	$(CC) Day1/Day1.cpp Day1/TestDay1.cpp $(GTEST_FLAGS) -o run
day2:
	$(CC) Day2/Day2.cpp Day2/TestDay2.cpp $(GTEST_FLAGS) -o run
day3:
	$(CC) Day3/Day3.cpp Day3/TestDay3.cpp $(GTEST_FLAGS) -o run
day4:
	$(CC) Day4/Day4.cpp Day4/TestDay4.cpp $(GTEST_FLAGS) -o run
day5:
	$(CC) Day5/Day5.cpp Day5/TestDay5.cpp $(COMMON_SRC) -I$(COMMON_INC) $(GTEST_FLAGS) -o run
day6:
	$(CC) Day6/Day6.cpp Day6/TestDay6.cpp $(COMMON_SRC) -I$(COMMON_INC) $(GTEST_FLAGS) -o run
