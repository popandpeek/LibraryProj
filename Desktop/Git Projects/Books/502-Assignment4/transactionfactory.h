/****************************************************************************
* Ben Pittman
* CS 502A Winter 2017
* HW 4
* transactionfactory.h
* TransactionFactory represents a factory method design pattern for creating
* transaction objects.  A base class object pointer is instantiated to a
* derived class object based upon a passed char.
*****************************************************************************/

#pragma once

#include <iostream>

using namespace std;

class LibItem;
class Patron;
class Transaction;
class CheckIn;
class CheckOut;
class DisplayInventory;
class DisplayPatronHistory;

class TransactionFactory {
public:
    TransactionFactory();
    ~TransactionFactory();

    // processes transactions from cfr; adds only valid transactions to librarian's queue
    Transaction* createTrans(const char);

};