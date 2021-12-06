#include "Day2.hpp"

std::tuple<int, int> part_one(instructions input){

    int position = 0;
    int depth = 0;
    for (auto it=input.begin(); it != input.end(); it++){
        if(std::get<0>(*it) == "forward"){
            position += std::get<1>(*it);
        }
        else if(std::get<0>(*it) == "up"){
            depth -= std::get<1>(*it);
        }
        else if(std::get<0>(*it) == "down"){
            depth += std::get<1>(*it);
        }
    }

    return std::tuple<int, int> {position, depth};
}

std::tuple<int, int> part_two(instructions input){

    int aim = 0;
    int position = 0;
    int depth = 0;

    for (auto it=input.begin(); it != input.end(); it++){
        if(std::get<0>(*it) == "forward"){
            position += std::get<1>(*it);
            depth += aim *  std::get<1>(*it);
        }
        else if(std::get<0>(*it) == "up"){
            aim -= std::get<1>(*it);
        }
        else if(std::get<0>(*it) == "down"){
            aim += std::get<1>(*it);
        }
    }

    return std::tuple<int, int> {position, depth};
}

instructions parse_input(std::string inputFile){

    std::ifstream inFile;
    inFile.open(inputFile.c_str());

    if(!inFile){
        std::cerr << "unable to open\n";
        exit(1);
    }

    instructions input;
    std::string x;
    std::string y;
    instruction z;
    while(inFile >> x >> y){
        z = {x, std::stoi(y)};
        input.push_back(z);
    }

    // for (auto it=input.begin(); it != input.end(); it++){
    //     std::cout << std::get<0>(*it) << std::get<1>(*it) << std::endl;
    // }

    return input;
}
