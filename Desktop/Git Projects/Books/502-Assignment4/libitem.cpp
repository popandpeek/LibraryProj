/******************************************************************************
* Ben Pittman 
* CS 502A Winter 2017
* HW 4
* libitem.cpp
* Abstract base class ADT for LibItems in the library.  Data members
* that will be inherited by derived classes are inventory, title and a list of
* pointers to patrons who have a LibItem currently checked out.  Includes get
* set methods for data members.
******************************************************************************/

#include "libitem.h"
#include "patron.h"

LibItem::LibItem() { }

LibItem::LibItem(string theTitle, string theFormat) {
    title = theTitle;
}

LibItem::~LibItem() {
    list<Patron*>::iterator it;
    for (it = whoHasOne.begin(); it != whoHasOne.end(); ++it) {
        *it = nullptr;
    }
    title.clear();
}

//MUTATORS
bool LibItem::setTitle(string theTitle) {
    if (theTitle.size() != 0) {
        title = theTitle;
        return true;
    }
    return false;
}

void LibItem::setYear(int passedYear) {
    year = passedYear;
}

void LibItem::setLibItemType(char theType) {
    libItemType = theType;
}

// Multiple check-outs of the same LibItem by the same PAtron will result
// in the same Patron in the list multiple times
bool LibItem::insertPatronToList(Patron *p) {
    whoHasOne.push_back(p);
    return true;
}

bool LibItem::removePatronFromList(Patron *p) {
    list<Patron*>::const_iterator it;
    for (it = whoHasOne.begin(); it != whoHasOne.end(); it++) {
        if ((*it)->getPatronID() == p->getPatronID()) {
            whoHasOne.erase(it);
            return true;
        }
    }
    cout << "Patron does not have " << getTitle() << " checked out." << endl;
    return false;
}
void LibItem::setAvailableInventory(int theInventory) {
    availableInventory = theInventory;
}

void LibItem::setTotalInventory(int theInventory) {
    totalInventory = theInventory;
}

bool LibItem::incrementAvailableInventory() {
    if (availableInventory < totalInventory) {
        availableInventory++;
        return true;
    }
    return false;
}

bool LibItem::decrementAvailableInventory() {
    if (availableInventory > 0) {
        availableInventory--;
        return true;
    }
    return false;
}

void LibItem::setFormat(char theFormat) {
    format = theFormat;
}

//ACCESSORS
string LibItem::getTitle() const {
    return title;
}

int LibItem::getYear() const {
    return year;
}

char LibItem::getLibItemType() const {
    return libItemType;
}

char LibItem::getFormat() const {
    return format;
}

bool LibItem::isInList(Patron *p) const {
    list<Patron*>::const_iterator it;
    for (it = whoHasOne.begin(); it != whoHasOne.end(); it++) {
        if ((*it)->getPatronID() == p->getPatronID()) {
            return true;
        }
    }
    return false;
}

bool LibItem::hasAvailableInventory() const {
    if (availableInventory > 0) {
        return true;
    }
    return false;
}

int LibItem::getAvailableInventory() const {
    return availableInventory;
}

int LibItem::getTotalInventory() const {
    return totalInventory;
}

ostream& operator<<(ostream& output, const LibItem &passedItem) {
    passedItem.print(output);
    return output;
}