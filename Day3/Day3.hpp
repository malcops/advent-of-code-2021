#include <fstream>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

typedef std::vector<std::string> report;
report parse_input(std::string inputFile);
std::tuple<int, int> part_one(report diags);
int part2(report diags);