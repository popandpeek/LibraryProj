/******************************************************************************
* Ben Pittman
* CS 502A Winter 2017
* HW 4
* fictionbook.cpp
* ADT for FictionBooks.  All data members are inherited from the base classes
* Features:
* setData() method for setting the data from a file
* partialSetData() method for setting limited data to search our library and
* complete transactions on LibItem objects.
* print() and printHistory() allow ADT to be printed to console for viewing
* in different circumstances.
******************************************************************************/

#include <fstream>
#include <iostream>
#include "fictionbook.h"

FictionBook::FictionBook() { }

FictionBook::FictionBook(string theTitle, string theFormat, string theAuthor, 
    int theYear, int inventory = 5) : Book(theTitle, theFormat, theAuthor, 
        theYear, inventory) {}

FictionBook::~FictionBook() {}

//MUTATORS
void FictionBook::setData(ifstream &inFile) {
    inFile.get();
    getline(inFile, author, ',');
    inFile.get();
    getline(inFile, title, ',');
    inFile.get();
    inFile >> year;
}

void FictionBook::setPartialData(ifstream &inFile) {
    libItemType = 'F';
    getline(inFile, author, ',');
    inFile.get();
    getline(inFile, title, ',');
}

bool FictionBook::operator==(const LibItem &passedItem) const {
    const FictionBook& aBook = static_cast<const FictionBook&>(passedItem);
    if (title.compare(aBook.getTitle()) == 0 &&
        author.compare(aBook.getAuthor()) == 0) {
        return true;
    }
    return false;
}

bool FictionBook::operator!=(const LibItem &passedItem) const {
    return !(operator==(passedItem));
}

bool FictionBook::operator<(const LibItem &passedItem) const {
    const FictionBook& aBook = static_cast<const FictionBook&>(passedItem);
    if (author < aBook.getAuthor()) {
        return true;
    }
    if (author == aBook.getAuthor()) {
        return (title < aBook.getTitle());
    }
    return false;
}

bool FictionBook::operator>(const LibItem &passedItem) const {
    const FictionBook& aBook = static_cast<const FictionBook&>(passedItem);
    if (author > aBook.getAuthor()) {
        return true;
    }
    if (author == aBook.getAuthor()) {
        return (title > aBook.getTitle());
    }
    return false;
}

void FictionBook::print(ostream& output) const {
    output << getLibItemType() << "  " << getFormat() << "  ";
    output << getAvailableInventory() << "  ";
    output << left << setw(31) << getAuthor();
    output << left << setw(35) << getTitle();
    output << left << setw(25) << getYear();
}

void FictionBook::printHistory(ostream& output) const {
    output << left << setw(31) << getAuthor();
    output << left << setw(35) << getTitle();
    output << left << setw(25) << getYear();
}