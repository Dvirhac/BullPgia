/**
 * A demo program for bull-pgia.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */




#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace bullpgia;

int main() {

    badkan::TestCase testcase;
    int grade=0;
    int signal = setjmp(badkan::longjmp_buffer);
    if (signal == 0) {

        // BASIC TESTS - DO NOT CHANGE
        ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"}, c012{"012"},c0000{"0000"}, c123{"123"} ;
        ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"} , g0000{"0000"}, g123{"123"}, g5555{"5555"}, g124{"124"} ;




        testcase.setname("Calculate bull and pgia")

                .CHECK_OUTPUT(calculateBullAndPgia("2552","2222"), "2,0")
                .CHECK_OUTPUT(calculateBullAndPgia("1234","1234"), "4,0")      // 4 bull, 0 pgia
                .CHECK_OUTPUT(calculateBullAndPgia("1256","1278"), "2,0")      // 0 bull, 4 pgia
                .CHECK_OUTPUT(calculateBullAndPgia("3456","1298"), "0,0")
                .CHECK_OUTPUT(calculateBullAndPgia("1678","6284"), "0,2")
                .CHECK_OUTPUT(calculateBullAndPgia("5678","8765"), "0,4")
                .CHECK_OUTPUT(calculateBullAndPgia("1289","8219"), "2,2")
                .CHECK_OUTPUT(calculateBullAndPgia("1289","8219"), "2,2")
                .CHECK_OUTPUT(calculateBullAndPgia("12345","56789"), "0,1")
                .CHECK_OUTPUT(calculateBullAndPgia("987654","123456"), "1,2")
                .CHECK_OUTPUT(calculateBullAndPgia("2223334","3332224"), "1,6")
                .CHECK_OUTPUT(calculateBullAndPgia("332244","224433"), "0,6")
                .CHECK_OUTPUT(calculateBullAndPgia("111","111"), "3,0")
                .CHECK_OUTPUT(calculateBullAndPgia("122334","433224"), "1,4")
                .CHECK_OUTPUT(calculateBullAndPgia("77775888","77779888"), "7,0")
                .CHECK_OUTPUT(calculateBullAndPgia("1131122","2231122"), "5,0")
                .CHECK_OUTPUT(calculateBullAndPgia("2213","4562"), "0,1")
                .CHECK_OUTPUT(calculateBullAndPgia("4522","2213"), "0,2")
                .CHECK_OUTPUT(calculateBullAndPgia("2552","5222"), "1,2")
                .CHECK_OUTPUT(calculateBullAndPgia("2552","5222"), "1,2")
                .CHECK_OUTPUT(calculateBullAndPgia("5222","2552"), "1,2")


                ;

        testcase.setname("Our Calculate bull and pgia tests")
                .CHECK_OUTPUT(calculateBullAndPgia("3456","1298"), "0,0")
                .CHECK_OUTPUT(calculateBullAndPgia("1678","6284"), "0,2")
                .CHECK_OUTPUT(calculateBullAndPgia("5678","8765"), "0,4")
                .CHECK_OUTPUT(calculateBullAndPgia("1289","8219"), "2,2")
                .CHECK_OUTPUT(calculateBullAndPgia("1289","8219"), "2,2")
                .CHECK_OUTPUT(calculateBullAndPgia("12345","56789"), "0,1")
                .CHECK_OUTPUT(calculateBullAndPgia("987654","123456"), "1,2")
                .CHECK_OUTPUT(calculateBullAndPgia("2223334","3332224"), "1,6")
                .CHECK_OUTPUT(calculateBullAndPgia("332244","224433"), "0,6")
                .CHECK_OUTPUT(calculateBullAndPgia("111","111"), "3,0")
                .CHECK_OUTPUT(calculateBullAndPgia("122334","433224"), "1,4")
                .CHECK_OUTPUT(calculateBullAndPgia("77775888","77779888"), "7,0")
                .CHECK_OUTPUT(calculateBullAndPgia("1131122","2231122"), "5,0")
                .CHECK_OUTPUT(calculateBullAndPgia("2213","4562"), "0,1")
                .CHECK_OUTPUT(calculateBullAndPgia("4522","2213"), "0,2")
                .CHECK_OUTPUT(calculateBullAndPgia("2552","5222"), "1,2")
                .CHECK_OUTPUT(calculateBullAndPgia("2552","5222"), "1,2")
                .CHECK_OUTPUT(calculateBullAndPgia("5222","2552"), "1,2")
                .CHECK_OUTPUT(calculateBullAndPgia("2552","2222"), "2,0")
                .CHECK_OUTPUT(calculateBullAndPgia("1234","5678"), "0,0")


                ;





        testcase.setname("Play with dummy choosers and guessers")
                .CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)      // guesser wins in one turn.
                .CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)    // guesser loses by running out of turns
                .CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
                .CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)

                ;

        testcase.setname("Our play with dummy choosers and guessers test")
                .CHECK_EQUAL(play(c0000, g0000, 4, 1), 1)
                .CHECK_EQUAL(play(c0000, g123, 4, 50), 51)
                .CHECK_EQUAL(play(c012, g1234, 4, 100), 0)
                .CHECK_EQUAL(play(c123, g123, 3, 100), 1)
                .CHECK_EQUAL(play(c0000, g124, 4, 100), 101)
                ;


        testcase.setname("Play with smart guesser");
        RandomChooser randy;
        SmartGuesser smarty;
        for (uint i=0; i<100; ++i) {
            testcase.CHECK_EQUAL(play(randy, smarty, 4, 100) <= 100, true);  // smarty should always win in at most 100 turns!
            testcase.CHECK_EQUAL(play(randy, smarty, 4, 100) > 100, false);  // smarty should always win in at most 100 turns!
        }

        testcase.setname("Our play with smart guesser test")

                .CHECK_EQUAL(play(c123,smarty,3,100) <= 100 , true)
                .CHECK_EQUAL(play(c12345,smarty,4,100) == 0 , true)
                .CHECK_EQUAL(play(c12345,smarty,4,100) != 0 , false)
                .CHECK_EQUAL(play(c0000,smarty,4,100)<= 100, true);




        grade = testcase.grade();
    } else {
        testcase.print_signal(signal);
        grade = 0;
    }
    cout << "Your grade is: "  << grade << endl;
    return 0;
}


