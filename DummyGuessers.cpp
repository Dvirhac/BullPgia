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

void RandomGuesser::learn(const string& result) {}
void RandomGuesser::startNewGame(uint length) {}
void ConstantGuesser::learn(const string& result) {}
void ConstantGuesser::startNewGame(uint length) {}


