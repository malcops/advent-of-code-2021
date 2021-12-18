#include "Day8.hpp"


void printWord(std::set<char> w){
    for(auto it=w.begin(); it!=w.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

std::string recreateString(std::set<char> w){
    std::string s;
    for(auto it=w.begin(); it!=w.end(); it++){
        s+= *it;
    }
    return s;
}

std::set<char> difference(std::set<char> setA, std::set<char> setB){
    std::set<char> diff;
    for(auto it=setA.begin(); it!=setA.end(); it++){
        if(setB.count(*it)){
            ;;
        } else{
            diff.insert(*it);
        }
    }
    return diff;
}


int solveEntry(std::vector<std::string> signal, std::vector<std::string> output){

    // length 5 = 2, 3, 5
    // length 6 = 6, 9, 0

    std::map<std::string, std::set<char> > deduced;
    std::vector<std::set<char> > length5;
    std::vector<std::set<char> > length6;

    for(auto it=signal.begin(); it!=signal.end(); it++){
        std::sort(it->begin(), it->end());
        int length = (*it).length();
        if(length == 2) {
            std::set<char> w;
            for(auto x=it->begin(); x!=it->end(); x++){
                w.insert(*x);
            }
            deduced["1"] = w;
        } else if (length == 3){
            std::set<char> w;
            for(auto x=it->begin(); x!=it->end(); x++){
                w.insert(*x);
            }
            deduced["7"] = w;
        } else if (length == 4){
            std::set<char> w;
            for(auto x=it->begin(); x!=it->end(); x++){
                w.insert(*x);
            }
            deduced["4"] = w;
        } else if (length == 7){
            std::set<char> w;
            for(auto x=it->begin(); x!=it->end(); x++){
                w.insert(*x);
            }
            deduced["8"] = w;
        } else if (length == 5){
            std::set<char> w;
            for(auto x=it->begin(); x!=it->end(); x++){
                w.insert(*x);
            }
            length5.push_back(w);
        } else if (length == 6){
            std::set<char> w;
            for(auto x=it->begin(); x!=it->end(); x++){
                w.insert(*x);
            }
            length6.push_back(w);
        }
    }

    // 9 is member of length6 that shares all 4 segments with "4"
    // 0 shares the two line segements with 1
    // 6 is the other item in length6 list
    for(auto it=length6.begin(); it!=length6.end(); it++){
        auto diff = difference(deduced["4"], *it);
        auto diff2 = difference(deduced["1"], *it);
        if(diff.size() == 0){
            deduced["9"] = *it;
        }
        else if (diff.size() == 1 && diff2.size() == 0){
            deduced["0"] = *it;
        } else {
            deduced["6"] = *it;
        }
    }

    for(auto it=length5.begin(); it!=length5.end(); it++){
        auto diff1 = difference(deduced["9"], *it);
        auto diff2 = difference(deduced["1"], *it);
        if(diff1.size() == 1 && diff2.size() == 1){
            deduced["5"] = *it;
        } else if(diff1.size() == 1 && diff2.size() == 0){
            deduced["3"] = *it;
        } else{
            deduced["2"] = *it;
        }
    }

    std::map<std::string, std::string> myMap;
    for(auto x=0; x<10; x++){
        // std::cout << x  << ": ";
        // printWord(deduced[std::to_string(x)]);
        std::string s = recreateString(deduced[std::to_string(x)]);
        myMap[s] = std::to_string(x);
    }

    std::string ans;
    for(auto it=output.begin(); it!=output.end(); it++){
        std::sort(it->begin(), it->end());
        ans += myMap[*it];
    }
    return stoi(ans);
}

int part2(std::string s){

    std::ifstream inFile;
    inFile.open(s.c_str());

    if(!inFile){
        std::cerr << "unable to open\n";
        exit(1);
    }

    std::string x;
    std::vector<std::vector<std::string> > signalList;
    std::vector<std::vector<std::string> > outputList;
    std::string delimiter = "|";
    std::string signals;
    std::string outputs;
    while(getline(inFile, x)){
        signals = x.substr(0, x.find(delimiter));
        outputs = x.substr(x.find(delimiter)+2, x.npos);

        std::vector<std::string> tmpVector;
        std::stringstream ss(signals);
        while(ss >> x){
            tmpVector.push_back(x);
        }
        signalList.push_back(tmpVector);
        tmpVector.clear();

        std::stringstream ss2(outputs);
        while(ss2 >> x){
            tmpVector.push_back(x);
        }
        outputList.push_back(tmpVector);
        tmpVector.clear();
    }

    int ans = 0;
    for(auto x=0; x<outputList.size(); x++){
        ans += solveEntry(signalList.at(x), outputList.at(x));
    }
    return ans;
}

int part1(std::string s){

    std::ifstream inFile;
    inFile.open(s.c_str());

    if(!inFile){
        std::cerr << "unable to open\n";
        exit(1);
    }

    std::string x;
    std::vector<std::vector<std::string> > signalList;
    std::vector<std::vector<std::string> > outputList;
    std::string delimiter = "|";
    std::string signals;
    std::string outputs;
    while(getline(inFile, x)){
        signals = x.substr(0, x.find(delimiter));
        outputs = x.substr(x.find(delimiter)+2, x.npos);

        std::vector<std::string> tmpVector;
        std::stringstream ss(signals);
        while(ss >> x){
            tmpVector.push_back(x);
        }
        signalList.push_back(tmpVector);
        tmpVector.clear();

        std::stringstream ss2(outputs);
        while(ss2 >> x){
            tmpVector.push_back(x);
        }
        outputList.push_back(tmpVector);
        tmpVector.clear();
    }

    int count = 0;
    for(auto it=outputList.begin(); it!=outputList.end(); it++){
        for(auto x=(*it).begin(); x!=(*it).end(); x++){
            int size = (*x).length();
            // 1, 4, 7, 8
            if(size == 2 || size == 4 || size == 3 || size == 7){
                count++;
            }
        }
    }

    return count;
}