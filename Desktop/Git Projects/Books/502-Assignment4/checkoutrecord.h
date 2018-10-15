/******************************************************************************
* Ben Pittman
* CS 502A Winter 2017
* HW 4
* checkoutrecord.h
* ADT to store records of items checked-out by Patrons from our library.
* Holds a pointer to a LibItem and a bool for if it is currently checked out
* or previously checked out.
******************************************************************************/

#pragma once

#include "libitem.h"

class CheckOutRecord {
public:
    CheckOutRecord();
    CheckOutRecord(LibItem*);
    ~CheckOutRecord();
    bool operator==(const CheckOutRecord&) const;
    bool operator!=(const CheckOutRecord&) const;

    void addRecord(LibItem*);
    void noLongerCheckedOut();
    void reCheckOut();

    bool isCheckedOut() const;

    LibItem* getLibItem() const;

    void deleteItem();

private:
    LibItem * item;
    bool checkedOut;
};
