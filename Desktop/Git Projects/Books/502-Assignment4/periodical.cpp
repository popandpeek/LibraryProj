/******************************************************************************
* Ben Pittman
* CS 502A Winter 2017
* HW 4
* periodical.cpp
* ADT for Periodicals.  All members but month are inherited from base class
* Features:
* setData() method for setting the data from a file
* partialSetData() method for setting limited data to search our library and
* complete transactions on LibItem objects.
* print() and printHistory() allow ADT to be printed to console for viewing
* in different circumstances.
******************************************************************************/
#include <fstream>
#include <iostream>
#include "periodical.h"

Periodical::Periodical() { availableInventory = 1, totalInventory = 1; }

Periodical::Periodical(string theTitle, string theFormat,
    int theMonth) :
    LibItem(theTitle, theFormat),
    month(theMonth) {}

Periodical::~Periodical() { }

//MUTATORS
void Periodical::setData(ifstream &inFile) {
    inFile.get();
    getline(inFile, title, ',');
    inFile.get();
    inFile >> month;
    inFile >> year;
}

void Periodical::setPartialData(ifstream& inFile) {
    libItemType = 'P';
    inFile >> year;
    inFile.get();
    inFile >> month;
    inFile.get();
    getline(inFile, title, ',');
}

void Periodical::setMonth(int theMonth) {
    month = theMonth;
}

void Periodical::setFormat(char theFormat) {
    format = theFormat;
}

//ACCESSORS
int Periodical::getMonth() const {
    return month;
}

char Periodical::getFormat() const {
    return format;
}

bool Periodical::operator==(const LibItem &passedItem) const {
    const Periodical& aPeriodical = static_cast<const Periodical&>(passedItem);
    if (year == aPeriodical.getYear() && month == aPeriodical.getMonth() &&
        title == aPeriodical.getTitle()) {
        return true;
    }
    return false;
}

bool Periodical::operator!=(const LibItem &passedItem) const {
    return !(operator==(passedItem));
}

bool Periodical::operator<(const LibItem &passedItem) const {
    const Periodical& aPeriodical = static_cast<const Periodical&>(passedItem);
    if (year < aPeriodical.getYear()) {
        return true;
    }
    else if (year == aPeriodical.getYear() && month < aPeriodical.getMonth()) {
        return true;
    }
    else if (year == aPeriodical.getYear() && month == aPeriodical.getMonth() 
        && title < aPeriodical.getTitle()) {
        return true;
    }
    else {
        return false;
    }
}

bool Periodical::operator>(const LibItem &passedItem) const {
    const Periodical& aPeriodical = static_cast<const Periodical&>(passedItem);
    if (year > aPeriodical.getYear()) {
        return true;
    }
    else if (year == aPeriodical.getYear() && month > aPeriodical.getMonth()) {
        return true;
    }
    else if (year == aPeriodical.getYear() && month == aPeriodical.getMonth()
        && title > aPeriodical.getTitle()) {
        return true;
    }
    return false;
}

void Periodical::print(ostream& output) const {
    output << setw(3) << getLibItemType();
    output << setw(3) << getFormat();
    output << getAvailableInventory() << "  ";
    output << getYear() << setw(2) << ",";
    output << setw(4) << getMonth();
    output << setw(30) << getTitle();
}

void Periodical::printHistory(ostream& output) const {
    output << getYear() << setw(2) << ",";
    output << setw(4) << getMonth();
    output << setw(30) << getTitle();
}