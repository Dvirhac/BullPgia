//
// Created by Dvir on 16/04/2019.
//

#ifndef BULLPGIA_SMARTGUESSER_HPP
#define BULLPGIA_SMARTGUESSER_HPP

#include "Guesser.hpp"
namespace bullpgia {
    class SmartGuesser : public bullpgia:: Guesser {
    public:
           SmartGuesser()
        //   :Guesser()
           {

           }

        void learn(string) override{

        }
        void startNewGame(uint) override{

        }

        string guess() override{
            string st;
            return st;
        }
    };
}

#endif //BULLPGIA_SMARTGUESSER_HPP
