/******************************************************************************
* Ben Pittman 
* CS 502A Winter 2017
* HW 4
* fictionbook.h
* ADT for FictionBooks.  All data members are inherited from the base classes
* Features:
* setData() method for setting the data from a file
* partialSetData() method for setting limited data to search our library and
* complete transactions on LibItem objects.
* print() and printHistory() allow ADT to be printed to console for viewing
* in different circumstances.
******************************************************************************/

#pragma once

#include <string>
#include "book.h"

using namespace std;

class FictionBook : public Book {

public:
    FictionBook();
    FictionBook(string, string, string, int, int);
    virtual ~FictionBook();

    //MUTATORS
    virtual void setData(ifstream&);
    virtual void setPartialData(ifstream&);

    virtual bool operator==(const LibItem&) const;
    virtual bool operator!=(const LibItem&) const;
    virtual bool operator<(const LibItem&) const;
    virtual bool operator>(const LibItem&) const;

    virtual void print(ostream&) const;
    virtual void printHistory(ostream&) const;
};



