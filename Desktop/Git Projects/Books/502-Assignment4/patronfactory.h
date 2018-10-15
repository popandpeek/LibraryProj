/******************************************************************************
 * Ben Pittman
 * CS 502A Winter 2017
 * HW 4
 * patronfactory.h
 * An object for creating patrons based on input from a patronFileReader
 ******************************************************************************/

#pragma once

class Library;
class Patron;

class PatronFactory {
public:
   PatronFactory();
   ~PatronFactory();

   // PatronFactory(const PatronFactory&);
   // PatronFactory & operator=(const PatronFactory&);
   
   bool addPatron(Patron*);
   
private:
   Library *lib;
   
};
