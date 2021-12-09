#include "Common.hpp"

inputVector parse_input(std::string inputFile){

    std::ifstream inFile;
    inFile.open(inputFile.c_str());

    if(!inFile){
        std::cerr << "unable to open\n";
        exit(1);
    }

    std::string x;
    std::vector<std::string> input;
    while(inFile >> x){
        input.push_back(x);
    }

    return input;
}