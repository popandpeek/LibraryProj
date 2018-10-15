/******************************************************************************
* Ben Pittman
* CS 502A Winter 2017
* HW 4
* patron.cpp
* ADT for patrons to interact with our Library, check-out and
* return books, etc.  Data members include person defining attributes and
* a list that holds a LibItem and a bool to let us know if it is
* currently checked out (or previously checked out).  
******************************************************************************/

#include "patron.h"

/******************************************************************************
* Default constructor
******************************************************************************/
Patron::Patron() { }

Patron::Patron(int passedID) {
    patronID = passedID;
}

/******************************************************************************
* Overloaded constructor
* Takes parameters to instantiate a patron for a library
******************************************************************************/
Patron::Patron(int ID, string theFirstName, string theLastName) {
    patronID = ID;
    firstName = theFirstName;
    lastName = theLastName;
}

Patron::~Patron() {
    for (list<CheckOutRecord>::iterator it = history.begin(); 
        it != history.end(); it++) {
        it->deleteItem();
    }
    firstName.clear();
    lastName.clear();
}

bool Patron::operator==(const Patron &passedPatron) const {
    if (patronID == passedPatron.patronID) {
        return true;
    }
    return false;
}

bool Patron::operator!=(const Patron &passedPatron) const {
    return !(Patron::operator==(passedPatron));
}

//MUTATORS
bool Patron::setFirstName(string theFirstName) {
    if (theFirstName.size() != 0) {
        firstName = theFirstName;
        return true;
    }
    return false;
}

bool Patron::setLastName(string theLastName) {
    if (theLastName.size() != 0) {
        lastName = theLastName;
        return true;
    }
    return false;
}

bool Patron::addToHistory(LibItem *passedItem) {
    if (!history.empty()) {
        list<CheckOutRecord>::iterator iter;
        for (iter = history.begin(); iter != history.end(); ++iter) {
            if (*iter->getLibItem() == *passedItem) {
                iter->reCheckOut();
                return true;
            }
        }
    }
    history.push_back(CheckOutRecord(passedItem));
    return true;
}

bool Patron::returnLibItem(LibItem *passedItem) {
    if (!history.empty()) {
        list<CheckOutRecord>::iterator iter; 
        for (iter = history.begin(); iter != history.end(); ++iter) {
            if (*iter->getLibItem() == *passedItem) {
                iter->noLongerCheckedOut();
                return true;
            }
        }
    }
    return false;
}

//ACCESSORS
int Patron::getPatronID() const {
    return patronID;
}

string Patron::getFirstName() const {
    return firstName;
}

string Patron::getLastName() const {
    return lastName;
}

int Patron::getHashCode() const {
    return patronID;
}

bool Patron::isCheckedOut(const LibItem &passedItem) const {
    for (list<CheckOutRecord>::const_iterator it = history.begin(); 
        it != history.end(); it++) {
        if (*it->getLibItem() == passedItem && it->isCheckedOut()) {
            return true;
        }
    }
    return false;
}

bool Patron::hasBeenCheckedOut(const LibItem &passedItem) const {
    for (list<CheckOutRecord>::const_iterator it = history.begin(); 
        it != history.end(); it++) {
        if (*it->getLibItem() == passedItem && !it->isCheckedOut()) {
            return true;
        }
    }
    return false;
}

void Patron::printPatronHistory(ostream& output) const {
    output << "***" << " PatronID = " << getPatronID();
    output << "  " << getLastName();
    output << ",  " << getFirstName() << endl;
    list<CheckOutRecord>::const_iterator it;
    for (it = history.begin(); it != history.end(); it++) {
        if (it->isCheckedOut()) {
            output << "Checked out: ";
        }
        else {
            output << "Returned:    ";
        }
        LibItem *tempItem = it->getLibItem();
        tempItem->printHistory(output);
        output << endl;
        tempItem = nullptr;
    }
}

ostream& operator<<(ostream &output, const Patron &passedPatron) {
    passedPatron.printPatronHistory(output);
    return output;
}

