/****************************************************************************
* Ben Pittman
* CS 502A Winter 2017
* HW 4
* displayinventory.cpp
* DisplayInventory instructs the library to execute its function for
* displaying a Library's inventory.
*
* Features:
*   setTransaction(), sets the data members from an input file stream
*   execute(), a method to instruct the library to display a library's
*   data members
*****************************************************************************/

#include "displayinventory.h"
#include "library.h"
#include "patron.h"

DisplayInventory::DisplayInventory() {

}

DisplayInventory::~DisplayInventory() { }

void DisplayInventory::setTransaction(ifstream& inFile) { }

// displays the library's history
void DisplayInventory::execute(Library* passedLibrary) {
    passedLibrary->displayAll();
}
