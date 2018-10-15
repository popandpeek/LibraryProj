/****************************************************************************
* Ben Pittman
* CS 502A Winter 2017
* HW 4
* checkout.h
* Check-Out instructs the library to execute its function for checking-out
* a library item. The constructor instantiates a pointer to a LibItem
* containing info for the item to be checked-out, as well as a Patron object
* containing the info for the patron checking-out the item.
*
* Features:
*   - setTransaction(), virtual function sets the data members for the
*     check-out
*	- execute(), virtual method to instruct the library to check-out a
*     library item
*****************************************************************************/

#pragma once

#include <iostream>
#include "transaction.h"

using namespace std;

class CheckOut : public Transaction {

public:
    CheckOut();
    virtual ~CheckOut();

    // method for initializing the transaction object
    virtual void setTransaction(ifstream&);

    // Performs the transaction
    virtual void execute(Library*);

};