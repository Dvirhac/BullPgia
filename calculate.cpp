//
// Created by Dvir on 16/04/2019.
//

#include <iostream>
#include "calculate.hpp"
using std::string;
namespace bullpgia {
    string calculateBullAndPgia(string chooser, string guesser) {
        string result = "";
        int bull=0;
        int pgia=0;
        if(chooser.size() != guesser.size()) throw "ERROR! NOT THE SAME SIZE";
        for (int i = 0 ; i < chooser.size();i++){
            for (int j = 0 ; j < guesser.size() ;j++ ){
                if(chooser.at(i) == guesser.at(j) && i == j){
                    bull++;
                    continue;
                }
                else if (chooser.at(i) == guesser.at(j)){
                    pgia++;
                    continue;
                }

            }
            continue;
        }

        result = to_string(bull) + "," + to_string(pgia);
        return result;
    }
}
