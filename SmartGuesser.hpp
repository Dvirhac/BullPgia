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

        void learn(string s) ;
        void startNewGame(uint uint) ;

        string guess() ;

    };
}

#endif //BULLPGIA_SMARTGUESSER_HPP
