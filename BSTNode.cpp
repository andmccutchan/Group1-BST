
#include "BSTNode.hpp"

template <typename T>
BSTNode<T>::BSTNode(const T& value) {
    data = value;
    left = nullptr;
    right = nullptr;
}

template <typename T>
BSTNode<T>::BSTNode(const T& value, BSTNode<T>* left, BSTNode<T>* right) {
    data = value;
    left = left;
    right = right;
}

template <typename T>
BSTNode<T>::BSTNode(const BSTNode<T>& other) {
    data = other.value;
    left = other.left;
    right = other.right;
}

template <typename T>
BSTNode<T>& BSTNode<T>::operator=(const BSTNode<T>& other) {
    data = other.value;
    left = other.left;
    right = other.right;
    return *this;
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
    if (left != nullptr) {
        left->printPreOrderTraversal();
    }
    if (right != nullptr) {
        right->printPreOrderTraversal();
    }
}

template <class T>
void BSTNode<T>::printInOrderTraversal() const {
    if (left != nullptr) {
        left->printInOrderTraversal();
    }
    cout << data << " ";
    if (right != nullptr) {
        right->printInOrderTraversal();
    }
}

template <class T>
void BSTNode<T>::printPostOrderTraversal() const {
    if (left != nullptr) {
        left->printPostOrderTraversal();
    }
    if (right != nullptr) {
        right->printPostOrderTraversal();
    }
    cout << data << " ";
}
