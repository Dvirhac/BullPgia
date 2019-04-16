#pragma once
#include "Guesser.hpp"
#include "string"
using std::string;


/**
 * ConstantGuesser is a guesser that always guesses the same string. 
 */
namespace bullpgia {
	class ConstantGuesser : public bullpgia::Guesser {
		string myConstantString;
	public:
		ConstantGuesser(const string &constantString)
		//:Guesser()
		{
			myConstantString = constantString;
		}

		void learn(string s) override;

		void startNewGame(uint uint) override;


		string guess() override ;



	};
}

/**
 * RandomGuesser is a guesser that guesses a random string.
 */
namespace bullpgia {
	class RandomGuesser : public bullpgia::Guesser {
	public :
		uint length;
		/*RandomGuesser()
        :Guesser()
        {

        }*/
		string guess() override;

		void learn(string s) override;

		void startNewGame(uint uint) override;

	};
}
