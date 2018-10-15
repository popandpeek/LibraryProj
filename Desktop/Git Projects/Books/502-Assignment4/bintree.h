/******************************************************************************
* Ben Pittman
* CS502A Winter 2017
* Assignment 4
* bintree.h
* This file contains our data structure and operations on the data structure, 
* a binary search tree.  We store a pointer to a LibItem object in each node, 
* as well as pointer to each nodes left and right children, if any.
*
******************************************************************************/

#pragma once

#include <iostream>
#include<string>
#include "libitem.h"

// class LibItem;

class BinTree {
    /**************************************************************************
    * operator<<
    * Preconditions:
    * Postconditions: Displays the tree nodes using in order traversal
    */
    friend ostream& operator<< (ostream&, BinTree&);

public:
    /**************************************************************************
    * constructor
    * Preconditions: 
    * Postconditions: Instantiates an empty tree
    */
    BinTree();

    /**************************************************************************
    * copy constructor
    * Preconditions:
    * Postconditions: Instantiates a tree that is a copy of the passed tree
    */
    // BinTree(const BinTree&);

    /**************************************************************************
    * destructor
    * Preconditions:
    * Postconditions: Calls makeEmpty to remove tree nodes
    */
    ~BinTree();

    /**************************************************************************
    * isEmpty()
    * Preconditions:
    * Postconditions: returns true if tree root is nullptr, false otherwise
    */
    bool isEmpty() const;

    /**************************************************************************
    * makeEmpty()
    * Preconditions:
    * Postconditions: Calling object tree nodes are deleted
    */
    void makeEmpty();

    /**************************************************************************
    * operator=
    * Preconditions:
    * Postconditions: Ensures that calling tree isn't initialized, deletes if
    * necessary, then assigns a copy of the passed tree to the calling object
    */
    // BinTree& operator=(const BinTree&);

    /**************************************************************************
    * operator==
    * Preconditions:
    * Postconditions: Returns true of calling and passed object are the same
    */
    bool operator==(const BinTree&) const;

    /**************************************************************************
    * operator!=
    * Preconditions:
    * Postconditions: Returns true if calling and passed object aren't the same
    */
    bool operator!=(const BinTree&) const;

    /**************************************************************************
    * insert()
    * Preconditions:
    * Postconditions: Inserts a LibItem object into the tree
    */
    bool insert(LibItem*);

    /**************************************************************************
    * remove
    * Preconditions:
    * Postconditions: Calls findNode() function to find, and return, tree
    * node holding object previous to object to remove (or root if targeted), 
    * removes target object and moves next smallest node to the tree node 
    * location; handles subtrees and children as appropriate/specified. 
    * Returns true if found and removed.
    */
    bool remove(const LibItem&, LibItem*&);

    /**************************************************************************
    * retrieve()
    * Preconditions: 
    * Postconditions: Tries to retrieve a pointer to a tree node that contains 
    * the LibItem object "key", returns true of found, false if not.
    */
    bool retrieve(const LibItem&, LibItem*&) const;

    /**************************************************************************
    * displaySideways()
    * Preconditions:
    * Postconditions: Displays the binary tree sideways
    */
    // void displaySideways() const;

    /**************************************************************************
    * getHeight()
    * Preconditions:
    * Postconditions: Returns an int representing the depth of the lowest leaf
    */
    // int getHeight(const LibItem&) const;

    /**************************************************************************
    * bstreeToArray()
    * Preconditions: Assume statically allocated array of 100 nullptr's
    * Postconditions: Fills an array with the tree node data pointers by using
    * the inorderHelper() function
    */
    void bstreeToArray(LibItem* []);

    /**************************************************************************
    * arrayToBSTree()
    * Preconditions: Assumes array parameter is sorted
    * Postconditions:Builds a balanced BinTree from a sorted array of LibItem*
    * leaving the array illed with nullptr's
    */
    void arrayToBSTree(LibItem* []);

    /**************************************************************************
    * printTree()
    * Preconditions:
    * Postconditions: Calls private helper function printInOrder() to write
    * tree node data values to an output stream object
    */
    void printTree(ostream&);

private:
    /**************************************************************************
    * Private data members
    * data variable - this is a pointer used to store a node data object and 
    *                 its underlying data (a string).
    * left and right variables - These are pointers to store children of a 
    *                            node - the Nodes with pointers to the 
    *                            objects whose underlying data goes
    *                            before or after the parent node.
    * root variable - this is a pointer to store the location of the root
                      of the tree data structure
    */
    struct Node {
        LibItem* data;
        Node* left;
        Node* right;
    };
    Node* root;

    /**************************************************************************
    * copyTree() - Helper function for copy constructor and operator=,
    * creates a copy of the passed tree and returns a pointer to its root
    */
    // Node* copyTree(Node*);

    /**************************************************************************
    * deleteTree() - private helper function for makeEmpty()
    */
    void deleteTree(Node*&);

    /**************************************************************************
    * insertHelper() - private helper function for insert()
    */
    bool insertHelper(Node*&, LibItem*);

    /**************************************************************************
    * equalityTest() - private helper function for operator==
    */
    bool equalityTest(const Node*, const Node*) const;

    /**************************************************************************
    * retrieveHelper() - private helper function for retrieve
    */
    LibItem* retrieveHelper(const LibItem &key, Node *root) const;

    /**************************************************************************
    * findNodePrev() helper function for remove(), returns
    * node previous to the one to remove(), or the root if it is target node
    */
    Node* findNodePrev(Node*, const LibItem&) const;

    /**************************************************************************
    * findMax() - private helper function for remove(), finds the largest
    * node of the left subtree of the node to remove
    */
    Node* findMax(Node*&, LibItem*&);

    /**************************************************************************
    * sideways() - Provided helper function to display trees to screen sideways
    */
    // void sideways(Node*, int) const;

    /**************************************************************************
    * getHeightHelper() - helper function for getHeight() function
    */
    // int getHeightHelper(Node*) const;

    /**************************************************************************
    * findNode() - helper function for getHeight() function
    */
    Node* findNode(Node *rt, const LibItem &key) const;

    /**************************************************************************
    * fillArray() - private helper function for bstreeToArray()
    */
    void fillArray(Node*&, LibItem*[], int&);

    /**************************************************************************
    * countArrayElements() - helper function for arrayToBSTree() function to 
    * count array elements
    */
    int countArrayElements(LibItem *[], int);

    /**************************************************************************
    * buildAndDeleteFromArray() - helper function for arryToBSTree() function 
    * to build tree and remove LibItem ptrs from array and aplce in order in
    * tree.
    */
    Node* buildAndDeleteFromArray(LibItem*[], int, int);

    /**************************************************************************
    * printInOrder() - private helper function for printTree()
    */
    void printInOrder(ostream&, Node*) const;
};