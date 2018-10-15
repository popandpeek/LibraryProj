/******************************************************************************
* Ben Pittman
* CS 502A Winter 2017
* HW 4
* periodical.h
* ADT for Periodicals.  All members but month are inherited from base class
* Features:
* setData() method for setting the data from a file
* partialSetData() method for setting limited data to search our library and
* complete transactions on LibItem objects.
* print() and printHistory() allow ADT to be printed to console for viewing
* in different circumstances.
******************************************************************************/

#pragma once

#include <string>
#include "libitem.h"

using namespace std;

class Periodical : public LibItem {

public:
    Periodical();
    Periodical(string, string, int);
    virtual ~Periodical();

    //MUTATORS
    virtual void setData(ifstream&);
    virtual void setPartialData(ifstream&);
    virtual void setMonth(int);
    virtual void setFormat(char);

    //ACCESSORS
    virtual int getMonth() const;
    virtual char getFormat() const;

    //COMPARISONS
    virtual bool operator==(const LibItem&) const;
    virtual bool operator!=(const LibItem&) const;
    virtual bool operator<(const LibItem&) const;
    virtual bool operator>(const LibItem&) const;
    
    // INPUT/OUPUT
    virtual void print(ostream&) const;
    virtual void printHistory(ostream&) const;

protected:
    int month;
};

