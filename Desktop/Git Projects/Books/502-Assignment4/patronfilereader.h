/******************************************************************************
* Ben Pittman - David Nixon - Mike Chavez - Rizky Ramdhani
* CS 502A Winter 2017
* HW 4
* patronfilereader.h
* Instatiates a file reader object for instantiating Patron objects in the
* Library.
******************************************************************************/

#pragma once

#include<string>
#include<vector>

using namespace std;

class PatronFileReader {

public:
    PatronFileReader(string fileName);
    ~PatronFileReader();
    PatronFileReader(const PatronFileReader&);
    PatronFileReader& operator=(const PatronFileReader&);

    // returns a pointer to the vector after parsing
    vector<vector<string>>* Parse();
    /* parses input string into smaller strings
    ** and places into 2D vector for processing elsewhere
    */

private:

    string fileName;  //name of file
};