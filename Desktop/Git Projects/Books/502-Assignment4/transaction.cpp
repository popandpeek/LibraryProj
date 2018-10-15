/****************************************************************************
* Ben Pittman
* CS 502A Winter 2017
* HW 4
* transaction.cpp
* Transaction is a pure abstract class. The constructor instantiates a
* pointer to a Library object, which will be used to execute library's
* transaction functions in derived transaction classes.
* Features:
*	-Execute, a pure virtual method for derived transaction classes to
*	 implement and act as commands for the library to perform individual
*	 transactions.
*****************************************************************************/

#include "transaction.h"
#include "library.h"
#include "libitemfactory.h"
#include "libitem.h"
#include "patron.h"

Transaction::Transaction() { 
    tempItem = nullptr;
    tempPatron = nullptr;
    tempPatronID = -1;
}

Transaction::~Transaction() {
    tempItem = nullptr;
    tempPatron = nullptr;
}
