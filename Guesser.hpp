//
// Created by Dvir on 16/04/2019.
//
#pragma once
#ifndef BULLPGIA_GUESSER_HPP
#define BULLPGIA_GUESSER_HPP
#include "iostream"
using namespace std;
typedef unsigned int uint;
namespace bullpgia {
    class Guesser {

    public:

        virtual string guess()=0;
        virtual void startNewGame(uint uint){}
        virtual void learn(const string& result){}

    protected:
        uint length=0;
    };
}

#endif //BULLPGIA_GUESSER_HPP
