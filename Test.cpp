#include "doctest.h"
#include "Notebook.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

ariel ::Notebook n;

TEST_CASE("Chack basic throw cases") {
    /* Try to write twich to the same col and row */
    CHECK(n.write(1,1,1,Direction::Horizontal, "hi")==0);
    CHECK_THROWS(n.write(1,1,1,Direction::Horizontal, "hi"));
    CHECK_THROWS(n.write(1,1,2,Direction::Horizontal, "hi"));
}
TEST_CASE("Chack throw whan rewrite") {

    /* Make sure to throws error when delete and write agin on the same place*/
    CHECK(n.erase(1,1,1,Direction::Horizontal, 2)==0);
    CHECK_THROWS(n.write(1,1,1,Direction::Horizontal, "hi"));
}
TEST_CASE("Chack null, negitive and out of range throws") {
    /* cant write empty string */
    CHECK_THROWS(n.write(1,5,5,Direction::Horizontal, ""));

    /*cant writ to negetiv page, col or row */
    CHECK_THROWS(n.write(-2,1,1,Direction::Horizontal, "hi"));
    CHECK_THROWS(n.write(1,-1,1,Direction::Horizontal, "hi"));
    CHECK_THROWS(n.write(1,1,-1,Direction::Horizontal, "hi"));
    CHECK_THROWS(n.erase(-1,1,1,Direction::Horizontal, 5));
    CHECK_THROWS(n.erase(1,-1,1,Direction::Horizontal, 5));
    CHECK_THROWS(n.erase(1,1,-1,Direction::Horizontal, 5));
    CHECK_THROWS(n.read(-1,1,1,Direction::Horizontal, 5));
    CHECK_THROWS(n.read(1,-1,1,Direction::Horizontal, 5));
    CHECK_THROWS(n.read(1,1,-1,Direction::Horizontal, 5));
    CHECK_THROWS(n.show(-1));

    /*row size is limited by 100*/
    CHECK_THROWS(n.write(1,1,101,Direction::Horizontal, "hi"));
    CHECK_THROWS(n.write(1,2,99,Direction::Horizontal, "hi my name is or"));
    CHECK_THROWS(n.erase(1,1,101,Direction::Horizontal, 5));
    CHECK_THROWS(n.read(1,1,101,Direction::Horizontal, 5));

                                          
}

TEST_CASE("Check basic functionlity") {
    /* read write show and erase*/
    CHECK(n.write(2,1,1,Direction::Horizontal, "hi")==0);
    CHECK(n.read(2,1,1,Direction::Horizontal, 2) == "hi");
    CHECK(n.show(2)=="hi_____________");
    CHECK(n.erase(2,1,1,Direction::Horizontal, 2)==0);
    CHECK(n.show(2)=="~~_____________");

    CHECK(n.write(3,1,1,Direction::Vertical, "hi")==0);
    CHECK(n.read(3,1,1,Direction::Vertical, 2) == "hi");
    CHECK(n.erase(3,1,1,Direction::Vertical, 2)==0);
    

}
                                      

