/******************************************************************************
* Ben Pittman
* CS 502A Winter 2017
* HW 4
* checkoutrecord.cpp
* ADT to store records of items checked-out by Patrons from our library.
* Holds a pointer to a LibItem and a bool for if it is currently checked out
* or previously checked out.
******************************************************************************/

#include "checkoutrecord.h"

CheckOutRecord::CheckOutRecord() { }

CheckOutRecord::CheckOutRecord(LibItem* passedItem) {
    item = passedItem;
    checkedOut = true;
}

bool CheckOutRecord::operator==(const CheckOutRecord& passedItem) const {
    if (*item == *passedItem.item) {
        return true;
    }
    return false;
}

bool CheckOutRecord::operator!=(const CheckOutRecord& passedItem) const {
    return !(operator==(passedItem));
}

void CheckOutRecord::addRecord(LibItem* passedItem) {
    item = passedItem;
    checkedOut = true;
}

CheckOutRecord::~CheckOutRecord() {
    item = nullptr;
}

void CheckOutRecord::noLongerCheckedOut() {
    checkedOut = false;
}

void CheckOutRecord::reCheckOut() {
    checkedOut = true;
}

bool CheckOutRecord::isCheckedOut() const {
    return checkedOut;
}

LibItem* CheckOutRecord::getLibItem() const {
    return item;
}

void CheckOutRecord::deleteItem() {
    item = nullptr;
}