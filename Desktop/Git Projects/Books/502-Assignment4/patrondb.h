/******************************************************************************
* Ben Pittman
* CS 502A Winter 2017
* HW 4
* patrondb.h
* Abstract Data Type that represents a collection of Patron objects.
* Features:
*   -Contains accessors for capacity, count
*   -contains()
*   -insertion and removal
* Implementation:
*    Hashes on the Patron ID for inserting into our Patron data structure.
******************************************************************************/

#pragma once

#include "patron.h"

class PatronDB {
public:
    PatronDB(); //default constructor;
    ~PatronDB();  //destructor
    

    //ACCESSORS
    Patron* getPatron(int) const;

    //return capacity of the HashTable
    int getCapacity() const;  

    //return the number of elements in the HashTable
    int getCount() const;  

    //returns whether element is inside the HashTable
    bool contains(const Patron&) const;

    //MUTATORS
    bool insertPatron(Patron*);
    
    bool removePatron(const Patron&);

private:
    Patron **arr;  //array that stores the elements, our hash table
    int capacity;  //capacity of arr
    int count;  //total elements in arr'
};
