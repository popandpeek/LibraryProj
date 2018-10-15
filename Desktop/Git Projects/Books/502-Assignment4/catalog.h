/******************************************************************************
* Ben Pittman
* CS 502A Winter 2017
* HW 4
* catalog.h
* Data structure to hold our LibItem ADTs.  We use a set to store LibItem's,
* and a comparator function (functor) is included such that we can properly
* sort the set in the proper order.  The functor allows the derived items
* comparison functions to sort the items.  We have 26 sets stored in an array;
* hased into based upon their derived type.  getTypeCode() is our hash function
******************************************************************************/

#pragma once

#include <string>
#include <vector>
#include <set>
#include "childrensbook.h"
#include "fictionbook.h"
#include "periodical.h"

using namespace std;

class LibItem;

class Catalog {
public:
    Catalog();
    ~Catalog();
    
    bool addItem(LibItem*);

    int getSetCount(char);

    int getTypeCode(char);

    LibItem* getLibItem(LibItem*);

    void printCatalog(char);

    void printAll();

private:

    struct PtrComp {
        bool operator()(const LibItem *lhs, const LibItem *rhs) const {
            return *lhs < *rhs;
        }
    };

    // sets of LibItem pointers 
    set<LibItem*, PtrComp> *itemCatalog;

};

