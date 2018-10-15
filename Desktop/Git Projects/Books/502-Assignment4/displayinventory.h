/****************************************************************************
* Ben Pittman
* CS 502A Winter 2017
* HW 4
* displayinventory.h
* DisplayInventory instructs the library to execute its function for
* displaying a Library's inventory.
*
* Features:
*   setTransaction(), sets the data members from an input file stream
*   execute(), a method to instruct the library to display a library's
*   data members
*****************************************************************************/

#pragma once

#include <iostream>
#include "transaction.h"

using namespace std;

class DisplayInventory : public Transaction {
public:
    DisplayInventory();
    virtual ~DisplayInventory();

    // method for initializing the transaction object
    virtual void setTransaction(ifstream&);

    // displays the library's history
    virtual void execute(Library*);

};