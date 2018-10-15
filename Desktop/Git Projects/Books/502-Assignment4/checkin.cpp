/****************************************************************************
* Ben Pittman
* CS 502A Winter 2017
* HW 4
* checkin.cpp
* Check-In instructs the library to execute its function for checking-in
* a library item. The constructor instantiates a pointer to a LibItem
* containing info for the item to be checked-in, as well as a Patron object
* containing the info for the patron checking-in the item.
*
* Features:
*   - setTransaction(), virtual function sets the data members for the
*     check-in
*	- execute(), virtual method to instruct the library to check-in a
*     library item
*****************************************************************************/

#include "checkin.h"
#include "patron.h"
#include "libitemfactory.h"
#include "library.h"

CheckIn::CheckIn() { }

CheckIn::~CheckIn() { 
    delete tempItem;
    delete tempPatron;
}

void CheckIn::setTransaction(ifstream& inFile) {
    inFile >> tempPatronID;
    tempPatron = new Patron(tempPatronID);
    char itemCode, bookCode;
    inFile >> itemCode;
    inFile >> bookCode;
    inFile.get();
    LibItemFactory *makeItem = new LibItemFactory();
    tempItem = makeItem->create(itemCode);
    if (tempItem != nullptr) {
        tempItem->setPartialData(inFile);
    }
    delete makeItem;
    makeItem = nullptr;
}

// Method that performs the check-in
void CheckIn::execute(Library* passedLibrary) {
    bool success = false;
    Patron* newTempPatron = passedLibrary->findPatron(tempPatron);
    LibItem* newTempLibItem = passedLibrary->getLibItem(tempItem);
    if (newTempPatron != nullptr) {
        if (newTempLibItem != nullptr) {
            success = newTempPatron->returnLibItem(newTempLibItem);
            if (success && newTempLibItem->getFormat() == 'H') {
                newTempLibItem->incrementAvailableInventory();
                newTempLibItem->removePatronFromList(newTempPatron);
            }
            else {
                cout << "Item has not been checked out." << endl;
            }
        }
        else {
            cout << "Item is not in our library." << endl;
        }
    }
    else {
        cout << "Patron not a member of our library." << endl;
    }
    newTempLibItem = nullptr;
    newTempPatron = nullptr;
}