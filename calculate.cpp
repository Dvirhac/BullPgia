#include "calculate.hpp"
#include <iostream>

using namespace std;
using namespace bullpgia;

namespace bullpgia {
    string calculateBullAndPgia(string choice, string guess) {
        int bull = countAndRemoveBull(choice, guess);
        int pgia = countPgia(choice, guess);
        string result = to_string(bull) + ',' + to_string(pgia);
        return result;
    }

    int countAndRemoveBull(string& choice, string& guess) {
        string newChoice = choice;
        string newGuess = guess;
        int ci = 0;
        int gi = 0;
        int count = 0;
        for (int i=0;i<newChoice.length();i++) {
            if (newChoice[i] == newGuess[i]) {
                guess = guess.substr(0, gi) + guess.substr(gi+1);
                choice = choice.substr(0, ci) + choice.substr(ci+1);
                ci--; gi--;
                count++;
            }
            ci++; gi++;
        }
        return count;
    }

    int countPgia(string& choice, string& guess) {
        int count = 0;
        for (int i=0;i<guess.length();i++) {
            for (int j=0;j<choice.length();j++) {
                if (guess[i] == choice[j]) {
                    count++;
                    guess = guess.substr(0, i) + guess.substr(i+1);
                    choice = choice.substr(0, j) + choice.substr(j+1);
                    i--;
                    break;
                }
            }
        }

        return count;
    }
}