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
    if (root == nullptr) {
        return 0; // If the root is nullptr, the size is 0
    }
    
    long count = 1; 
    if (root->left != nullptr) {
        count += size(root->left); 
    }
    if (root->right != nullptr) {
        count += size(root->right);
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
        if (value < current->data) {
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
    BSTNode<T>* current = root;
    while (current != nullptr) {
        if (current->data == value) {
            return current;
        }
        else if (value < current->data) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
    return nullptr;
}

//================================================
// TREEMIN
//================================================
template <class T>
BSTNode<T>* BST<T>::treeMin() const {
    BSTNode<T>* current = root;
    while (root && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

//================================================
// TREEMAX
//================================================
template <class T>
BSTNode<T>* BST<T>::treeMax() const {
    BSTNode<T>* current = root;
    while (root && current->right != nullptr) {
        current = current->right;
    }
    return current;
}

//================================================
// PRINTPREORDERTRAVERSAL
//================================================
template <class T>
void BST<T>::printPreOrderTraversal() const {
    if (root != nullptr) {
        root->printPreOrderTraversal();
    }
}

//================================================
// PRINTINORDERTRAVERSAL
//================================================
template <class T>
void BST<T>::printInOrderTraversal() const {
    if (root != nullptr) {
        root->printInOrderTraversal();
    }
}

//================================================
// PRINTPOSTORDERTRAVERSAL
//================================================
template <class T>
void BST<T>::printPostOrderTraversal() const {
    if (root != nullptr) {
        root->printPostOrderTraversal();
    }
}
