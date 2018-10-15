/******************************************************************************
* Ben Pittman
* CS 502A Winter 2017
* HW 4
* librarian.cpp
* The Librarian object is a manager that pulls in the data files, calls the
* LibItemFactory to fill our Library with LibItem objects, our PatronDB
* with Patrons and calls our TransactionFactory to create transactino objects
* for processing actions in our Library - checking in/out books, displaying
* a patrons history and displaying the contents of the library.
*****************************************************************************/

#include <limits.h>
#include "librarian.h"
#include "libitemfactory.h"
#include "transactionfactory.h"
#include "periodical.h"
#include "patrondb.h"
#include "patron.h"
#include "transaction.h"

static const int STARTINGINV = 5;
static const char BOOKCODE = 'H';

Librarian::Librarian(string bookFile, string patronFile, string commandFile) {
    buildLibrary(bookFile);
    buildTransactions(commandFile);
}

Librarian::~Librarian() {
    delete Lib;
    delete makeLibItems;
    delete makeTrans;
    Lib = nullptr;
    makeLibItems = nullptr;
    makeTrans = nullptr;
}

void Librarian::buildLibrary(string fileName) {
    Lib = new Library();
    fillLibraryCatalog(fileName);
    buildPatrons("data4patrons.txt");
}

void Librarian::fillLibraryCatalog(string fileName) {
    ifstream bookStream(fileName);
    char itemCode;
    while (!bookStream.eof()) {
        bookStream >> itemCode;
        if (!bookStream.eof()) {
            LibItem  *newItem = makeLibItems->create(itemCode);
            // NULLPTR TEST for bad itemCode
            if (newItem != nullptr) {
                newItem->setData(bookStream);
                newItem->setLibItemType(itemCode);
                newItem->setFormat(BOOKCODE);
                Lib->addLibItem(newItem);
            }
            else {
                bookStream.ignore(INT_MAX, '\n');
                cout << "Library item not inserted." << endl;
            }
        }
    }
    bookStream.close();
}

void Librarian::buildPatrons(string fileName) {
    ifstream patronStream(fileName);
    int patronCode;
    string firstName;
    string lastName;
    while (!patronStream.eof()) {
        patronStream >> patronCode;
        if (!patronStream.eof()) {
            patronStream >> lastName;
            patronStream >> firstName;
            Patron *newPatron = new Patron(patronCode, firstName, lastName);
            Lib->addPatron(newPatron);
        }
    }
    patronStream.close();

}

void Librarian::buildTransactions(string inFile) {
    ifstream transStream(inFile);
    char transCode;
    while (!transStream.eof()) {
        transStream >> transCode;
        if (!transStream.eof()) {
            Transaction* trans = makeTrans->createTrans(transCode);
            if (trans != nullptr) {
                transStream.get();
                trans->setTransaction(transStream);
                transactionQueue.push_back(trans);
            }
            else {
                transStream.ignore(INT_MAX, '\n');
            }
        }
    }
    transStream.close();
}

// fills a vector with transaction objects to be executed
void Librarian::addToQueue(Transaction* passedTrans) {
    transactionQueue.push_back(passedTrans);
}

// Dequeues the list and calls execute() on each transaction 
void Librarian::executeTransactions() {
    vector<Transaction*>::iterator iter;
    for (iter = transactionQueue.begin(); iter < transactionQueue.end(); iter++) {
        (*iter)->execute(Lib);
    }
    transactionQueue.empty();
}
