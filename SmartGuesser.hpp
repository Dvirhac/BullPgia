//
// Created by Dvir on 16/04/2019.
//

#ifndef BULLPGIA_SMARTGUESSER_HPP
#define BULLPGIA_SMARTGUESSER_HPP

#include "Guesser.hpp"
#include "string"
#include "calculate.hpp"
#include "set"
#include "iterator"

namespace bullpgia {

    class SmartGuesser : public bullpgia::Guesser {

    public:

        void learn(const string &result) override;

        void startNewGame(uint uint) override;

        string guess() override;

    private:
        set<string> allOptions;
        string myGuess = "";
        bool firstGuess;
        uint length = 0;

    };
}

#endif //BULLPGIA_SMARTGUESSER_HPP
