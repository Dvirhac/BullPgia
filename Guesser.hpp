//
// Created by Dvir on 16/04/2019.
//

#ifndef BULLPGIA_GUESSER_HPP
#define BULLPGIA_GUESSER_HPP
#include <string>
using namespace std;
typedef unsigned int uint;
namespace bullpgia {
    class Guesser {

    public:


        virtual string guess()=0;
        virtual void startNewGame(uint uint) =0;
        virtual void learn(string s) =0;
    };
}

#endif //BULLPGIA_GUESSER_HPP
