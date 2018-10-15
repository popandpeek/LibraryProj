/******************************************************************************
* Ben Pittman
* CS 502A Winter 2017
* HW 4
* book.cpp
* Claass to instantiate Book objects.  Title and year are inherited from the
* base class, adds author as a data member.
* set and get author are the only non-virtual methods of this class.
******************************************************************************/

#include "book.h"

Book::Book() { totalInventory = 5, availableInventory = 5;}

Book::Book(string title, string theAuthor, string theFormat, int theYear,
    int inventory) : LibItem::LibItem(title, theFormat) {
    author = theAuthor;
    year = theYear;
}
Book::~Book() {
    author.clear();
}

//MUTATORS
bool Book::setAuthor(string passedAuthor) {
    if (!passedAuthor.empty()) {
        author = passedAuthor;
        return true;
    }
    return false;
}

//ACCESSORS
string Book::getAuthor() const {
    return author;
}
