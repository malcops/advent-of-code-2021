#include "Day10.hpp"

int isLineCorrupted(std::vector<char> line){

    std::map<char, char> lookup = { {'}','{'},
                                    {']','['},
                                    {'>','<'},
                                    {')','('}
                                  };

    std::map<char, int> values = { {'}', 1197},
                                   {']',57},
                                   {'>',25137},
                                   {')',3}
                                  };

    std::stack<char> s;
    char failure;
    for(int x=0; x<line.size(); x++){
        char brac = line.at(x);
        switch (brac){
            case '{':
            case '<':
            case '[':
            case '(':
                s.push(brac);
                break;
            case '}':
            case ']':
            case '>':
            case ')':
                char m = s.top();
                if(m != lookup[brac]){
                    return values[brac];
                }
                s.pop();
                break;
        }
    }
    return 0;
}

Score autocompleteScore(std::vector<char> line){

    std::map<char, char> lookup = { {'{','}'},
                                    {'[',']'},
                                    {'<','>'},
                                    {'(',')'}
                                  };

    std::map<char, int> values = { {'}',3},
                                   {']',2},
                                   {'>',4},
                                   {')',1}
                                  };

    std::stack<char> s;
    char failure;
    for(int x=0; x<line.size(); x++){
        char brac = line.at(x);
        switch (brac){
            case '{':
            case '<':
            case '[':
            case '(':
                s.push(brac);
                break;
            case '}':
            case ']':
            case '>':
            case ')':
                s.pop();
                break;
        }
    }

    Score score = 0;
    while(!s.empty()){
        char top = s.top();
        score = score*5 + values[lookup[top]];
        s.pop();
    }
    return score;
}

std::vector<std::vector<char> > parseInputVector(inputVector in){

    std::vector<std::vector<char> > input;
    std::vector<char> line;
    for(auto it=in.begin(); it!=in.end(); it++){
        int length=it->size();
        for(auto x=it->begin(); x!=it->end(); x++){
            line.push_back(*x);
        }
        input.push_back(line);
        line.clear();
    }
    return input;
}

int part1(inputVector in){

    auto input = parseInputVector(in);
    int score = 0;
    for(auto it=input.begin(); it!=input.end(); it++){
        score += isLineCorrupted(*it);
    }

    return score;

}

int part2(inputVector in){

    auto input = parseInputVector(in);
    std::vector<Score> scores;
    for(auto it=input.begin(); it!=input.end(); it++){
        if(!isLineCorrupted(*it)){
            scores.push_back(autocompleteScore(*it));
        }
    }

    int idx = scores.size()/2;
    std::sort(scores.begin(), scores.end());
    return scores.at(idx);
}