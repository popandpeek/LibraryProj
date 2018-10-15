/******************************************************************************
* Ben Pittman
* CS 502A Winter 2017
* HW 4
* libitemfactory.h
* A class for instantiating derived classes of the LibItem class and returning 
* the object for use in the library to store data.
******************************************************************************/

#pragma once

class LibItem;
class ChildrensBook;
class FictionBook;
class Periodical;

using namespace std;

class LibItemFactory {
public:
    LibItemFactory();
    ~LibItemFactory();

    LibItem* create(const char libItemType);
    /* takes a char for LibItem type
    ** and instantiates the correct type of LibItem,
    ** and returns the item
    ** disregard any chars with bad LibItem types,
    */ 
};
