//
// Created by Dvir on 16/04/2019.
//

#include <iostream>
#include "calculate.hpp"
using std::string;
namespace bullpgia {
    string calculateBullAndPgia(string chooser, string guesser) {
        string result = "";
        int bull = 0;
        int pgia = 0;
        int check[10];
        int index[chooser.size()];
        for(int i = 0 ; i < 10 ; i++){
            check[i] = 0;
        }

        for(int i = 0 ; i < chooser.length(); i++){
            index[i] = 0;
        }

       for(int i = 0 ; i < chooser.size() ; i++){
           char tempChar = chooser.at(i);
           int tempInt = (int)tempChar - 48;
           check[tempInt]++;
        }


        if(chooser.size() != guesser.size()) throw "ERROR! NOT THE SAME SIZE";
        for (int i = 0 ; i < chooser.size();i++){
            for (int j = 0 ; j < guesser.size() ;j++ ){
                if(chooser.at(i) == guesser.at(j) && i == j){


                        bull++;
                        index[j]++;
                        j = guesser.size();


                }
                else if (chooser.at(i) == guesser.at(j) && index[j] == 0){
                    if (chooser.at(i) == guesser.at(i)|| chooser.at(j) == guesser.at(j)){
                        bull++;
                       index[j]++;
                        j = guesser.size();
                        continue;
                    }
                    char temp = chooser.at(i);
                    int temp2 = (int)temp - 48;
                    if(check[temp2] != 0) {
                        pgia++;
                        check[temp2]--;
                        continue;

                    }

                }

            }


        }

        result = to_string(bull) + "," + to_string(pgia);

        return result;
    }
}
