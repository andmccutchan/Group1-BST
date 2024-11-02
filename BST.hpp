#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include "BSTNode.hpp"
using namespace std;

template <class T>
class BST {
private:
    BSTNode<T>* root = nullptr;
public:
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

#include "BST.cpp"

#endif