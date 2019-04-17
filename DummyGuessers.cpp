#include "DummyGuessers.hpp"
#include <cstdlib>
#include "string"


std::string RandomGuesser::guess() {
std::string r="";
			for (uint i=0; i<this->length; ++i) {
				char c = '0' + (rand()%10);
				r += c;
			}
			return r;
		}

void RandomGuesser::learn(const string& s) {}
void RandomGuesser::startNewGame(uint uint) {}
void ConstantGuesser::learn(const string& s) {}
void ConstantGuesser::startNewGame(uint uint) {}


