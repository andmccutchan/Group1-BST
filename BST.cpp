#include "BST.hpp"

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
    BSTNode<T>* current = root;
    BSTNode<T>* previous = nullptr;

    // iterate through and search for given value
    while (current != nullptr && current->data != value) {
        previous = current;
        if (value < current->data) {
            current = current->left;
        }else {
            current = current->right;
        }
    }
    // CASE 1 -- VALUE NOT FOUND
    if (current == nullptr) {
        cout << "Value not found in tree" << endl;
        delete(previous);
    }
    // CASE 2 -- NODE HAS NO CHILDREN
    else {
        if (current->left == nullptr && current->right == nullptr) {
            // check if value is root
            if (root == current) {
            root = nullptr;
            }if (previous->left == current) {
                previous->left = nullptr;
        }else {
            previous->right = nullptr;
        }
            delete(current);
        }
        // CASE 3 -- NODE HAS ONE CHILD
        if (current->left == nullptr || current->right == nullptr) {
            BSTNode<T>* child = nullptr;
            if (current->left == nullptr) {
                child = current->right;
            }else {
                child = current->left;
            }
            // check if current is root
            if (previous == nullptr) {
                root = child;
            }if (previous->left == current) {
                previous->left = child;
            }else {
                previous->right = child;
            }
            delete(current);
        }
        // CASE 4 -- NODE HAS TWO CHILDREN
        if (current->left != nullptr && current->right != nullptr) {
            BSTNode<T>* successor = current->right;
            BSTNode<T>* successorParent = nullptr;

            while (successor->left != nullptr) {
                successorParent = successor;
                successor = successor->left;
            }
            // checks if successor is right child of node to be deleted
            if (successorParent != nullptr){
                successorParent->left = successor->right;
            }else {
                current->right = successor->right;
            }
            successor->right = current->right;

            if (previous->left == current) {
                previous->left = successor;
            }else {
                previous->right = successor;
            }
            successor->left = current->left;

            delete(current);
        }
    }
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