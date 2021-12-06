#include "Day3.hpp"


report parse_input(std::string inputFile){

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

std::tuple<int, int> part_one(report diags){

    int wordLength = diags.at(0).length();
    unsigned counts[wordLength] = { 0 };

    for (auto it=diags.begin(); it!=diags.end(); it++){
        for (auto x=0; x < wordLength; x++){
            char s = (*it)[x];
            counts[x] += s - '0';
        }
    }

    int diagLength = diags.size();
    std::string gamma;
    std::string epsilon;
    for (auto x=0; x<wordLength; x++){
        if (counts[x] > diagLength/2){
            gamma += "1";
            epsilon += "0";
        } else{
            gamma += "0";
            epsilon += "1";
        }
    }

    return std::tuple<int, int>  {std::stoi(gamma, 0, 2), std::stoi(epsilon, 0, 2)};
}

int part2(report diags){

    int wordLength = diags.at(0).length();

    std::vector<int> nums;
    for(auto it=diags.begin(); it!=diags.end(); it++){
        nums.push_back(stoi(*it, 0, 2));
    }

    // calculate the oxygen generator rating
    std::vector<int> hasOne;
    std::vector<int> hasZero;
    std::vector<int> oxygenNums = nums;
    int bit = 1 << (wordLength-1);
    
    while(oxygenNums.size() != 1){
        for(auto it=oxygenNums.begin(); it!=oxygenNums.end(); it++){
            if(bit & *it){
                hasOne.push_back(*it);

            } else{
                hasZero.push_back(*it);
            }
        }
        oxygenNums = hasOne.size() >= hasZero.size() ? hasOne : hasZero;
        hasOne.clear();
        hasZero.clear();
        bit = bit >> 1;
    }
    // std::cout << "oxygen: " << oxygenNums.at(0) << std::endl;
    int oxygen = oxygenNums.at(0);


    // calculate the co2 rating
    hasOne.clear();
    hasZero.clear();
    bit = 1 << (wordLength-1);
    
    while(nums.size() != 1){
        for(auto it=nums.begin(); it!=nums.end(); it++){
            if(bit & *it){
                hasOne.push_back(*it);

            } else{
                hasZero.push_back(*it);
            }
        }
        nums = hasOne.size() < hasZero.size() ? hasOne : hasZero;
        hasOne.clear();
        hasZero.clear();
        bit = bit >> 1;
    }
    // std::cout << "co2: " << nums.at(0) << std::endl;
    int co2 = nums.at(0);
    return oxygen * co2;
}