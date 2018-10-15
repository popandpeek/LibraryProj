/****************************************************************************
* Ben Pittman
* CS 502A Winter 2017
* HW 4
* checkin.h
* Check-In instructs the library to execute its function for checking-in 
* a library item. The constructor instantiates a pointer to a LibItem 
* containing info for the item to be checked-in, as well as a Patron object 
* containing the info for the patron checking-in the item.
* 
* Features:
*   - setTransaction(), virtual function sets the data members for the 
*     check-in 
*	- execute(), virtual method to instruct the library to check-in a 
*     library item
*****************************************************************************/

#pragma once

#include <iostream>
#include "transaction.h"

using namespace std;

class CheckIn : public Transaction {

public:
    CheckIn();
    virtual ~CheckIn();

    // method for initializing the transaction object
    virtual void setTransaction(ifstream&);

    // Method that performs the check-in
    virtual void execute(Library*);

};

