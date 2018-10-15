/******************************************************************************
* Ben Pittman
* CS 502A Winter 2017
* HW 4
* library.cpp
* An ADT that holds catalogs of LibItems and a database of patrons.
*******************************************************************************/

#include "library.h"
#include "libitem.h"
#include "fictionbook.h"
#include "childrensbook.h"
#include "periodical.h"
#include "patron.h"
#include "catalog.h"
#include "patrondb.h"

Library::Library() {
    initializeCatalog();
    initializePatronDB();
}

Library::~Library() {
    delete catalogOfItems;
    delete patronDB;
    catalogOfItems = nullptr;
    patronDB = nullptr;
}
void Library::addLibItem(LibItem* passedItem) {
    catalogOfItems->addItem(passedItem);
}

void Library::addPatron(Patron* nPatron) {
    patronDB->insertPatron(nPatron);
}

void Library::initializeCatalog() {
    catalogOfItems = new Catalog();
}

void Library::initializePatronDB() {
    patronDB = new PatronDB();
}

Patron* Library::findPatron(Patron* passedPatron) {
    if (hasPatron(passedPatron)) {
        return patronDB->getPatron(passedPatron->getPatronID());
    }
    else {
        return nullptr;
    }
}

LibItem* Library::getLibItem(LibItem* passedLibItem) {
    return catalogOfItems->getLibItem(passedLibItem);
}

void Library::displayAll() {
    catalogOfItems->printAll();
}

void Library::displayCatalog(char libItemType) {
    catalogOfItems->printCatalog(libItemType);
}

bool Library::hasPatron(Patron* passedPatron) {
    return (patronDB->contains(*passedPatron));
}