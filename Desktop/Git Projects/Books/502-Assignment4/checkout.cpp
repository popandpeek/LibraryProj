/****************************************************************************
* Ben Pittman
* CS 502A Winter 2017
* HW 4
* checkout.cpp
* Check-Out instructs the library to execute its function for checking-out
* a library item. The constructor instantiates a pointer to a LibItem
* containing info for the item to be checked-out, as well as a Patron object
* containing the info for the patron checking-out the item.
*
* Features:
*   - setTransaction(), virtual function sets the data members for the
*     check-out
*	- execute(), virtual method to instruct the library to check-out a
*     library item
*****************************************************************************/

#include "checkout.h"
#include "patron.h"
#include "library.h"
#include "libitemfactory.h"

using namespace std;

CheckOut::CheckOut() { }

CheckOut::~CheckOut() { 
    delete tempItem;
    delete tempPatron;
}

void CheckOut::setTransaction(ifstream& inFile) {
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

    // Performs the transaction
void CheckOut::execute(Library* passedLibrary) {
    LibItem* newTempLibItem = passedLibrary->getLibItem(tempItem);
    Patron* newTempPatron = passedLibrary->findPatron(tempPatron);
    if (newTempLibItem != nullptr && newTempPatron != nullptr) {
        if (newTempLibItem->getFormat() != 'H' || 
            !(newTempLibItem->hasAvailableInventory())) {
            cout << "Item is not currently available." << endl;
        }
        else {
            newTempLibItem->decrementAvailableInventory();
            newTempLibItem->insertPatronToList(newTempPatron);
            newTempPatron->addToHistory(newTempLibItem);
        }
    }
    newTempLibItem = nullptr;
    newTempPatron = nullptr;
}
