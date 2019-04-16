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

void bullpgia::RandomGuesser::learn(string s) {

}

void bullpgia::RandomGuesser::startNewGame(uint uint) {

}

void bullpgia::ConstantGuesser::learn(string s) {

}

void bullpgia::ConstantGuesser::startNewGame(uint uint) {

}

string bullpgia::ConstantGuesser::guess() {
    return std::__cxx11::string();
}
