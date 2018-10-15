/****************************************************************************
* Ben Pittman
* CS 502A Winter 2017
* HW 4
* displaypatronhistory.cpp
* DisplayPatronHistory instructs the library to execute its function for
* displaying a given patron's transaction history with the library. The
* constructor instantiates a pointer to a Patron object containing the info
* for the patron whose history will be displayed.
*
* Features:
*   setTransaction(), sets the data members from an input file stream
*   execute(), a method to instruct the library to display a library's
*   data members
*****************************************************************************/

#include <limits.h>
#include "displaypatronhistory.h"
#include "patron.h"
#include "library.h"

DisplayPatronHistory::DisplayPatronHistory() {

}

DisplayPatronHistory::~DisplayPatronHistory() {
    delete tempPatron;
}

void DisplayPatronHistory::setTransaction(ifstream& inFile) {
    inFile >> tempPatronID;
    tempPatron = new Patron(tempPatronID);
    inFile.ignore(INT_MAX, '\n');
}

// displays the patron's history
void DisplayPatronHistory::execute(Library* passedLibrary) {
    Patron* newTempPatron = passedLibrary->findPatron(tempPatron);
    if (newTempPatron != nullptr) {
        cout << *newTempPatron;
    }
}
