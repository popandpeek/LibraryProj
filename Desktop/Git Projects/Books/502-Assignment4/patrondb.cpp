/******************************************************************************
* Ben Pittman 
* CS 502A Winter 2017
* HW 4
* patrondb.cpp
* Abstract Data Type that represents a collection of Patron objects.
* Features:
*   -Contains accessors for capacity, count
*   -contains()
*   -insertion and removal
* Implementation:
*    Hashes on the Patron ID for inserting into our Patron data structure.
******************************************************************************/

#include "patrondb.h"

static const int ARRSIZE = 10000;

PatronDB::PatronDB() {
    capacity = ARRSIZE;
    arr = new Patron*[capacity];
    for (int i = 0; i < capacity; i++) {
        arr[i] = nullptr;
    }
}

PatronDB::~PatronDB() {
    for (int i = 0; i < capacity; i++) {
        if (arr[i] != nullptr) {
            delete arr[i];
            arr[i] = nullptr;
        }
    }
    delete[] arr;
    arr = nullptr;
}

//ACCESSORS
Patron* PatronDB::getPatron(int code) const {
    return arr[code];
}

//return capacity of the HashTable
int PatronDB::getCapacity() const {
    return capacity;
}

//return the number of elements in the HashTable
int PatronDB::getCount() const {
    return count;
}

//returns whether element is inside the HashTable
bool PatronDB::contains(const Patron& passedPatron) const {
   return (arr[passedPatron.getHashCode()] != nullptr);
}

//MUTATORS
bool PatronDB::insertPatron(Patron* passedPatron) {
    if (!contains(*passedPatron)) {
        arr[(*passedPatron).getHashCode()] = passedPatron;
        count++;
        //cout << *arr[(*passedPatron).getHashCode()] << endl;
        return true;
    }
    cout << "Patron not inserted: ";
    cout << "Memory in database is occupied, possible duplicate PatronID.";
    return false;
}

bool PatronDB::removePatron(const Patron& passedPatron) {
    if (contains(passedPatron)) {
        arr[passedPatron.getHashCode()] = nullptr;
        count--;
        return true;
    }
    cout << "Patron not removed, Patron not in database.";
    return false;
}