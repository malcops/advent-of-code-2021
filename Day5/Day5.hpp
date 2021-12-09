#include "Common.hpp"

struct Line{
    int x1;
    int y1;
    int x2;
    int y2;
};

typedef std::vector<Line> Lines;
Lines parse_lines(inputVector input);
bool isLineStraight(Line* l);
int part1(Lines);
int part2(Lines);