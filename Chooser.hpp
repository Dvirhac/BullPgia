//
// Created by Dvir on 16/04/2019.
//
#pragma once
#ifndef BULLPGIA_CHOOSER_HPP
#define BULLPGIA_CHOOSER_HPP
#include "string"
#include "calculate.hpp"
using namespace std;
typedef unsigned int uint;
namespace bullpgia{
    class Chooser {
    public:

        virtual string choose(uint length)=0; //pure
    };

}
#endif //BULLPGIA_CHOOSER_HPP
