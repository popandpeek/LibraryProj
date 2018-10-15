#/******************************************************************************
* Ben Pittman - David Nixon - Mike Chavez - Rizky Ramdhani
* CS 502A Winter 2017
* HW 4
* transactionfilereader.h
* Instatiates a file reader object for instantiating Command objects to send to
* the Library.
******************************************************************************/

#pragma once

#include<string>
#include<vector>

using namespace std;

class TransactionFileReader {

public:
    TransactionFileReader(string fileName);
    ~TransactionFileReader();
    TransactionFileReader(const TransactionFileReader&);
    TransactionFileReader& operator=(const TransactionFileReader&);

    // returns a pointer to the vector after parsing
    vector<vector<string>>* Parse();
    /* parses input string into smaller strings
    ** and places into 2D vector for processing elsewhere
    */

private:

    // temp storage for file read-in
    string fileName;
};
