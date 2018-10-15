/******************************************************************************
* Ben Pittman
* CS 502A Winter 2017
* HW 4
* book.h
* Claass to instantiate Book objects.  Title and year are inherited from the 
* base class, adds author as a data member.  
* set and get author are the only non-virtual methods of this class.
******************************************************************************/

#pragma once

#include <string>
#include "libitem.h"

using namespace std;

class Book : public LibItem {

public:
    Book();
    Book(string, string, string, int, int);
    virtual ~Book();

    //MUTATORS
    virtual void setData(ifstream&) = 0;
    virtual void setPartialData(ifstream&) = 0;
    virtual bool setAuthor(string);

    //ACCESSORS
    virtual string getAuthor() const;

    virtual bool operator==(const LibItem&) const = 0;
    virtual bool operator!=(const LibItem&) const = 0;
    virtual bool operator<(const LibItem&) const = 0;
    virtual bool operator>(const LibItem&) const = 0;

    virtual void print(ostream&) const = 0;
    virtual void printHistory(ostream&) const = 0;

protected:
    string author;
};



