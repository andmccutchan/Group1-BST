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
    else {
        root = nullptr;
        nodeCount = 0;
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
//================================================
template <class T>
void BST<T>::remove(T value) {
    if (root == nullptr) {
       try {
            throw custom_exceptions("Tree is empty");
        }
        
        catch (const custom_exceptions& e) {
            cout << "Caught an exception: " << e.what() << endl;
        }
    }
    BSTNode<T>* node = search(value);

    if (node == nullptr) {
        try {
            throw custom_exceptions("Value not found in tree");
        }
        
        catch (const custom_exceptions& e) {
            cout << "Caught an exception: " << e.what() << endl;
        }
        delete(node);
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
    if (root == nullptr) {
        try {
            throw custom_exceptions("Tree is empty");
        }
        
        catch (const custom_exceptions& e) {
            cout << "Caught an exception: " << e.what() << endl;
        }
    }
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
    if (root == nullptr) {
        try {
            throw custom_exceptions("Tree is empty");
        }
        
        catch (const custom_exceptions& e) {
            cout << "Caught an exception: " << e.what() << endl;
        }
    }
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