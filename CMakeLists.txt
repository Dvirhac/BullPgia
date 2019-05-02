cmake_minimum_required(VERSION 3.13)
project(BullPgia)

set(CMAKE_CXX_STANDARD 17)
include_directories(.)
add_executable(BullPgia
        Test.cpp
        DummyChoosers.cpp DummyChoosers.hpp
        DummyGuessers.cpp DummyGuessers.hpp
        play.cpp play.hpp
        Chooser.hpp
        Guesser.hpp
        calculate.cpp calculate.hpp
        SmartGuesser.cpp SmartGuesser.hpp
        )