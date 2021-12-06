#include <fstream>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

typedef std::vector< std::tuple<std::string, int> > instructions;
typedef std::tuple<std::string, int> instruction;

instructions parse_input(std::string inputFile);
std::tuple<int, int> part_two(instructions input);
std::tuple<int, int> part_one(instructions input);