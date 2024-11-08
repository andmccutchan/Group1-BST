//========================================================
// BSTNode.cpp
// DATE: October 26th
// AUTHORS: Andrew McCutchan, Liam Kaznelson, Esther Zhang
// DESCRIPTION: Provides function definitions for all of
// the methods contained within the BSTNode class.
//========================================================

#include "BSTNode.hpp"

//================================================
// DEFAULT CONSTRUCTOR
// PARAMETERS: const T& value
// DESCRIPTION: Initializes a BSTNode value
// RETURN: None
//================================================
template <typename T>
BSTNode<T>::BSTNode(const T& value) {
    data = value;
    left = nullptr;
    right = nullptr;
}

//================================================
// PARAMETER CONSTRUCTOR
// PARAMETERS: const T& value, BSTNode<T>* left,
// BSTNode<T>* right
// DESCRIPTION: Initializes a BSTNode value using
// the given parameters
// RETURN: None
//================================================
template <typename T>
BSTNode<T>::BSTNode(const T& value, BSTNode<T>* left, BSTNode<T>* right) {
    data = value;
    left = left;
    right = right;
}

//================================================
// COPY CONSTRUCTOR
// PARAMETERS: const BSTNode<T>& other
// DESCRIPTION: Initializes a BSTNode value using
// the parametered BSTNode value
// RETURN: None
//================================================
template <typename T>
BSTNode<T>::BSTNode(const BSTNode<T>& other) {
    data = other.value;
    left = other.left;
    right = other.right;
}

//================================================
// ASSIGNMENT OPERATOR
// PARAMETERS: const BSTNode<T>& other
// DESCRIPTION: Sets the current BSTNode value
// equal to the parametered BSTNode other
// RETURN: None
//================================================
template <typename T>
BSTNode<T>& BSTNode<T>::operator=(const BSTNode<T>& other) {
    data = other.value;
    left = other.left;
    right = other.right;
    return *this;
}

//================================================
// TREEMIN
// PARAMETERS: None
// DESCRIPTION: Returns the smallest value in the
// BSTNode
// RETURN: current
//================================================
template <class T>
BSTNode<T>* BSTNode<T>::treeMin() {
        BSTNode<T>* current = this;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

//================================================
// TREEMAX
// PARAMETERS: None
// DESCRIPTION: Returns the largest value in the
// BSTNode
// RETURN: current
//================================================
template <class T>
BSTNode<T>* BSTNode<T>::treeMax() {
    BSTNode<T>* current = this;
    while (current && current->right != nullptr) {
        current = current->right;
    }
    return current;
}

//================================================
// PRINTPREORDERTRAVERSAL
// PARAMETERS: None
// DESCRIPTION: Print the BSTNode's items using
// preorder traversal
// RETURN: None
//================================================
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

//================================================
// PRINTINORDERTRAVERSAL
// PARAMETERS: None
// DESCRIPTION: Print the BSTNode's items using
// inorder traversal
// RETURN: None
//================================================
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

//================================================
// PRINTPOSTORDERTRAVERSAL
// PARAMETERS: None
// DESCRIPTION: Print the BSTNode's items using
// postorder traversal
// RETURN: None
//================================================
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
