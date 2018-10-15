/******************************************************************************
* Ben Pittman
* CS 502A Winter 2017
* HW 4
* libitem.h
* Abstract base class ADT for LibItems in the library.  Data members
* that will be inherited by derived classes are inventory, title and a list of
* pointers to patrons who have a LibItem currently checked out.  Includes get
* set methods for data members.
******************************************************************************/

#pragma once

#include <iostream>
#include <list>
#include <string>
#include <iomanip>

using namespace std;

// forward declaration to avoid circular dependancy issues
class Patron;

class LibItem {

public:
    LibItem();
    LibItem(string, string); 
    virtual ~LibItem();

    //MUTATORS
    virtual void setData(ifstream&) = 0;
    virtual void setPartialData(ifstream&) = 0;
    virtual bool setTitle(string);
    virtual void setYear(int);
    virtual void setLibItemType(char);
    virtual void setAvailableInventory(int);
    virtual void setTotalInventory(int);
    virtual bool incrementAvailableInventory();
    virtual bool decrementAvailableInventory();
    virtual bool insertPatronToList(Patron*);
    virtual bool removePatronFromList(Patron*);
    virtual void setFormat(char);

    //ACCESSORS
    virtual string getTitle() const;
    virtual int getYear() const;
    virtual char getLibItemType() const;
    virtual bool isInList(Patron*) const;
    virtual char getFormat() const;
    bool hasAvailableInventory() const;
    virtual int getAvailableInventory() const;
    virtual int getTotalInventory() const;

    virtual bool operator==(const LibItem&) const = 0;
    virtual bool operator!=(const LibItem&) const = 0;
    virtual bool operator<(const LibItem&) const = 0;
    virtual bool operator>(const LibItem&) const = 0;
    
    virtual void print(ostream&) const = 0;
    virtual void printHistory(ostream&) const = 0;

    friend ostream& operator<<(ostream&, const LibItem&);

protected:
    string title;
    int year;
    char libItemType;
    char format;
    int availableInventory;
    int totalInventory;

    // List of Patrons who currently have a book checked out
    list<Patron*> whoHasOne;

};




