/****************************************************************************
* Ben Pittman - David Nixon - Mike Chavez - Rizky Ramdhani
* CS 502A Winter 2017
* HW 4
* object.h
* Object class
* A superclass that all classes must inherit from.
* Features:
*   -returns a hash code unique to object.

****************************************************************************/

#pragma once

class Object {
    virtual int getHashCode() const;
};



