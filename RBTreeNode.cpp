#include "RBTreeNode.hpp"

template <typename T>
RBTreeNode<T>::RBTreeNode(const T& value) {
    data = value;
    left = nullptr;
    right = nullptr;
    color = true;
}

template <typename T>
RBTreeNode<T>::RBTreeNode(const T& value, RBTreeNode<T>* left, RBTreeNode<T>* right) {
    data = value;
    left = left;
    right = right;
}

template <typename T>
RBTreeNode<T>::RBTreeNode(const RBTreeNode<T>& other) {
    data = other.data;
    left = other.left;
    right = other.right;
}

template <typename T>
RBTreeNode<T>& RBTreeNode<T>::operator=(const RBTreeNode<T>& other) {
    if (this != &other) {
        data = other.data;
        left = other.left;
        right = other.right;
    }
    return *this;
}

template <typename T>
RBTreeNode<T>* RBTreeNode<T>::treeMin() {
    RBTreeNode<T>* track = this;
    while (track && track->left != nullptr) {
        track = track -> left;
    }
    return track;
}

template <typename T>
RBTreeNode<T>* RBTreeNode<T>::treeMax() {
    RBTreeNode<T>* track = this;
    while (track && track->right != nullptr) {
        track = track -> right;
    }
    return track;
}

template <typename T>
void RBTreeNode<T>::printPreOrderTraversal() const {
    cout << data << " ";
    if (left != nullptr) {
        left -> printPreOrderTraversal();
    }
    if (right != nullptr) {
        right -> printPreOrderTraversal();
    }
}

template <typename T>
void RBTreeNode<T>::printInOrderTraversal() const {
    if (left != nullptr){
       left -> printInOrderTraversal();
    }
    cout << data << " ";
    if (right != nullptr){
        right -> printInOrderTraversal();
    }
}

template <typename T>
void RBTreeNode<T>::printPostOrderTraversal() const {
    if (left != nullptr){
        left -> printPostOrderTraversal();
    }
    if (right != nullptr){
        right -> printPostOrderTraversal();
    }
    cout << data << " ";
}
