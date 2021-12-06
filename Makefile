CC=g++
GTEST_FLAGS=-lgtest -lpthread 

day1:
	$(CC) Day1/Day1.cpp Day1/TestDay1.cpp $(GTEST_FLAGS) -o run
day2:
	$(CC) Day2/Day2.cpp Day2/TestDay2.cpp $(GTEST_FLAGS) -o run
