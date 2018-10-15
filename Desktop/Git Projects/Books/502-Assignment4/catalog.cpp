/******************************************************************************
* Ben Pittman
* CS 502A Winter 2017
* HW 4
* catalog.cpp
* Data structure to hold our LibItem ADTs.  We use a set to store LibItem's,
* and a comparator function (functor) is included such that we can properly
* sort the set in the proper order.  The functor allows the derived items
* comparison functions to sort the items.  We have 26 sets stored in an array;
* hased into based upon their derived type.  getTypeCode() is our hash function
******************************************************************************/

#include "catalog.h"


static const int LIBITEMTYPES = 26;

Catalog::Catalog() {
    itemCatalog = new set<LibItem*, PtrComp>[LIBITEMTYPES];
}

Catalog::~Catalog() {
    delete[] itemCatalog;
}

bool Catalog::addItem(LibItem* passedItem) {
    int location = getTypeCode(passedItem->getLibItemType());
    if (location >= 0 && location < 26) {
        itemCatalog[location].insert(passedItem);
        return true;
    }
    cout << "Item not inserted, hash value out of range : " << 
        getTypeCode(passedItem->getLibItemType()) << endl;
    return false;
}

int Catalog::getSetCount(char type) {
    int location = getTypeCode(type);
    return itemCatalog[location].size();
}

int Catalog::getTypeCode(char type) {
    return type - 'A';
}

LibItem* Catalog::getLibItem(LibItem* passedItem) {
    if (passedItem != nullptr) {
        char tempChar = passedItem->getLibItemType();
        int tempCode = getTypeCode(tempChar);
        set<LibItem*>::const_iterator iter;
        for (iter = itemCatalog[tempCode].begin();
            iter != itemCatalog[tempCode].end(); iter++) {
            if (**iter == *passedItem) {
                return *iter;
            }
        }
    }
    return nullptr;
}

void Catalog::printCatalog(char passedType) {
    int typeCode = getTypeCode(passedType);
    set<LibItem*>::const_iterator iter;
    for (iter = itemCatalog[typeCode].begin(); 
        iter != itemCatalog[typeCode].end(); iter++) {
        cout << **iter << endl;
    }
}

void Catalog::printAll() {
    for (int i = 0; i < LIBITEMTYPES; i++) {
        if (!itemCatalog[i].empty()) {
            printCatalog(i + 'A');
         }
    }
}