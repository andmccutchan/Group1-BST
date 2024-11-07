#include "BST.hpp"
#include "customexceptions.hpp"

//================================================
// DEFAULT CONSTRUCTOR
//================================================
template <typename T>
BST<T>::BST() {
    root = nullptr;
    nodeCount = 0;
}


//================================================
// COPY CONSTRUCTOR
//================================================
template <typename T>
BST<T>::BST(const BST<T>& other) {
    if (other.root != nullptr) {
        root = copySubTree(other.root); 
        nodeCount = other.nodeCount;
    }
}


//================================================
// DESTRUCTOR
//================================================
template <typename T>
BST<T>::~BST() {
    deleteSubTree(root);
    root = nullptr;
    nodeCount = 0;
}


//================================================
// ASSIGNMENT OPERATOR
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
//================================================
template <class T>
void BST<T>::transplant(BSTNode<T> *oldNode, BSTNode<T> *newNode) {
    if (oldNode == root) {
        root = newNode;
    } 
    BSTNode<T>* parent = nullptr;
    BSTNode<T>* current = root;

    while (current != nullptr && current != oldNode) {
        parent = current;
        if (oldNode->data < current->data) {
            current = current->left;
        } 
        else {
            current = current->right;
        }
    }

    if (oldNode == parent->left) {
        parent->left = newNode;
    }
    else {
        parent->right = newNode;
    }

    if (newNode != nullptr) {
        newNode->left = oldNode->left;
        newNode->right = oldNode->right;
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
    return nodeCount;
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

    if (value <= parent->data) {
        parent->left = newNode; 
    } else {
        parent->right = newNode;
    }
    nodeCount++;
    return newNode;
}

//================================================
// REMOVE
//================================================
template <class T>
void BST<T>::remove(T value) {
    BSTNode<T>* current = search(value);

    // CASE -- VALUE NOT FOUND
    if (current == nullptr) {
        try {
            throw custom_exceptions("Value not found in tree");
        }
        
        catch (const custom_exceptions& e) {
            cout << "Caught an exception: " << e.what() << endl;
        }
    }

    if (current->left == nullptr) {
        transplant(current, current->right);
    }else if (current->right == nullptr) {
        transplant(current, current->left);
    }else {
        BSTNode<T>* successor = current->right->treeMin();
        if (successor != current->right) {
            transplant(successor, successor->right);
            successor->right = current->right;
            successor->right = successor;
        }
        transplant(current, successor);
        successor->left = current->left;
        successor->left= successor;
    }
    delete current;
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


template <typename T>
BSTNode<T>* BST<T>::copySubTree(const BSTNode<T>* node) {
    if (node == nullptr) return nullptr;

    BSTNode<T>* newNode = new BSTNode<T>(node->data);

    newNode->left = copySubTree(node->left);
    newNode->right = copySubTree(node->right);

    return newNode;
}

template <typename T>
void BST<T>::deleteSubTree(BSTNode<T>* node) {
    if (node == nullptr)
        return;
    deleteSubTree(node->left);
    deleteSubTree(node->right);

    delete node;
}