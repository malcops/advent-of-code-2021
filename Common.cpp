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

std::vector<int> parseNumbers(std::string inputFile){

    inputVector input = parse_input(inputFile);
    std::vector<int> numbers;
    std::stringstream ss(input.at(0));
    while( ss.good() )
    {
        std::string substr;
        getline( ss, substr, ',' );
        numbers.push_back( stoi(substr) );
    }
    return numbers;
}