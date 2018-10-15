/******************************************************************************
 * Ben Pittman
 * CS 502A Winter 2017
 * HW 4
 * librarian.h
 * The Librarian object is a manager that pulls in the data files, calls the 
 * LibItemFactory to fill our Library with LibItem objects, our PatronDB
 * with Patrons and calls our TransactionFactory to create transactino objects
 * for processing actions in our Library - checking in/out books, displaying
 * a patrons history and displaying the contents of the library.
 *****************************************************************************/

#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include<vector>
#include "library.h"
#include "libitem.h"


using namespace std;

class LibItemFactory;
class TransactionFactory;
class Transaction;

class Librarian {
public:
    Librarian(string, string, string);
    ~Librarian();
   
    void buildLibrary(string);

    void executeTransactions();
   
private:
    Library *Lib;
    LibItemFactory *makeLibItems;
    TransactionFactory *makeTrans;

    vector<Transaction*> transactionQueue;

    void fillLibraryCatalog(string);

    void buildPatrons(string);

    void buildTransactions(string);

    void addToQueue(Transaction*);
};











