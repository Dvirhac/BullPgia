#include "DummyGuessers.hpp"
#include <stdlib.h>
#include "string"



std::string bullpgia:: RandomGuesser::guess() {
std::string r="";
			for (uint i=0; i<this->length; ++i) {
				char c = '0' + (rand()%10);
				r += c;
			}
			return r;
		}

int bullpgia::RandomGuesser::learn(string s) {
return 0;
}

int bullpgia::RandomGuesser::startNewGame(uint uint) {
	return 0;
}

int bullpgia::ConstantGuesser::learn(string s) {
return 0;
}

int bullpgia::ConstantGuesser::startNewGame(uint uint) {
return 0;
}

string bullpgia::ConstantGuesser::guess() {
    return std::__cxx11::string();
}
