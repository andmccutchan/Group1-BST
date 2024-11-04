#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include "BSTNode.hpp"
using namespace std;

template <class T>
class BST {
private:
    BSTNode<T>* root;
    long nodeCount;

    void deleteSubTree(BSTNode<T>* node);       //helper function to delete nodes
    BSTNode<T>* copySubTree(const BSTNode<T>* node);        //helper function for copying nodes of a tree
public:
                BST();
                BST(const BST<T>& other);
                ~BST();
    BST<T>&     operator=(const BST<T>& other);

    void        transplant(BSTNode<T> *oldNode, BSTNode<T> *newNode);
    bool        isEmpty() const;
    long        size() const;
    BSTNode<T>* insert(T value);
    void        remove(T value);
    BSTNode<T>* search(T value) const;
    BSTNode<T>* treeMin() const;
    BSTNode<T>* treeMax() const;
    void        printPreOrderTraversal() const;
    void        printInOrderTraversal() const;
    void        printPostOrderTraversal() const;  
};

#endif