/******************************************************************************
* Ben Pittman
* CS 502A Winter 2017
* HW 4
* libitemfactory.cpp
* A class for instantiating derived classes of the LibItem class and returning
* the object for use in the library to store data.
******************************************************************************/

#include "libitemfactory.h"
#include "libitem.h"
#include "childrensbook.h"
#include "fictionbook.h"
#include "periodical.h"

LibItemFactory::LibItemFactory() { }

LibItemFactory::~LibItemFactory() { }

LibItem* LibItemFactory::create(const char libItemType) {
    LibItem* newItem;
    switch (libItemType)
    {
    case 'F': newItem = new FictionBook();
        break;
    case 'Y': newItem = new ChildrensBook();
        break;
    case 'P': newItem = new Periodical();
        break;
    default: newItem = nullptr;
        break;
    }
    return newItem;
}