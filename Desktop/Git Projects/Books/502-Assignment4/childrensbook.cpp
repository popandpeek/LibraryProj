/******************************************************************************
* Ben Pittman
* CS 502A Winter 2017
* HW 4
* childrensbook.cpp
* ADT for ChildrenBooks.  All data members are inherited from the base classes
* Features:
* setData() method for setting the data from a file
* partialSetData() method for setting limited data to search our library and
* complete transactions on LibItem objects.
* print() and printHistory() allow ADT to be printed to console for viewing
* in different circumstances.
******************************************************************************/

#include <fstream>
#include <iostream>
#include "childrensbook.h"

ChildrensBook::ChildrensBook() { }

ChildrensBook::ChildrensBook(string title, string theFormat, string author, 
    int year, int inventory = 5) :
    Book(title, theFormat, author, year, inventory) {}

ChildrensBook::~ChildrensBook() { }

//MUTATORS

void ChildrensBook::setData(ifstream &inFile) {
    inFile.get();
    getline(inFile, author, ',');
    inFile.get();
    getline(inFile, title, ',');
    inFile.get();
    inFile >> year;
}

void ChildrensBook::setPartialData(ifstream& inFile) {
    libItemType = 'Y';
    getline(inFile, title, ',');
    inFile.get();
    getline(inFile, author, ',');
}

bool ChildrensBook::operator==(const LibItem& passedItem) const {
    const ChildrensBook& aBook = static_cast<const ChildrensBook&>(passedItem);
    if (title.compare(aBook.getTitle()) == 0 &&
        author.compare(aBook.getAuthor()) == 0) {
        return true;
    }
    return false;
}

bool ChildrensBook::operator!=(const LibItem& passedItem) const {
    return !(operator==(passedItem));
}

bool ChildrensBook::operator<(const LibItem& passedItem) const {
    const ChildrensBook& aBook = static_cast<const ChildrensBook&>(passedItem);
    if (title < aBook.getTitle()) {
        return true;
    }
    if (title == aBook.getTitle()) {
        return (author < aBook.getAuthor());
    }
    return false;
}

bool ChildrensBook::operator>(const LibItem& passedItem) const {
    const ChildrensBook& aBook = static_cast<const ChildrensBook&>(passedItem);
    if (title > aBook.getTitle()) {
        return true;
    }
    if (title == aBook.getTitle()) {
        return (author > aBook.getAuthor());
    }
    return false;
}

void ChildrensBook::print(ostream& output) const {
    output << getLibItemType() << "  " << getFormat() << "  ";
    output << getAvailableInventory() << "  ";
    output << left << setw(31) << getAuthor();
    output << left << setw(35) << getTitle();
    output << left << setw(25) << getYear();
}

void ChildrensBook::printHistory(ostream& output) const {
    output << left << setw(31) << getAuthor();
    output << left << setw(35) << getTitle();
    output << left << setw(25) << getYear();
}
