/****************************************************************************
* Ben Pittman
* CS 502A Winter 2017
* HW 4
* transaction.h
* Transaction is a pure abstract class. The constructor instantiates a 
* pointer to a Library object, which will be used to execute library's
* transaction functions in derived transaction classes.
* Features: 
*	-Execute, a pure virtual method for derived transaction classes to 
*	 implement and act as commands for the library to perform individual
*	 transactions.
*****************************************************************************/

#pragma once

#include <iostream>
#include <fstream>

using namespace std;

class Library;
class LibItem;
class Patron;

class Transaction {

public:
    Transaction(); 
    virtual ~Transaction();

    // method for initializing the transaction object
    virtual void setTransaction(ifstream&) = 0;

    // pure virtual method for executing a transaction
    virtual void execute(Library*) = 0;

protected:
    LibItem *tempItem;
    Patron *tempPatron;
    int tempPatronID;

};