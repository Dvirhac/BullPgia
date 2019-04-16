#pragma once
#include "Guesser.hpp"
#include "string"
using std::string;


/**
 * ConstantGuesser is a guesser that always guesses the same string. 
 */
class ConstantGuesser: public bullpgia::Guesser{
	string myConstantString;
public:
	ConstantGuesser(const string& constantString)

	{
		myConstantString = constantString;
	}

	string guess() override {
		return myConstantString;
	}

    void learn(string) override;
    void startNewGame(uint) override;
};

/**
 * RandomGuesser is a guesser that guesses a random string.
 */
class RandomGuesser: public bullpgia::Guesser {
	int length;
	string guess() override;

};
