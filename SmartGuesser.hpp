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

        virtual void learn(string s) override;
        virtual void startNewGame(uint uint) override;
        virtual string guess() override;

    };
}

#endif //BULLPGIA_SMARTGUESSER_HPP
