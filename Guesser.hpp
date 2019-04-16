//
// Created by Dvir on 16/04/2019.
//

#ifndef BULLPGIA_GUESSER_HPP
#define BULLPGIA_GUESSER_HPP
#include "string"
using namespace std;
typedef unsigned int uint;
namespace bullpgia {
    class Guesser {
    public:
        Guesser();
        virtual string guess();
        void startNewGame(uint);
        void learn(string);
    };
}

#endif //BULLPGIA_GUESSER_HPP
