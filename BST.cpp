//========================================================
// BST.cpp
// DATE: October 26th
// AUTHORS: Andrew McCutchan, Liam Kaznelson, Esther Zhang
// DESCRIPTION: Provides function definitions for all of
// the methods contained within the BST class.
//========================================================

#include "BST.hpp"
#include "customexceptions.hpp"

//================================================
// DEFAULT CONSTRUCTOR
// PARAMETERS: None
// DESCRIPTION: Initializes a value of the BST
// class
// RETURN: None
//================================================
template <typename T>
BST<T>::BST() {
    root = nullptr;
    nodeCount = 0;
}


//================================================
// COPY CONSTRUCTOR
// PARAMETERS: const BST<T>& other
// DESCRIPTION: Copies one BST value into another
// RETURN: None
//================================================
template <typename T>
BST<T>::BST(const BST<T>& other) {
    if (other.root != nullptr) {
        root = copySubTree(other.root); 
        nodeCount = other.nodeCount;
    }
    else {
        root = nullptr;
        nodeCount = 0;
    }
}


//================================================
// DESTRUCTOR
// PARAMETERS: None
// DESCRIPTION: Deconstructs the BST value
// RETURN: None
//================================================
template <typename T>
BST<T>::~BST() {
    deleteSubTree(root);
    root = nullptr;
    nodeCount = 0;
}


//================================================
// ASSIGNMENT OPERATOR
// PARAMETERS: const BST<T>& other
// DESCRIPTION: Set the current BST equal to the
// parameter BST value.
// RETURN: *this
//================================================
template <typename T>
BST<T>& BST<T>::operator=(const BST<T>& other) {
    deleteSubTree(root);
    root = copySubTree(other.root);
    nodeCount = other.nodeCount;
    return *this;
}

//================================================
// TRANSPLANT
// PARAMETERS: BSTNode<T> *oldNode, 
// BSTNode<T> *newNode
// DESCRIPTION: Transplants the oldNode parameter
// into the newNode parameter, accounting for
// any important cases.
// RETURN: None
//================================================
template <class T>
void BST<T>::transplant(BSTNode<T> *oldNode, BSTNode<T> *newNode) {
    if (oldNode == root) {
        root = newNode;  
        return;
    }

    BSTNode<T>* parent = nullptr;
    BSTNode<T>* current = root;

    while (current != nullptr && current != oldNode) {
        parent = current;
        if (oldNode->data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (oldNode == parent->left) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

//================================================
// ISEMPTY
// PARAMETERS: None
// DESCRIPTION: Checks whether the current BST
// is empty or not
// RETURN: True or False
//================================================
template <class T>
bool BST<T>::isEmpty() const {
    return root == nullptr;
}

//================================================
// SIZE
// PARAMETERS: None
// DESCRIPTION: Returns the size of the current
// BST
// RETURN: nodeCount
//================================================
template <class T>
long BST<T>::size() const {  
    return nodeCount;
}

//================================================
// INSERT
// PARAMETERS: T value
// DESCRIPTION: Inserts the value parameter into
// the current BST
// RETURN: newNode
//================================================
template <class T>
BSTNode<T>* BST<T>::insert(T value) {
    BSTNode<T>* newNode = new BSTNode<T>(value);
    nodeCount++;
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

    if (value <= parent->data) {
        parent->left = newNode; 
    } else {
        parent->right = newNode;
    }
    return newNode;
}

//================================================
// REMOVE
// PARAMETERS: T value
// DESCRIPTION: Removes the inputted value from
// the current BST
// RETURN: None
//================================================
template <class T>
void BST<T>::remove(T value) {
    if (root == nullptr) {
        throw empty_tree_exception();
    }
    BSTNode<T>* node = search(value);

    if (node == nullptr) {
        throw value_not_in_tree_exception();
    }

    if (node->left == nullptr) { 
        transplant(node, node->right);
    } 
    else if (node->right == nullptr) {
        transplant(node, node->left);
    } 
    else {
        BSTNode<T>* successor = node->right->treeMin();

        if (successor != node->right) {
            transplant(successor, successor->right);
            successor->right = node->right;
        }

        transplant(node, successor);
        successor->left = node->left;
    }

    nodeCount--;
    delete node;
}

//================================================
// SEARCH
// PARAMETERS: T value
// DESCRIPTION: Searches for the value parameter
// in the current BST
// RETURN: Pointer of value parameter or nullptr
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
// PARAMETERS: None
// DESCRIPTION: Returns the smallest value in the
// BST
// RETURN: current
//================================================
template <class T>
BSTNode<T>* BST<T>::treeMin() const {
    if (root == nullptr) {
        throw empty_tree_exception();
    }
    BSTNode<T>* current = root;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

//================================================
// TREEMAX
// PARAMETERS: None
// DESCRIPTION: Returns the biggest value in the
// BST
// RETURN: None
//================================================
template <class T>
BSTNode<T>* BST<T>::treeMax() const {
    if (root == nullptr) {
        throw empty_tree_exception();
    }
    BSTNode<T>* current = root;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current;
}

//================================================
// PRINTPREORDERTRAVERSAL
// PARAMETERS: None
// DESCRIPTION: Print the BST's items using
// preorder traversal
// RETURN: None
//================================================
template <class T>
void BST<T>::printPreOrderTraversal() const {
    if (root != nullptr) {
        root->printPreOrderTraversal();
    }
}

//================================================
// PRINTINORDERTRAVERSAL
// PARAMETERS: None
// DESCRIPTION: Print the BST's items using
// inorder traversal
// RETURN: None
//================================================
template <class T>
void BST<T>::printInOrderTraversal() const {
    if (root != nullptr) {
        root->printInOrderTraversal();
    }
}

//================================================
// PRINTPOSTORDERTRAVERSAL
// PARAMETERS: None
// DESCRIPTION: Print the BST's items using
// postorder traversal
// RETURN: None
//================================================
template <class T>
void BST<T>::printPostOrderTraversal() const {
    if (root != nullptr) {
        root->printPostOrderTraversal();
    }
}

//================================================
// COPY SUBTREE
// PARAMETERS: const BSTNode<T>* node
// DESCRIPTION: Copies the inputted subtree
// into the current BSTNode
// RETURN: nullptr or newNode
//================================================
template <typename T>
BSTNode<T>* BST<T>::copySubTree(const BSTNode<T>* node) {
    if (node == nullptr) {
        return nullptr;
    }
    
    BSTNode<T>* newNode = new BSTNode<T>(node->data);

    newNode->left = copySubTree(node->left);
    newNode->right = copySubTree(node->right);

    return newNode;
}

//================================================
// DELETE SUBTREE
// PARAMETERS: BSTNode<T>* node
// DESCRIPTION: Delete the inputted parameter
// from the current BST
// RETURN: None
//================================================
template <typename T>
void BST<T>::deleteSubTree(BSTNode<T>* node) {
    if (node == nullptr) {
        return;
    }
    deleteSubTree(node->left);
    deleteSubTree(node->right);

    delete node;
}