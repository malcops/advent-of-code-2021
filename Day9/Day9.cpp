#include "Day9.hpp"

void printGrid(int** grid, int xmax, int ymax){
    for (int i = 0; i < ymax; i++) {
        for (int j = 0; j < xmax; j++) {
            std::cout << grid[j][i] << " ";
        }
        std::cout << std::endl;
    }
}

int part1(){

    auto input = parse_input("Day9/example.txt");

    int xmax = input.at(0).length();
    int ymax = input.size();

    int** grid = new int*[xmax];
    for (int i = 0; i < xmax; i++) {
        grid[i] = new int[ymax];
    }

    int yidx = 0;
    int xidx = 0;
    for(auto y=input.begin(); y!=input.end(); y++){
        for(auto x=y->begin(); x!=y->end(); x++){
            int num = (*x) - '0';
            grid[xidx][yidx] = num;
            std::cout << " " << *x;
            xidx++;
        }
        std::cout << std::endl;
        xidx = 0;
        yidx++;
    }

    printGrid(grid, xmax, ymax);


    return 0;
}
