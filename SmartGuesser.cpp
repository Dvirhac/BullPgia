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
        auto first = allOptions.begin();
        advance(first, index);
        myGuess = *first;
        return myGuess;
    }


}

void SmartGuesser::learn(const string& result) {

    auto runner = allOptions.begin();
    while (runner != allOptions.end()){
        string _ans = calculateBullAndPgia(*runner, myGuess);
        if (_ans != result)
            runner = allOptions.erase(runner);
        else runner++;
    }

    for (string currString : allOptions){
        string _ans = calculateBullAndPgia(currString, myGuess);
        if (_ans != result)
            allOptions.erase(currString);
    }
}

void SmartGuesser::startNewGame(uint uint) {
    firstGuess = true;
    allOptions.clear();
    length = uint;

    if (length > 4 ) throw "invalid length";

    string currentString = "";

    switch (uint) {
        case 1: {
            for (int i = 0; i <= 9; i++) {

                currentString += to_string(i);
                allOptions.insert(currentString);
                currentString = "";
            }
        }
        case 2: {
            for (int i = 0; i <= 9; i++) {
                for (int j = 0; j <= 9; j++) {
                    currentString += to_string(i) + to_string(j);
                    allOptions.insert(currentString);
                    currentString = "";
                }


            }
        }
        case 3 : {
            for (int i = 0; i <= 9; i++) {
                for (int j = 0; j <= 9; j++) {
                    for (int z = 0; z <= 9; z++) {
                        currentString += to_string(i) + to_string(j) + to_string(z) ;
                        allOptions.insert(currentString);
                        currentString = "";
                    }
                }

            }
        }
        case 4:{
            for (int i = 0 ; i <= 9; i  ++){
                for (int j = 0 ; j <= 9; j  ++){
                    for (int z = 0 ; z <= 9; z  ++){
                        for (int q = 0 ; q <= 9; q  ++){
                            currentString += to_string(i) + to_string(j) + to_string(z) + to_string(q);
                            allOptions.insert(currentString);
                            currentString = "";
                        }
                    }
                }
            }
        }
    }
}



