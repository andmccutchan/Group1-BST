#include <iostream>
#include "BSTNode.hpp"
using namespace std;

template<class T>
BSTNode<T>::BSTNode(const T& value) {
    data = value;
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
    delete left;
    delete right;
}



template <class T>
BSTNode<T>* BSTNode<T>::treeMin() {
        BSTNode<T>* current = this;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

template <class T>
BSTNode<T>* BSTNode<T>::treeMax() {
    BSTNode<T>* current = this;
    while (current && current->right != nullptr) {
        current = current->right;
    }
    return current;
}

template <class T>
void BSTNode<T>::printPreOrderTraversal() const {
    cout << data << " ";
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
        left->printInOrderTraversal();
    }
    cout << data << " ";
    if (right) {
        right->printInOrderTraversal();
    }
}

template <class T>
void BSTNode<T>::printPostOrderTraversal() const {
    if (left) {
        left->printPostOrderTraversal();
    }
    if (right) {
        right->printPostOrderTraversal();
    }  
    cout << data << " ";
}
