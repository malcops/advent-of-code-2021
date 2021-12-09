#include "Day4.hpp"

int checkForWinner(Card* c){

    // check winning rows
    int res = 1;
    for(int row = 0; row < BOARD_SIZE; row++){
        res = 1;
        for (int col = 0; col < BOARD_SIZE; col++){
            res = res && c->called[row][col];
        }
        if (res){
            return res;
        }
    }
    // check winning cols
    res = 1;
    for(int col = 0; col < BOARD_SIZE; col++){
        res = 1;
        for (int row = 0; row < BOARD_SIZE; row++){
            res = res && c->called[row][col];
        }
        if (res){
            return res;
        }
    }
    return res;
}

std::vector<int> parseDraws(inputVector input){

    std::vector<int> draws;
    std::stringstream ss(input.at(0));
    while( ss.good() )
    {
        std::string substr;
        getline( ss, substr, ',' );
        draws.push_back( stoi(substr) );
    }
    return draws;
}

std::vector<Card> parseCards(inputVector input){
    std::vector<Card> bingoCards;
    std::vector<std::string> cardStrings;

    // newCard.board[0][0] = stoi(input.at(1));
    int cardSize = BOARD_SIZE * BOARD_SIZE;
    int numAdded = 0;
    int col = 0;
    int row = 0;
    Card newCard = { 0 };
    for(int x=1; x<input.size(); x++){
        // std::cout << input.at(x) << std::endl;
        if(numAdded == cardSize){
            bingoCards.push_back(newCard);
            newCard = { 0 };
            numAdded = 0;
            row = 0;
            col = 0;
        }
        newCard.board[row][col] = stoi(input.at(x));
        row = (col + 1) % BOARD_SIZE ? row:(row+1);
        col = (col + 1) % BOARD_SIZE;
        numAdded++;
    }
    bingoCards.push_back(newCard);
    return bingoCards;
}

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

int part1(inputVector input){

    auto draws = parseDraws(input);
    auto cards = parseCards(input);
    Card* c;
    int draw;
    for (auto it=draws.begin(); it!=draws.end(); it++){
        draw = *it;
        for (int card=0; card < cards.size(); card++){
            c = &cards.at(card);
            for(int row = 0; row < BOARD_SIZE; row++){
                for (int col = 0; col < BOARD_SIZE; col++){
                    if(c->board[row][col] == draw){
                        c->called[row][col] = 1;
                    }
                }
            }
            if (checkForWinner(c)){
                int sum = 0;
                for(int row = 0; row < BOARD_SIZE; row++){
                    for (int col = 0; col < BOARD_SIZE; col++){
                        if(c->called[row][col] == 0){
                            sum += c->board[row][col];
                        }
                    }
                }
                return draw * sum;
            }
        }
    }
    return -1;
}

int part2(inputVector input){

    auto draws = parseDraws(input);
    auto cards = parseCards(input);
    Card* c;
    int draw;
    for (auto it=draws.begin(); it!=draws.end(); it++){
        draw = *it;
        for (int card=0; card < cards.size(); card++){
            c = &cards.at(card);
            for(int row = 0; row < BOARD_SIZE; row++){
                for (int col = 0; col < BOARD_SIZE; col++){
                    if(c->board[row][col] == draw){
                        c->called[row][col] = 1;
                    }
                }
            }
        }
        for (int card=0; card < cards.size(); card++){
            c = &cards.at(card);
            if (checkForWinner(c)){
                if(cards.size() == 1){
                    int sum = 0;
                    for(int row = 0; row < BOARD_SIZE; row++){
                       for (int col = 0; col < BOARD_SIZE; col++){
                           if(c->called[row][col] == 0){
                               sum += c->board[row][col];
                           }
                       }
                    }
                    return draw * sum;
                }
                cards.erase(cards.begin() + card);
            }
        }
    }
    return -1;
}