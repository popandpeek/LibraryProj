/****************************************************************************
* Ben Pittman
* CS 502A Winter 2017
* HW 4
* displaypatronhistory.h
* DisplayPatronHistory instructs the library to execute its function for 
* displaying a given patron's transaction history with the library. The 
* constructor instantiates a pointer to a Patron object containing the info 
* for the patron whose history will be displayed.
*
* Features:
*   setTransaction(), sets the data members from an input file stream
*   execute(), a method to instruct the library to display a library's
*   data members
*****************************************************************************/
#pragma once

#include <iostream>
#include <fstream>
#include "transaction.h"


using namespace std;

class DisplayPatronHistory : public Transaction {
public:
    DisplayPatronHistory();
    virtual ~DisplayPatronHistory();

    // method for initializing the transaction object
    virtual void setTransaction(ifstream&);

    // displays the patron's history
    virtual void execute(Library*);

};