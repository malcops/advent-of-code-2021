#include "Day1.hpp"

unsigned part_one(std::list<int> numbers){
    
    int increases = -1;
    int prev = -1;
    for(auto it=numbers.begin(); it!= numbers.end(); it++){
        if (*it > prev){
            increases++;
        }
        prev=*it;
    }
    return (unsigned) increases;
}

unsigned part_two(std::vector<int> numbers){
    
    int increases = -1;
    unsigned prevSum = 0;
    for (auto it=numbers.begin(); it!=(numbers.end()-2); it++){
        unsigned sum = *(it) + *(it+1) + *(it+2);
        if (sum > prevSum){
            increases++;
        }
        prevSum = sum;
    }
    return increases;
}

std::vector<int> parse_vector(){

    std::ifstream inFile;
    inFile.open("Day1/input1.txt");

    if(!inFile){
        std::cerr << "unable to open\n";
        exit(1);
    }

    std::vector<int> input;
    int x;
    while(inFile >> x){
        input.push_back(x);
    }

    return input;
}

std::list<int> parse_input(){

    std::ifstream inFile;
    inFile.open("Day1/input1.txt");

    if(!inFile){
        std::cerr << "unable to open\n";
        exit(1);
    }

    std::list<int> input;
    int x;
    while(inFile >> x){
        input.push_back(x);
    }

    return input;
}