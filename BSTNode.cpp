#include <iostream>
#include "BSTNode.hpp"
using namespace std;

template<class T>
BSTNode<T>::BSTNode() {
    data = T();
    left = nullptr;
    right = nullptr;    
}

template <class T>
BSTNode<T>::BSTNode(const BSTNode<T> &tree) {
    data = tree.data;

    if (tree.left) {
        left = new BSTNode<T>(*(tree.left)); 
    } else {
        left = nullptr; 
    }

    if (tree.right) {
        right = new BSTNode<T>(*(tree.right)); 
    } else {
        right = nullptr; 
    }
}

template <class T>
BSTNode<T>& BSTNode<T>::operator=(const BSTNode<T>& tree) {
    if (left) {
        delete left;
        left = nullptr; 
    }
    if (right) {
        delete right;
        right = nullptr; 
    } 

    data = tree.data;

    if (tree.left) {
        left = new BSTNode<T>(*(tree.left)); 
    } else {
        left = nullptr; 
    }

    if (tree.right) {
        right = new BSTNode<T>(*(tree.right)); 
    } else {
        right = nullptr; 
    }

    return *this;
}

template <class T>
BSTNode<T>::~BSTNode() {
    if (left) {
        delete left;
        left = nullptr; 
    }
    if (right) {
        delete right;
        right = nullptr; 
    }
}



template <class T>
BSTNode<T>* BSTNode<T>::treeMin() {
    if (this == nullptr) {
        return nullptr;
    }

    BSTNode<T>* currNode = this;
    while (currNode->left) {
        currNode = currNode->left;
    }
    return currNode;
}

template <class T>
BSTNode<T>* BSTNode<T>::treeMax() {
    if (this == nullptr) {
        return nullptr;
    }

    BSTNode<T>* currNode = this;
    while (currNode->right) {
        currNode = currNode->right;
    }
    return currNode;
}

template <class T>
void BSTNode<T>::printPreOrderTraversal() const {
    cout << value << " ";
    if (left) {
        left->printPreOrderTraversal();
    }
    if (right) {
        right->printPreOrderTraversal();
    }
}

template <class T>
void BSTNode<T>::printInOrderTraversal() const {
    if (left) {
        left->printPreOrderTraversal();
    }
    cout << value << " ";
    if (right) {
        right->printPreOrderTraversal();
    }
}

template <class T>
void BSTNode<T>::printPostOrderTraversal() const {
    if (left) {
        left->printPreOrderTraversal();
    }
    if (right) {
        right->printPreOrderTraversal();
    }  
    cout << value << " ";
}
