//
// Created by Dvir on 16/04/2019.
//

#include "SmartGuesser.hpp"
using std::string;
using namespace bullpgia;
std:: string SmartGuesser::guess() {
    if (firstGuess) {
        switch (length){
            case 1:
                myGuess = "1";
                break;
            case 2:
                myGuess = "12";
                break;
            case 3:
                myGuess =  "112";
                break;
            case 4:
                myGuess = "1122";
                break;
        }
        firstGuess = false;
        return myGuess;
    }

    else {
        int index = rand()%allOptions.size();
        auto chosen = allOptions.begin();
        advance(chosen, index);
        myGuess = *chosen;
        return myGuess;
    }


}

void SmartGuesser::learn(const string& result) {
    string _ans = "";
    auto runner = allOptions.begin();
    while (runner != allOptions.end()){
        _ans = calculateBullAndPgia(*runner, myGuess);
        if (_ans != result)
            runner = allOptions.erase(runner);
        else runner++;
    }


}

void SmartGuesser::startNewGame(uint length) {
    firstGuess = true;
    allOptions.clear();
    this->length = length;
    list<string>::iterator it = allOptions.begin();

    if (length <= 4 )
    {

        string currentString = "";

        switch (length) {
            case 1: {
                for (int i = 0; i <= 9; i++) {

                    currentString += to_string(i);
                    allOptions.insert(it, currentString);
                    currentString = "";
                    advance(it, 1);
                }
                break;
            }

            case 2: {
                for (int i = 0; i <= 9; i++) {
                    for (int j = 0; j <= 9; j++) {
                        currentString += to_string(i) + to_string(j);
                        allOptions.insert(it, currentString);
                        currentString = "";
                        advance(it, 1);
                    }


                }
                break;
            }

            case 3 : {
                for (int i = 0; i <= 9; i++) {
                    for (int j = 0; j <= 9; j++) {
                        for (int z = 0; z <= 9; z++) {
                            currentString += to_string(i) + to_string(j) + to_string(z);
                            allOptions.insert(it, currentString);
                            currentString = "";
                            advance(it, 1);
                        }
                    }

                }
                break;
            }

            case 4: {
                for (int i = 0; i <= 9; i++) {
                    for (int j = 0; j <= 9; j++) {
                        for (int z = 0; z <= 9; z++) {
                            for (int q = 0; q <= 9; q++) {
                                currentString += to_string(i) + to_string(j) + to_string(z) + to_string(q);
                                allOptions.insert(it, currentString);
                                currentString = "";
                                advance(it, 1);
                            }
                        }
                    }
                }
                break;
            }
        }
    }
    else{}
}



