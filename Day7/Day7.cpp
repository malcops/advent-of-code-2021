#include "Day7.hpp"

int part1(std::vector<int> input){

    double total = accumulate(input.begin(), input.end(), 0.0);
    double mean = total/input.size();

    size_t n = input.size() / 2;
    std::nth_element(input.begin(), input.begin()+n, input.end());

    int fuel = 0;
    int median = input[n];
    for(auto it=input.begin(); it!=input.end(); it++){
        fuel += abs(*it - median);
    }
    return fuel;
}

int part2(std::vector<int> input){

    double total = accumulate(input.begin(), input.end(), 0.0);
    double mean = total/input.size();
    int roundedMean = std::round(mean);

    // https://oeis.org/
    // triangular numbers
    // n*(n+1)/2
    int minimumFuel=2147483647;
    // try immediate neighbors as well
    for(auto mean=roundedMean-2; mean<roundedMean+2; mean++){
        int fuel = 0;
        int diff = 0;
        for(auto it=input.begin(); it!=input.end(); it++){
            diff = abs(*it - mean);
            fuel += diff*(diff+1)/2;
        }
        if(fuel < minimumFuel){
            minimumFuel = fuel;
        }
    }
    return minimumFuel;
}