/******************************************************************************
* Ben Pittman
* CS 502A Winter 2017
* HW 4
* patron.h
* ADT for patrons to interact with our Library, check-out and
* return books, etc.  Data members include person defining attributes and
* a list that holds a LibItem and a bool to let us know if it is
* currently checked out (or previously checked out).
******************************************************************************/

#pragma once

#include <string>
#include <list>
#include "libitem.h"
#include "checkoutrecord.h"
#include "transaction.h"

using namespace std;

class Patron {
public:
    Patron();
    Patron(int);
    Patron(int ID, string firstName, string lastName);
    ~Patron();

    bool operator==(const Patron& other) const;
    bool operator!=(const Patron& other) const;

    //MUTATORS
    bool setFirstName(string firstName);
    bool setLastName(string lastName);
    bool addToHistory(LibItem*);
    bool returnLibItem(LibItem*);


    //ACCESSORS
    int getPatronID() const;
    string getFirstName() const;
    string getLastName() const;
    int getHashCode() const;
    bool isCheckedOut(const LibItem&) const;
    bool hasBeenCheckedOut(const LibItem&) const;

    friend ostream& operator<<(ostream&, const Patron&);

protected:
    // data members of a patron
    int patronID;
    string firstName;
    string lastName;

    // list of structs defined above
    list<CheckOutRecord> history;
    
    void printPatronHistory(ostream&) const;
};

