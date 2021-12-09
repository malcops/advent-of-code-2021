#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <tuple>
#include <vector>

typedef std::vector<std::string> inputVector;
#define BOARD_SIZE 5

struct Card {
    int board[BOARD_SIZE][BOARD_SIZE];
    int called[BOARD_SIZE][BOARD_SIZE];
};

inputVector parse_input(std::string inputFile);
std::vector<int> parseDraws(inputVector);
std::vector<Card> parseCards(inputVector);

int checkForWinner(Card*);
int part1(inputVector);
int part2(inputVector);