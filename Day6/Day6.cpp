#include "Day6.hpp"

void simulateDay(std::vector<unsigned long long int>* counts){

    // for (auto it=counts->begin(); it!=counts->end(); ++it)
    // std::cout << ' ' << *it;
    // std::cout << '\n';
    unsigned long long int respawn = counts->front();
    counts->erase(counts->begin());
    counts->push_back(respawn);
    unsigned long long int* pos = counts->data() + 6;
    *pos = *pos + respawn;
}

void part2(std::vector<int>* fish, int days){

    unsigned long long int zeroes = std::count(fish->begin(), fish->end(), 0);
    unsigned long long int ones = std::count(fish->begin(), fish->end(), 1);
    unsigned long long int twos = std::count(fish->begin(), fish->end(), 2);
    unsigned long long int threes = std::count(fish->begin(), fish->end(), 3);
    unsigned long long int fours = std::count(fish->begin(), fish->end(), 4);
    unsigned long long int fives = std::count(fish->begin(), fish->end(), 5);

    std::vector<unsigned long long int> counts = {zeroes, ones, twos, threes, fours, fives, 0, 0, 0};
    for(auto day=0; day<days; day++){
        simulateDay(&counts);
    }

    unsigned long long int totalFish = 0;
    for(auto x=0; x<counts.size(); x++){
        totalFish += counts.at(x);
    }

    // for(auto x=0; x< counts.size(); x++){
    //     std::cout << counts.at(x) << " ";
    // }
    // std::cout << std::endl;

    std::string total = std::to_string(totalFish);
    std::cout << total << std::endl;
}

int part1(std::vector<int>* fish, int days){
    for(auto day=0; day<days;day++){
        simulateDay(fish);
    }
    return fish->size();
}

// Each day, a 0 becomes a 6 and adds a new 8 to the end of the list, while each other number decreases by 1 if it was present at the start of the day.
void simulateDay(std::vector<int>* fish){
    int zeroes = std::count(fish->begin(), fish->end(), 0);
    std::transform(fish->begin(), fish->end(), fish->begin(), [](int x){if(x==0){return 6;}else{return x-1; }});
    for(auto x=0; x<zeroes; x++){
        fish->push_back(8);
    }
}

std::vector<int> parseLanternfish(inputVector input){
    std::vector<int> lanternfish;
    std::stringstream ss(input.at(0));
    while( ss.good() )
    {
        std::string substr;
        getline( ss, substr, ',' );
        lanternfish.push_back( stoi(substr) );
    }
    return lanternfish;
}
