/****************************************************************************
* Ben Pittman
* CS 502A Winter 2017
* HW 4
* transactionfactory.cpp
* TransactionFactory represents a factory method design pattern for creating
* transaction objects.  A base class object pointer is instantiated to a 
* derived class object based upon a passed char.
*****************************************************************************/

#include "transactionfactory.h"
#include "librarian.h"
#include "transaction.h"
#include "checkin.h"
#include "checkout.h"
#include "displayinventory.h"
#include "displaypatronhistory.h"


TransactionFactory::TransactionFactory() { }

TransactionFactory::~TransactionFactory() { }

Transaction* TransactionFactory::createTrans(const char transType) {
    Transaction *newTrans = nullptr;
    switch (transType) {
    case 'C':
        newTrans = new CheckOut();
            break;
    case 'R':
        newTrans = new CheckIn();
            break;
    case 'H':
        newTrans = new DisplayPatronHistory();
            break;
    case 'D':
        newTrans = new DisplayInventory();
            break;
    // if action code is invalid, do nothing
    }
    return newTrans;
}
