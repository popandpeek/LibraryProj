/******************************************************************************
* Ben Pittman
* CS 502A Winter 2017
* HW 4
* libitemfilereader.cpp
* Instatiates a file reader object for instantiating LibItem objects in the
* Library.
******************************************************************************/

#include "libItemfilereader.h"

LibItemFileReader::LibItemFileReader(string passedFileName) { 
    fileName = passedFileName;
}

LibItemFileReader::~LibItemFileReader() { }

vector<vector<string>>* LibItemFileReader::Parse() {

}