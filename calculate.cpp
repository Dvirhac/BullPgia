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

        for (int i = 0; i < 10; i++) {
            check[i] = 0;
        }

        for (int i = 0; i < chooser.length(); i++) {
            if (chooser[i] == guesser[i]) {
                bull++;
                chooser.erase(i, 1);
                guesser.erase(i, 1);
                i--;
            }
        }

        for (int i = 0; i < guesser.size(); i++) {
            char tempChar = guesser[i];
            int tempInt = (int) tempChar - 48;
            check[tempInt]++;
        }


        for (int i = 0; i < chooser.size(); i++) {
            for (int j = 0; j < guesser.size(); j++) {
                if (chooser[i] == guesser[j]) { //check for hits
                    char temp = chooser[i];
                    int temp2 = (int) temp - 48;
                    if (check[temp2] > 0) {
                        pgia++;
                        check[temp2]--;
                        j = guesser.length();
                        continue;
                    }


                }

            }

        }

        result = to_string(bull) + "," + to_string(pgia);

        return result;

    }

}



