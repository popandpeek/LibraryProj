/******************************************************************************
* Ben Pittman - David Nixon - Mike Chavez - Rizky Ramdhani
* CS 502A Winter 2017
* HW 4
* libraryviewer.h
* Viewer class for displaying library catalogs, patrons and patron histories
* to the console.  Creates a heap
******************************************************************************/

#pragma once

#include <iostream>
#include "library.h"
#include "catalog.h"
#include "patrondb.h"

using namespace std;

class LibraryViewer {
public:
    LibraryViewer();
    ~LibraryViewer();
    LibraryViewer(const LibraryViewer&);
    LibraryViewer& operator=(const LibraryViewer&);

    // Displays library catolog to the console
    void displayCatalog(Catalog*);
    /* heap = catalog->toArray()
    ** sort heap
    ** heap->deleteMin
    ** cout one LibItem per line
    */

    // Displays one patrons history to the console
    void displayPatronHistory(Patron*);
    /* cout one patrons history 
    ** One LibItem per line
    ** denotes whether a LibItem is currently checked out
    */
private:
    Library* Lib;

};
