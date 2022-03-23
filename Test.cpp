#include "doctest.h"
#include "Notebook.hpp"

TEST_CASE("Parametrs mustn't be negative")
{
    ariel::Notebook notebook;
    CHECK_THROWS(notebook.write(-1,-2,-3,ariel::Direction::Horizontal,"12"));
    CHECK_THROWS(notebook.write(-2,-2,-2,ariel::Direction::Horizontal,"12"));
    CHECK_THROWS(notebook.read(-11,-22,-33,ariel::Direction::Horizontal,5));
    CHECK_THROWS(notebook.read(-17,-7,-8,ariel::Direction::Horizontal,5));
    CHECK_THROWS(notebook.erase(-5,-6,-7,ariel::Direction::Horizontal,6));
    CHECK_THROWS(notebook.erase(-3,-4,-1,ariel::Direction::Horizontal,6));
    CHECK_THROWS(notebook.show(-5));
    CHECK_THROWS(notebook.show(-9));
}

TEST_CASE("Check no throws occur for positive parameters")
{
    ariel::Notebook notebook;
    CHECK_NOTHROW(notebook.write(1,2,3,ariel::Direction::Horizontal,"12"));
    CHECK_NOTHROW(notebook.write(2,2,2,ariel::Direction::Horizontal,"12"));
    CHECK_NOTHROW(notebook.read(11,22,33,ariel::Direction::Horizontal,7));
    CHECK_NOTHROW(notebook.read(17,7,8,ariel::Direction::Horizontal,5));
    CHECK_NOTHROW(notebook.erase(5,6,7,ariel::Direction::Horizontal,6));
    CHECK_NOTHROW(notebook.erase(-3,-4,-1,ariel::Direction::Horizontal,6));
    CHECK_NOTHROW(notebook.show(5));
    CHECK_NOTHROW(notebook.show(9));
}

TEST_CASE("Mustn't write to the same place")
{
    ariel::Notebook notebook;
    notebook.write(9,9,9,ariel::Direction::Horizontal,"61");
    CHECK_THROWS(notebook.write(9,9,9,ariel::Direction::Horizontal,"61"));

    notebook.write(15,15,15,ariel::Direction::Horizontal,"71");
    CHECK_THROWS(notebook.write(15,15,15,ariel::Direction::Horizontal,"71"));

    notebook.write(17,17,17,ariel::Direction::Horizontal,"80");
    CHECK_THROWS(notebook.write(17,17,17,ariel::Direction::Horizontal,"80"));

    notebook.write(19,19,19,ariel::Direction::Horizontal,"299");
    CHECK_THROWS(notebook.write(19,19,19,ariel::Direction::Horizontal,"299"));

}

TEST_CASE("The length of row mustn't excced 100")
{
    ariel::Notebook notebook;
    CHECK_THROWS(notebook.write(19,19,99,ariel::Direction::Horizontal,"312aa"));
    CHECK_THROWS(notebook.write(19,19,90,ariel::Direction::Horizontal,"123456789000"));
    CHECK_THROWS(notebook.write(20,21,95,ariel::Direction::Horizontal,"5555555555"));

    CHECK_NOTHROW(notebook.write(3,2,2,ariel::Direction::Horizontal,"24"));
    CHECK_NOTHROW(notebook.write(5,6,9,ariel::Direction::Horizontal,"14"));
}