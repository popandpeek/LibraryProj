/******************************************************************************
* Ben Pittman
* CS 502A Winter 2017
* HW 4
* libitemfilereader.h
* Instatiates a file reader object for instantiating LibItem objects in the
* Library.
******************************************************************************/

#pragma once

#include<string>
#include<vector>

using namespace std;

class LibItemFileReader {

public:
    LibItemFileReader(string);

    ~LibItemFileReader();
    // LibItemFileReader(const LibItemFileReader&);
    // LibItemFileReader& operator=(const LibItemFileReader&);

    // returns a pointer to the vector after parsing
    vector<vector<string>>* Parse();
    /* parses input string into smaller strings
    ** and places into 2D vector for processing elsewhere
    */ 

private:

    string fileName;  //name of file

};
