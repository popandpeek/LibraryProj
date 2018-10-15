/******************************************************************************
* Ben Pittman
* CS502A Winter 2017
* Assignment 4
* bintree.cpp
* This file contains our data structure and operations on the data structure,
* a binary search tree.  We store a pointer to a LibItem object in each node,
* as well as pointer to each nodes left and right children, if any.
*
******************************************************************************/

#include <iostream>
#include<array>
#include "bintree.h"
#include "libitem.h"

using namespace std;

/******************************************************************************
* constructor
* Preconditions:
* Postconditions: Instantiates an empty tree
*/
BinTree::BinTree() {
    root = nullptr;
}

/******************************************************************************
* copy constructor
* Preconditions:
* Postconditions: Instantiates a tree that is a copy of the passed tree
*/
//BinTree::BinTree(const BinTree &BST) {
//    root = copyTree(BST.root);
//}
//
////  copyTree() a private helper function for operator= and copy constructor
//BinTree::Node* BinTree::copyTree(Node *rt) {
//    Node *newNode = nullptr;
//    if (rt == nullptr) {
//        return nullptr;
//    }
//    newNode = new Node;
//    newNode->data = new LibItem(*rt->data);
//    newNode->left = copyTree(rt->left);
//    newNode->right = copyTree(rt->right);
//    return newNode;
//}

/******************************************************************************
* destructor
* Preconditions:
* Postconditions: Calls makeEmpty to remove tree nodes
*/
BinTree::~BinTree() {
    if (root != nullptr) {
        makeEmpty();
    }
}

/******************************************************************************
* isEmpty()
* Preconditions:
* Postconditions: returns true if tree root is nullptr, false otherwise
*/
bool BinTree::isEmpty() const {
    if (root == nullptr) {
        return true;
    }
    return false;
}

/******************************************************************************
* makeEmpty()
* Preconditions:
* Postconditions: Calling object tree nodes are deleted
*/
void BinTree::makeEmpty() {
    if (root == nullptr) { 
        return;
    }
    deleteTree(root);
}

// private helper function for makeEmpty()
void BinTree::deleteTree(Node*& rt) {
    if (rt != nullptr) {
        deleteTree(rt->left);
        deleteTree(rt->right);
        delete rt->data;
        rt->data = nullptr;
        delete rt;
        rt = nullptr;
    }
}

/******************************************************************************
* operator=
* Preconditions:
* Postconditions: Ensures that calling tree isn't initialized, deletes if
* necessary, then assigns a copy of the passed tree to the calling object
* by calling private copyTree() function (above with copy constructor).
*/
//BinTree& BinTree::operator=(const BinTree &BST) {
//    if (*this != BST) {
//        if (this != nullptr) {
//            makeEmpty();
//        }
//        this->root = copyTree(BST.root);
//    }
//    return *this;
//}

/******************************************************************************
* operator==
* Preconditions:
* Postconditions: Returns true if calling and passed object are the same
*/
bool BinTree::operator==(const BinTree &BST) const {
    return equalityTest(root, BST.root);
}

// equalityTest() a private helper function for operator== 
bool BinTree::equalityTest(const Node *root1, const Node *root2) const {
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    }
    if (root1 != nullptr && root2 != nullptr) {
        return ((*root1->data == *root2->data) &&
            equalityTest(root1->left, root2->left) &&
            equalityTest(root1->right, root2->right));
    }
    return false;
}

/******************************************************************************
* operator!=
* Preconditions:
* Postconditions: Returns true if calling and passed object aren't the same
*/
bool BinTree::operator!=(const BinTree &BST) const {
    return !(*this == BST);
}

/******************************************************************************
* insert()
* Preconditions:
* Postconditions: Calls private function insertHelper() to insert a
* Node object into the tree
*/
bool BinTree::insert(LibItem *passedNode) {
    return insertHelper(root, passedNode);
}

// insertHelper() private helper function for insert()
bool BinTree::insertHelper(Node *&rt, LibItem *passedNode) {
    if (rt == nullptr) {
        rt = new Node;
        rt->data = passedNode;
        rt->left = nullptr;
        rt->right = nullptr;
        return true;
    }
    else if (*passedNode < *rt->data) {
        return insertHelper(rt->left, passedNode);
    }
    else if (*passedNode > *rt->data) {
        return insertHelper(rt->right, passedNode);
    }
    else {
        return false;
    }
}

/******************************************************************************
* remove()
* Preconditions:
* Postconditions: Calls findNodePrev() function to find, and return, tree
* node holding object previous to object to remove (or root if targeted),
* removes target object and moves next smallest node to the tree node
* location; handles subtrees and children as appropriate/specified.
* Returns true if found and removed.
*/
bool BinTree::remove(const LibItem &key, LibItem *&nd) {
    // find node to delete
    // do simple bubble up cases
    // if not simple, find max of left sub-tree
    // swap with value to remove
    // delete unnecessary node (if we can't do in helper functions)
    Node *nodeToDelete;
    Node *prevNodeToDelete = findNodePrev(root, key);
    if (prevNodeToDelete == nullptr) {
        nd = nullptr;
        return false;
    }
    // handles removing the root
    else if (*prevNodeToDelete->data == key) {
        Node *nextSmallest = findMax(prevNodeToDelete->left, nd);
        nd = prevNodeToDelete->data;
        prevNodeToDelete->data = nextSmallest->data;
        nextSmallest->data = nullptr;
        delete nextSmallest;
        nextSmallest = nullptr;
        return true; 
    }
    else {
        nodeToDelete = *prevNodeToDelete->left->data == key ? 
            prevNodeToDelete->left : prevNodeToDelete->right;
        nd = nodeToDelete->data;
        // handles removing node with no children
        if (nodeToDelete->left == nullptr && nodeToDelete->right == nullptr) {
            if (*prevNodeToDelete->left->data == key) {
                prevNodeToDelete->left = nullptr;
            }
            else {
                prevNodeToDelete->right = nullptr;
            }
            prevNodeToDelete = nullptr;
            return true;
        }
        // handles removing node with one child
        else if (nodeToDelete->left == nullptr || 
            nodeToDelete->right == nullptr) {
            Node *tmp;
            if (nodeToDelete->left == nullptr) {
                tmp = nodeToDelete->right;
                nodeToDelete->right = nullptr;
            }
            else {
                tmp = nodeToDelete->left;
                nodeToDelete->left = nullptr;
            }
            nodeToDelete->data = tmp->data;
            delete tmp;
            tmp = nullptr;
            return true;
        }
        else {
            // handles removing node with two children
            Node *nextSmallest = findMax(nodeToDelete->left, nd);
            nodeToDelete->data = nextSmallest->data;
            nextSmallest->data = nd;
            delete nextSmallest;
            nextSmallest = nullptr;
            return true;
        }
    }
}

// findNodePrev() helper function for remove() and getHeight(), returns node
// previous to the one to remove(), or the root if it is to be removed
BinTree::Node* BinTree::findNodePrev(Node *rt, const LibItem &key) const {
    if (rt == nullptr) {
        return nullptr;
    }
    else if (key == *root->data) {
        return root;
    }
    else if (rt->left != nullptr && key == *rt->left->data) {
        return rt;
    }
    else if (rt->right != nullptr && key == *rt->right->data) {
        return rt;
    }
    else if (key < *rt->data) {
        return findNodePrev(rt->left, key);
    }
    else {
        return findNodePrev(rt->right, key);
    }
}

// private helper function for remove()
BinTree::Node* BinTree::findMax(Node *&rt, LibItem *&nd) {
    if (rt == nullptr) {
        return rt;
    }
    if (rt->right == nullptr) {
        Node *temp = rt;
        rt = rt->left;
        return temp;
    }
    else {
        return findMax(rt->right, nd);
    }
}
/******************************************************************************
* retrieve()
* Preconditions:
* Postconditions: Calls helper function on the root of the calling tree to
* retrieve the passed key value in the tree; true if present, false if not
*/
bool BinTree::retrieve(const LibItem &key, LibItem *&nd) const {
    nd = retrieveHelper(key, root);
    if (nd == nullptr) {
        return false;
    }
    return true;
}

// private helper function for retrieve()
LibItem* BinTree::retrieveHelper(const LibItem &key, Node *rt) const {
    if (rt == nullptr) {
        return nullptr;
    }
    else if (key == *rt->data) {
        return rt->data;
    }
    else if (key < *rt->data) {
        return retrieveHelper(key, rt->left);
    }
    else {
        return retrieveHelper(key, rt->right);
    }
}

/******************************************************************************
* displaySideways()
* Preconditions:
* Postconditions: Displays the binary tree sideways
*/
//void BinTree::displaySideways() const {
//    sideways(root, 0);
//}
//
//// private helper function for displaySideways()
//void BinTree::sideways(Node *current, int level) const {
//    if (current != nullptr) {
//        level++;
//        sideways(current->right, level);
//
//        // indent for readability, 4 spaces per depth level 
//        for (int i = level; i >= 0; i--) {
//            cout << "    ";
//        }
//
//        cout << *current->data << endl;   // display information of object
//        sideways(current->left, level);
//    }
//}

/******************************************************************************
* getHeight()
* Preconditions:
* Postconditions: Finds the height of the passed value in the calling 
* object, returns one if it is a leaf, 0 if not in tree
*/
//int BinTree::getHeight(const LibItem &key) const {
//    // findNode() definition located above with remove() 
//    BinTree::Node *rootNode = findNode(root, key); 
//    if (rootNode != nullptr) {
//        return getHeightHelper(rootNode); 
//    }
//    return 0;
//}
//
//// private helper function for getHeight()
//int BinTree::getHeightHelper(Node* rt) const {
//    if (rt == nullptr) {
//        return 0;
//    }
//    int leftHeight = 1 + getHeightHelper(rt->left);
//    int rightHeight = 1 + getHeightHelper(rt->right);
//
//    if (leftHeight > rightHeight) {
//        return leftHeight;
//    }
//    else {
//        return rightHeight;
//    }
//
//}

// findNode() helper function for getHeight(), searches entire tree for key 
// and returns node holding key or nullptr if not present
BinTree::Node* BinTree::findNode(Node *rt, const LibItem &key) const {
    if (rt == nullptr || *rt->data == key) {
        return rt;
    }
    Node* found = nullptr;
    // searches left sub-tree, returns if found
    if (rt->left != nullptr && (found = findNode(rt->left, key))) {
        return found;
    }
    // searches right subtree, returns node if found
    if (rt->right != nullptr) {
        return findNode(rt->right, key);
    }
    return nullptr;
}

/******************************************************************************
* bstreeToArray()
* Preconditions: Assume statically allocated array of 100 nullptr's
* Postconditions: Fills an array with the tree node data pointers by using
* the fillArray() function and leaves the calling tree empty
*/
void BinTree::bstreeToArray(LibItem *bstArray[]) {
    if (root == nullptr) {
        return;
    }
    int *count = new int;
    *count = 0;
    fillArray(root, bstArray, *count);
    delete count;
    deleteTree(root);
}

// private helper function for bstreeToArray()
void BinTree::fillArray(Node *&rn, LibItem *bstArray[], int &count) {
    if (rn == nullptr) {
        return;
    }
    if (rn->left != nullptr) {
        fillArray(rn->left, bstArray, count);
    }
    bstArray[count] = rn->data;
    rn->data = nullptr;
    count++;
   if (rn->right != nullptr) {
        fillArray(rn->right, bstArray, count);
   }
 }

/******************************************************************************
* arrayToBSTree()
* Preconditions: Assumes array parameter is sorted
* Postconditions:Builds a balanced BinTree from a sorted array of LibItem*
* leaving the array filled with nullptr's
*/
void BinTree::arrayToBSTree(LibItem *bstArray[]) {
    int elementCount = countArrayElements(bstArray, 0);
    if (elementCount == 0) {
        return;
    }
    root = buildAndDeleteFromArray(bstArray, 0, elementCount - 1);
}

// private helper function to count array elements
int BinTree::countArrayElements(LibItem *bstArray[], int count) {
    if (bstArray[count] != nullptr) {
        return countArrayElements(bstArray, count + 1);
    }
    return count;
}

// private helper function to build tree and delete array elements
BinTree::Node* BinTree::buildAndDeleteFromArray(LibItem *bstArray[], 
    int low, int high) {
    if (low > high) {
        return nullptr;
    }
    int midLoc = (low + high) / 2;
    Node *newNode = new Node;
    newNode->data = bstArray[midLoc];
    newNode->left = nullptr;
    newNode->right = nullptr;
    bstArray[midLoc] = nullptr;
    newNode->left = buildAndDeleteFromArray(bstArray, low, midLoc - 1);
    newNode->right = buildAndDeleteFromArray(bstArray, midLoc + 1, high);
    return newNode;
}

/******************************************************************************
* operator<<
* Preconditions:
* Postconditions: Displays the tree nodes using in order traversal
*/
ostream& operator<<(ostream &os, BinTree &BST) {
    BST.printTree(os);
    os << endl;
    return os;
}

/******************************************************************************
* printTree()
* Preconditions:
* Postconditions: Calls private helper function printInOrder() to write
* tree node data values to an output stream object
*/
void BinTree::printTree(ostream& os) {
    printInOrder(os, root);
}

// private helper function for printTree()
void BinTree::printInOrder(ostream& os, Node *rt) const {
    if (rt == nullptr) {
        return;
    }
    printInOrder(os, rt->left);
    os << *rt->data << " ";
    printInOrder(os, rt->right);
}
