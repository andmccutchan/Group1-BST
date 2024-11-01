#include "BST.hpp"
#include "BSTNode.hpp"

//================================================
// TRANSPLANT
//================================================
template <class T>
void BST<T>::transplant(BSTNode<T> *oldNode, BSTNode<T> *newNode) {
    if (oldNode->parent == nullptr) {
        root = newNode;
    }
    else if (oldNode == oldNode->parent->left) {
        oldNode->parent->left = newNode;
    }
    else {
        oldNode->parent->right = newNode;
    }

    if (newNode != nullptr) {
        newNode->parent = oldNode->parent;
    }
}

//================================================
// ISEMPTY
//================================================
template <class T>
bool BST<T>::isEmpty() const {
    return root == nullptr;
}

//================================================
// SIZE
//================================================
template <class T>
long BST<T>::size() const {
    if (this == nullptr) {
        return 0;
    }

    long count = 1; 
    if (left) {
        count += left->size(); 
    }
    if (right) {
        count += right->size(); 
    }
    return count;
}

//================================================
// INSERT
//================================================
template <class T>
BSTNode<T>* BST<T>::insert(T value) {
    BSTNode<T>* newNode = new BSTNode<T>(value);

    if (root == nullptr) {
        root = newNode;
        return newNode;
    }

    BSTNode<T>* current = root;
    BSTNode<T>* parent = nullptr;
    while (current != nullptr) {
        parent = current;
        if (value < current->value) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    if (value < parent->data) {
        parent->left = newNode; 
    } else {
        parent->right = newNode;
    }

    return newNode;
}

//================================================
// REMOVE
//================================================
template <class T>
void BST<T>::remove(T value) {

}

//================================================
// SEARCH
//================================================
template <class T> 
BSTNode<T>* BST<T>::search(T value) const {
    
}

//================================================
// TREEMIN
//================================================
template <class T>
BSTNode<T>* BST<T>::treeMin() const {

}

//================================================
// TREEMAX
//================================================
template <class T>
BSTNode<T>* BST<T>::treeMax() const {
    
}

//================================================
// PRINTPREORDERTRAVERSAL
//================================================
template <class T>
void BST<T>::printPreOrderTraversal() const {

}

//================================================
// PRINTINORDERTRAVERSAL
//================================================
template <class T>
void BST<T>::printInOrderTraversal() const {

}

//================================================
// PRINTPOSTORDERTRAVERSAL
//================================================
template <class T>
void BST<T>::printPostOrderTraversal() const {
    
}
