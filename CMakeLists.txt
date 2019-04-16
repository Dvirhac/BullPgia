cmake_minimum_required(VERSION 3.13)
project(BullPgia)

set(CMAKE_CXX_STANDARD 17)

add_executable(Demo.cpp DummyChoosers.cpp DummyChoosers.hpp DummyGuessers.cpp DummyGuessers.hpp play.cpp play.hpp Test.cpp Chooser.cpp Chooser.hpp Guesser.cpp Guesser.hpp calculate.cpp calculate.hpp SmartGuesser.cpp SmartGuesser.hpp)