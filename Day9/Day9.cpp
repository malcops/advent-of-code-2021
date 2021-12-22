#include "Day9.hpp"

#define PAD_NUMBER 9
#define PAD_AMOUNT 1

void printGrid(int** grid, int xmax, int ymax){
    for (int i = 0; i < ymax; i++) {
        for (int j = 0; j < xmax; j++) {
            std::cout << grid[j][i] << " ";
        }
        std::cout << std::endl;
    }
}

int** createGrid(inputVector in){

    int xmax = in.at(0).length() + PAD_AMOUNT*2;
    int ymax = in.size() + PAD_AMOUNT*2;

    int** grid = new int*[xmax];
    for (int i = 0; i < xmax; i++) {
        grid[i] = new int[ymax];
    }
    for (int i = 0; i < xmax; i++) {
        for (int j = 0; j < ymax; j++) {
            grid[i][j] = PAD_NUMBER;
        }
    }

    int yidx = 1;
    int xidx = 1;
    for(auto y=in.begin(); y!=in.end(); y++){
        for(auto x=y->begin(); x!=y->end(); x++){
            int num = (*x) - '0';
            grid[xidx][yidx] = num;
            // std::cout << " " << *x;
            xidx++;
        }
        // std::cout << std::endl;
        xidx = 1;
        yidx++;
    }
    return grid;
}

int part1(inputVector input){

    int xmax = input.at(0).length() + PAD_AMOUNT*2;
    int ymax = input.size() + PAD_AMOUNT*2;
    auto grid = createGrid(input);
    // printGrid(grid, xmax, ymax);

    int above;
    int below;
    int left;
    int right;
    int x;
    std::vector<int> minima;
    for (int i = 1; i < xmax-1; i++) {
        for (int j = 1; j < ymax-1; j++) {
            above = grid[i][j-1];
            below = grid[i][j+1];
            left  = grid[i-1][j];
            right = grid[i+1][j];
            x = grid[i][j];
            if(x < above && x < below && x < left && x < right){
                // std::cout << i << " " << j << " " << x << std::endl;
                minima.push_back(x);
            }
        }
    }

    int totalRisk = 0;
    for(auto m=0; m<minima.size(); m++){
        totalRisk += minima.at(m) + 1;
    }
    return totalRisk;
}

int part2(inputVector input){

    int xmax = input.at(0).length() + PAD_AMOUNT*2;
    int ymax = input.size() + PAD_AMOUNT*2;
    auto grid = createGrid(input);

    // convert to binary grid
    for(int y=0; y<ymax; y++){
        for(int x=0; x<xmax; x++){
            grid[x][y] = grid[x][y] == 9? 0 : 1;
        }
    }

    printGrid(grid, xmax, ymax);

    // https://en.wikipedia.org/wiki/Connected-component_labeling

    // create a 2nd grid for labels
    int** labels = new int*[xmax];
    for (int i = 0; i < xmax; i++) {
        labels[i] = new int[ymax];
    }
    for (int i = 0; i < xmax; i++) {
        for (int j = 0; j < ymax; j++) {
            labels[i][j] = 0;
        }
    }

    int east;
    int west;
    int north;
    int south;
    int pix;
    int label = 0;
    for (int i = 1; i < xmax-1; i++) {
        for (int j = 1; j < ymax-1; j++) {
            pix  = grid[i][j];
            if(pix){
                east = grid[i+1][j];
                west = grid[i-1][j];
                north = grid[i][j-1];
                south = grid[i][j+1];
                if(west == 0 && north == 0){
                    label++;
                    labels[i][j] = label;
                } else if(west != 0 && north == 0){
                    labels[i][j] = label;
                } else if(west == 0 && north != 0){
                    labels[i][j] = label;
                } else {
                    labels[i][j] = label;
                }
            }
        }
    }

    std::cout << std::endl;
    printGrid(labels, xmax, ymax);

    return 0;
}