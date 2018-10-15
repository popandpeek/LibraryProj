/****************************************************************************
* Ben Pittman - David Nixon - Mike Chavez - Rizky Ramdhani
* CS 502A Winter 2017
* HW 4
* hashtable.h
* Abstract Class Template that provides the functionality of a HashTable
* Features:
*   -Contains accessors for capacity, count
*   -contains()
*   -getKey()
*   -toArray()
*   -insertion and removal
* Implementation:
*   -Uses an array to store elements
*   -array capacity is determined by a Load Factor of 0.5.  Meaning that
*    if the (number of elements / capacity of the array) is greater than 0.5,
*    then the array is resized to a larger capacity and each element is then
*    reinserted / rehashed into the larger array.
*   -Capacity is always a prime number to reduce the frequency collision 
*    during insertion.
*   -Collision is handled by open addressing, meaning if the index of the
*    array is already occupied by an element, then the next available index
*    is used to insert the element.
*   -Index position is determined by hash(), which is a pure virtual function.
*    All instantiable subclasses of HashTable must implement its own hash().
****************************************************************************/

#pragma once

#include "object.h"

//factor to decide whether internal array needs to be resized.
static const double LOAD_FACTOR = 0.5;

class HashTable {

public:
    HashTable();  //default Constructor
    HashTable(const HashTable &other);  //copy constructor
    ~HashTable();  //destructor

    HashTable& operator=(const HashTable &other);  //assignment operator    

    //ACCESSORS
    int getCapacity() const;  //return capacity of the HashTable
    int getCount() const;  //return the number of elements in the HashTable

    //returns whether element is inside the HashTable
    bool contains(const Object &) const;  

    //returns object in HashTable that matches the key passed in the argument
    virtual Object *  getKey(Object *) const;

    Object * toArray() const;  //returns the elements in HashTable in an array

    //MUTATORS
    bool insert(const Object& item);  //Adds an item into the HashTable
    bool remove(const Object& item);  //Remove item from the HashTable

protected:
    Object *arr;  //array that stores the elements
    int capacity;  //capacity of arr
    int count;  //total elements in arr

    //pure virtual function
    //returns the index position in arr to be used for object insertion
    int virtual hash(const Object &item) const;  

    void resize(int n); //resizes the array and rehash
    int getNextCapacity();  //get the next valid capacity to resize array
};
