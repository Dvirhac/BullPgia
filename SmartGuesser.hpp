//
// Created by Dvir on 16/04/2019.
//

#ifndef BULLPGIA_SMARTGUESSER_HPP
#define BULLPGIA_SMARTGUESSER_HPP

#include "Guesser.hpp"

    class SmartGuesser : public bullpgia:: Guesser {
    public:
            SmartGuesser()
           {

           }

        void learn(string s) override;
        void startNewGame(uint uint) override;
        string guess() override;

    };


#endif //BULLPGIA_SMARTGUESSER_HPP
