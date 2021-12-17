#include "Day5.hpp"

bool isLineStraight(Line* l){
    if ((l->x1 == l->x2) || (l->y1 == l->y2)){
        return 1;
    } else{
        return 0;
    }
}

void printGrid(int** grid, int xmax, int ymax){
    for (int i = 0; i < ymax; i++) {
        for (int j = 0; j < xmax; j++) {
            std::cout << grid[j][i] << " ";
        }
        std::cout << std::endl;
    }
}

void drawLine(Line* line, int** grid){

    // std::cout << line->x1 << "," << line->y1  << "->" << line->x2 << "," << line->y2 << std::endl;
    int p_start;
    int p_end;
    if(line->x1 == line->x2){
        p_start = (line->y1 > line->y2)? line->y2 : line->y1;
        p_end = (line->y1 > line->y2)? line->y1 : line ->y2;
        for (auto p=p_start; p<=p_end; p++){
            grid[line->x1][p] += 1;
        }
    } else if(line->y1 == line->y2){
        p_start = (line->x1 > line->x2)? line->x2 : line->x1;
        p_end = (line->x1 > line->x2)? line->x1 : line ->x2;
        for (auto p=p_start; p<=p_end; p++){
            grid[p][line->y1] += 1;
        }
    } else{
        // x1, y1 = point1
        int point1IsTop = 0;
        int point1IsLeft = 0;
        point1IsTop = (line->y2 > line->y1)? 1 : 0;
        point1IsLeft = (line->x2 > line->x1)? 1 : 0;
        // 4 scenarios
        if(point1IsTop && point1IsLeft){
            // start at top left and work down and right
            int y = line->y1;
            for(auto x=line->x1; x<=line->x2; x++,y++){
                grid[x][y] += 1;
            }
        } else if (point1IsTop && !point1IsLeft){
            int y = line->y1;
            for(auto x=line->x1; x>=line->x2; x--,y++){
                grid[x][y] += 1;
            }
        } else if(!point1IsTop && point1IsLeft){
            int y=line->y1;
            for(auto x=line->x1; x<=line->x2; x++,y--){
                grid[x][y] += 1;
            }
        } else{
            // !point1IsTop && !point1IsLeft
            int y = line->y1;
            for(auto x=line->x1; x>=line->x2; x--,y--){
                grid[x][y] += 1;
            }
        }
   }
   return;
}

int part1(Lines ll){
    Lines straightLines;
    unsigned xmax = 0;
    unsigned ymax = 0;
    for (auto line=ll.begin(); line!=ll.end(); line++){
        // std::cout << line->x1 << "," << line->y1  << "->" << line->x2 << "," << line->y2 << std::endl;
        xmax = (line->x1 > xmax)? line->x1 : xmax;
        xmax = (line->x2 > xmax)? line->x1 : xmax;
        ymax = (line->y1 > ymax)? line->y1 : ymax;
        ymax = (line->y2 > ymax)? line->y2 : ymax;
        if (isLineStraight(&(*line))){
            straightLines.push_back(*line);
        }
    }
    xmax++;
    ymax++;

    int** grid = new int*[xmax];
    for (int i = 0; i < xmax; i++) {
        grid[i] = new int[ymax];
    }
    for (int i = 0; i < xmax; i++) {
        for (int j = 0; j < ymax; j++) {
            grid[i][j] = 0;
        }
    }

    // printGrid(grid, xmax, ymax);

    for(auto line=straightLines.begin(); line!=straightLines.end(); line++){
        drawLine(&(*line), grid);
    }

    // std::cout << std::endl;
    // printGrid(grid, xmax, ymax);

    int overlapCount = 0;
    for (int i = 0; i < ymax; i++) {
        for (int j = 0; j < xmax; j++) {
            if(grid[j][i] > 1){
                overlapCount++;
            }
        }
    }

    for(int i=0;i<ymax;i++){
        delete [] grid[i];
    }
    delete [] grid;
    return overlapCount;
}

int part2(Lines ll){
    unsigned xmax = 0;
    unsigned ymax = 0;
    for (auto line=ll.begin(); line!=ll.end(); line++){
        // std::cout << line->x1 << "," << line->y1  << "->" << line->x2 << "," << line->y2 << std::endl;
        xmax = (line->x1 > xmax)? line->x1 : xmax;
        xmax = (line->x2 > xmax)? line->x1 : xmax;
        ymax = (line->y1 > ymax)? line->y1 : ymax;
        ymax = (line->y2 > ymax)? line->y2 : ymax;
    }
    xmax++;
    ymax++;

    int** grid = new int*[xmax];
    for (int i = 0; i < xmax; i++) {
        grid[i] = new int[ymax];
    }
    for (int i = 0; i < xmax; i++) {
        for (int j = 0; j < ymax; j++) {
            grid[i][j] = 0;
        }
    }

    // printGrid(grid, xmax, ymax);

    for(auto line=ll.begin(); line!=ll.end(); line++){
        drawLine(&(*line), grid);
    }

    // std::cout << std::endl;
    // printGrid(grid, xmax, ymax);

    int overlapCount = 0;
    for (int i = 0; i < ymax; i++) {
        for (int j = 0; j < xmax; j++) {
            if(grid[j][i] > 1){
                overlapCount++;
            }
        }
    }

    for(int i=0;i<ymax;i++){
        delete [] grid[i];
    }
    delete [] grid;
    return overlapCount;
}

Lines parse_lines(inputVector input){

    Lines lines;
    int write1 = 1;
    Line newLine = { 0 };
    for(auto it=input.begin(); it!=input.end(); it++){
        if(write1 == 1){
            newLine = { 0 };
            std::stringstream ss(*it);
            std::string substr;
            getline(ss, substr, ',' );
            newLine.x1 = stoi(substr);
            substr="";
            getline(ss, substr, '\n' );
            newLine.y1 = stoi(substr);
            write1 = 0;
        } else if (*it == "->"){
            ;;
        } else{
            std::stringstream ss(*it);
            std::string substr;
            getline(ss, substr, ',' );
            newLine.x2 = stoi(substr);
            substr="";
            getline(ss, substr, '\n' );
            newLine.y2 = stoi(substr);
            write1 = 1;
            lines.push_back(newLine);
        }
    }
    return lines;
}