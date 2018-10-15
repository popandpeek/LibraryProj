/****************************************************************************
* Ben Pittman
* CS 502A Winter 2017
* HW 4
* main.cpp
* Instantiates a Library object and calls function to implement library
* functionality by reading in a transaction file.
*****************************************************************************/

#include "librarian.h"

int main() {
    Librarian *librarian = new Librarian("data4books.txt", 
        "data4patrons.txt", "data4commands.txt");
    
    librarian->executeTransactions();

    return 0;
}

