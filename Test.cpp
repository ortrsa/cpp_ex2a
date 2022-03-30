/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: Or Trabelsi
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good input @ and - Symbols with diffrent mat size") {
	/* Example test */
    CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));
	/* Test -  1 */
    CHECK(nospaces(mat(7, 7, '@', '-')) == nospaces("@@@@@@@\n"
													 "@-----@\n"
													 "@-@@@-@\n"
													 "@-@-@-@\n"
													 "@-@@@-@\n"
													 "@-----@\n"
													 "@@@@@@@"));

    /* Test -  2 */
    CHECK(nospaces(mat(3, 7, '@', '-')) == nospaces("@@@\n"
													 "@-@\n"
													 "@-@\n"
													 "@-@\n"
													 "@-@\n"
													 "@-@\n"
													 "@@@"));                                                    
                                          
}

TEST_CASE("bad input @ and - Symbols with diffrent mat size") {
	/* Test -  3 */
    CHECK(nospaces(mat(9, 7, '@', '-')) != nospaces("$$$$$$$$$\n"
													 "$-------$\n"
													 "$-$$$$$-$\n"
													 "$-$---$-$\n"
													 "$-$$$$$-$\n"
													 "$-------$\n"
													 "$$$$$$$$$"));
	/* Test -  4 */
    CHECK(nospaces(mat(7, 7, '@', '-')) != nospaces("@@@@@@@\n"
													 "@_____@\n"
													 "@_@@@_@\n"
													 "@_@_@_@\n"
													 "@_@@@_@\n"
													 "@_____@\n"
													 "@@@@@@@"));

    /* Test -  5 */
    CHECK(nospaces(mat(3, 7, '@', '-')) != nospaces("@@@\n"
													 "@@@\n"
													 "@@@\n"
													 "@@@\n"
													 "@@@\n"
													 "@@@\n"
													 "@@@"));                                                    
                                          
}

TEST_CASE("good input mat with diffrent size") {
	/* Test -  6 */
    CHECK(nospaces(mat(3, 3, '@', '-')) == nospaces("@@@\n"
                                                    "@-@\n"
                                                    "@@@"));
	/* Test -  7 */
    CHECK(nospaces(mat(7, 3, '$', '-')) == nospaces("$$$$$$$\n"
													 "$-----$\n"
													 "$$$$$$$"
													 ));

    /* Test -  8 */
    CHECK(nospaces(mat(3, 7, '@', '.')) == nospaces("@@@\n"
													 "@.@\n"
													 "@.@\n"
													 "@.@\n"
													 "@.@\n"
													 "@.@\n"
													 "@@@"));                                                    
                                          
}


TEST_CASE("Bad input") {
    /* Test -  9 */
    CHECK_THROWS(mat(10, 5, '$', '%'));

    /* Test -  10 */
    CHECK_THROWS(mat(10, 4, '@', '-'));

    /* Test -  11 */
    CHECK_THROWS(mat(10, 5, '@', '-'));

    /* Test -  12 */
    CHECK_THROWS(mat(5, 10, '@', '-'));

    /* Test -  13 */
    CHECK_THROWS(mat(0, 5, '@', '-'));

    /* Test -  14 */
    CHECK_THROWS(mat(5, 0, '@', '-'));

    /* Test -  15 */
    CHECK_THROWS(mat(2, 2, '@', '-'));

    /* Test -  16 */
    CHECK_THROWS(mat(0, 0, '@', '-'));
    
}


TEST_CASE("diffrent sizes mat ") {
	/* Test -  17 */
    CHECK(nospaces(mat(1, 1, '@', '-')) == nospaces("@"));

	/* Test -  18 */
    CHECK(nospaces(mat(3, 3, '@', '-')) == nospaces("@@@\n"
													 "@-@\n"
													 "@@@"));

    /* Test -  19 */
    CHECK(nospaces(mat(1, 7, '@', '-')) == nospaces("@\n"
													 "@\n"
													 "@\n"
													 "@\n"
													 "@\n"
													 "@\n"
													 "@"));

    /* Test -  20 */
    CHECK(nospaces(mat(7, 1, '@', '-')) == nospaces("@@@@@@@"));

    /* Test -  21 */
    CHECK(nospaces(mat(7, 3, '@', '+')) == nospaces("@@@@@@@\n"
                                                    "@+++++@\n"
                                                    "@@@@@@@"
                                                    ));                                                                                                      
                                          
}

TEST_CASE("negetiv mat ") {
	/* Test -  22 */
	CHECK_THROWS(mat(-1, 1, '@', '-'));

	/* Test -  23 */
	CHECK_THROWS(mat(3, -3, '@', '-'));

    /* Test -  24 */
	CHECK_THROWS(mat(1, -7, '@', '-'));

    /* Test -  25 */
	CHECK_THROWS(mat(-7, 1, '@', '-'));

    /* Test -  26 */
	CHECK_THROWS(mat(-2, 3, '@', '+'));
                                                                                                
                                          
}
