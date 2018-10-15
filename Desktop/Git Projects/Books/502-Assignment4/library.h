/******************************************************************************
* Ben Pittman
* CS 502A Winter 2017
* HW 4
* library.h
* An ADT that holds catalogs of LibItems and a database of patrons.  
*******************************************************************************/

#pragma once

#include <string>

class LibItem;
class FictionBook;
class ChildrensBook;
class Periodical;
class Patron;
class Catalog;
class PatronDB;

class Library {
public:
   Library();
   ~Library();

   // display the catalog, sorted as proscribed
   void displayAll();

   void displayCatalog(char);
   
   // gives us a pointer to the library item from the title:
   LibItem* getLibItem(LibItem*);
   
   // gives us a pointer to the Patron from her ID, or a nullptr:
   Patron* findPatron(Patron*);

   bool hasPatron(Patron*);
   
   //// to add a new patron. (this checks to make sure there isn't one there already.)
   void addPatron(Patron*);

   void addLibItem(LibItem*);
   
private:

    Catalog *catalogOfItems;
    PatronDB *patronDB;

    // initializeCatalog() is called by the constructor
    void initializeCatalog();

    void initializePatronDB();

};










