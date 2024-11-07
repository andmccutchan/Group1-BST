#include "RBTree.hpp"

/*=================================================
Default Constructor: Intializes an empty tree
Parameters: none
Post Condition: root = 0, size = 0
Returns: none
=================================================*/
template <typename T>
RBTree<T>::RBTree(){
    root = nullptr;
    nodeCount = 0;
}

/*=================================================
Copy Constructor: Intializes a tree through deep
copying on another red black tree
Parameters: Tree being copied
Post Condition: Copy of tree is created
Returns: none
=================================================*/
template <typename T>
RBTree<T>::RBTree(const RBTree<T>& other) {
    if (other.root != nullptr){
        root = copySubTree(other.root);
        nodeCount = other.nodeCount;
    }
}

/*=================================================
Destructor: Removes instance of a red black tree
Parameters: none
Returns: none
=================================================*/
template <typename T>
RBTree<T>::~RBTree() {
    deleteSubTree(root);
    root = nullptr;
    nodeCount = 0;
}

/*=================================================
Assignment Operator: 
Parameters:
Returns:
=================================================*/
template <typename T>
RBTree<T>& RBTree<T>::operator=(const RBTree<T>& other){
    deleteSubTree(root);
    root = copySubTree(other.root);
    nodeCount = other.nodeCount;
    return *this;
}

/*=================================================
Transplant:
Parameters:
Returns:
=================================================*/
template <typename T>
void RBTree<T>::transplant(RBTreeNode<T> *oldNode, RBTreeNode<T> *newNode){
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

/*=================================================
IsEmpty:
Parameters:
Returns:
=================================================*/
template <typename T>
bool RBTree<T>::isEmpty() const{
    return root == nullptr;
}

/*=================================================
Size:
Parameters:
Returns:
=================================================*/
template <typename T>
long RBTree<T>::size() const{
    return nodeCount;
}

template <class T>
void RBTree<T>::leftRotate(RBTreeNode<T> *moveNode) {
    RBTreeNode<T>* current = moveNode->right;
    moveNode->right = current->left;
    if (current->left != nullptr){
        current->left->parent = moveNode;
    }
    current->parent = moveNode->parent;
    if (moveNode->parent == nullptr) {
        root = current;
    }
    
    else if(moveNode == moveNode->parent->left) {
        moveNode->parent->left = current;
    }
    else {
        moveNode->parent->right = current;
    }
    current->left = moveNode;
    moveNode->parent = current;
}

template <class T>
void RBTree<T>::rightRotate(RBTreeNode<T> *moveNode) {
   RBTreeNode<T>* current = moveNode->left;
    moveNode->left = current->right;
    if (current->right != nullptr){
        current->right->parent = moveNode;
    }
    current->parent = moveNode->parent;
    if (moveNode->parent == nullptr) {
        root = current;
    }
    
    else if(moveNode == moveNode->parent->right) {
        moveNode->parent->right = current;
    }
    else {
        moveNode->parent->left = current;
    } 
    current->right = moveNode;
    moveNode->parent = current;
}

/*=================================================
Insert:
Parameters:
Returns:
=================================================*/
template <typename T>
RBTreeNode<T>* RBTree<T>::insert(T value){
    RBTreeNode<T>* newNode = new RBTreeNode<T>(value);
    nodeCount++;
    RBTreeNode<T>* current = root;
    RBTreeNode<T>* valueParent = nullptr;
    while (current != nullptr) {
        valueParent = current;
        if (newNode->data < current->data) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
    newNode->parent = valueParent;
    if (valueParent == nullptr) {
        root = newNode;
    }
    else if (newNode->data < valueParent->data) {
        valueParent->left = newNode;
    }
    else {
        valueParent->right = newNode;
    }
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->color = true;
    insertFixUp(newNode);
    return newNode;
}

template <class T>
void RBTree<T>::insertFixUp(RBTreeNode<T>* node) {
    while (node != root && node->parent->color == true) {
        if (node->parent == node->parent->parent->left) {
            RBTreeNode<T>* uncle = node->parent->parent->right;
            if (uncle != nullptr && uncle->color == true) {
                node->parent->color = false;
                uncle->color = false;
                node->parent->parent->color = true;
                node = node->parent->parent;
            }
            else {
                if (node == node->parent->right) {
                    node = node->parent;
                    leftRotate(node);
                }
                node->parent->color = false;
                node->parent->parent->color = true;
                rightRotate(node->parent->parent);
            }
        }
        else {
            RBTreeNode<T>* uncle = node->parent->parent->left;
            if (uncle != nullptr && uncle->color == true) {
                node->parent->color = false;
                uncle->color = false;
                node->parent->parent->color = true;
                node = node->parent->parent;
            }
            else {
                if (node == node->parent->left) {
                    node = node->parent;
                    rightRotate(node);
                }
                node->parent->color = false;
                node->parent->parent->color = true;
                leftRotate(node->parent->parent);
            }
        }
    }
    root->color = false;
}

/*=================================================
Remove:
Parameters:
Returns:
=================================================*/
template <typename T>
void RBTree<T>::remove(T value){
    RBTreeNode<T>* removeNode = search(value);
    if (removeNode == nullptr) {
        try {
            throw custom_exceptions("Value not found in tree");
        }
        
        catch (const custom_exceptions& e) {
            cout << "Caught an exception: " << e.what() << endl;
        }
    }

    RBTreeNode<T>* node = removeNode;
    RBTreeNode<T>* moveNode;
    bool node_color = node->color;
    
    if (removeNode->left == nullptr) {
        moveNode = removeNode->right;
        transplant(removeNode, removeNode->right);
    }
    else if (removeNode->right == nullptr) {
        moveNode = removeNode->left;
        transplant(removeNode, removeNode->left);
    }
    else {
        node = removeNode->right->treeMin();
        node_color = node->color;
        moveNode = node->right;

        if (node != removeNode->right) {
            transplant(node, node->right);
            node->right = removeNode->right;
            node->right->parent = node;
        }
        else {
            moveNode->parent = node;
        }
        transplant(removeNode, node);
        node->left = removeNode->left;
        node->left->parent = node;
        node->color = removeNode->color;
    }
    delete removeNode;
    nodeCount--;
    if (node_color == false) {
        deleteFixUp(moveNode);
    }
}

template <class T>
void RBTree<T>::deleteFixUp(RBTreeNode<T>* moveNode) {
    while (moveNode != root && (moveNode == nullptr || moveNode->color == false)) {
        if (moveNode == moveNode->parent->left) {
            RBTreeNode<T>* sibling = moveNode->parent->right;
            if (sibling->color == true) {
                sibling->color = false;
                moveNode->parent->color = true;
                leftRotate(moveNode->parent);
                sibling = moveNode->parent->right;
            }
            if ((sibling->left == nullptr || sibling->left->color == false) && 
                (sibling->right == nullptr || sibling->right->color == false)) {
                sibling->color = true;
                moveNode = moveNode->parent;
            }
            else {
                if (sibling->right == nullptr || sibling->right->color == false) {
                    if (sibling->left != nullptr) {
                        sibling->left->color = false;
                    }
                    sibling->color = true;
                    rightRotate(sibling);
                    sibling = moveNode->parent->right;
                }
                sibling->color = moveNode->parent->color;
                moveNode->parent->color = false;
                if (sibling->right != nullptr){
                    sibling->right->color = false;
                }
                leftRotate(moveNode->parent);
                moveNode = root;
            }
        }
        else {
            RBTreeNode<T>* sibling = moveNode->parent->left;
            if (sibling->color == true) {
                sibling->color = false;
                moveNode->parent->color = true;
                rightRotate(moveNode->parent);
                sibling = moveNode->parent->left;
            }
            if ((sibling->right == nullptr || sibling->right->color == false) &&
                (sibling->left == nullptr || sibling->left->color == false)) {
                sibling->color = true;
                moveNode = moveNode->parent;
            }
            else {
                if (sibling->left == nullptr || sibling->left->color == false) {
                    if (sibling->right != nullptr) {
                        sibling->left->color = false;
                    }
                    sibling->color = true;
                    leftRotate(sibling);
                    sibling = moveNode->parent->left;
                }
                sibling->color = moveNode->parent->color;
                moveNode->parent->color = false;
                sibling->left->color = false;
                rightRotate(moveNode->parent);
                moveNode = root;
            }
        }
    }
    if (moveNode != nullptr) {
        moveNode->color = false;
    }
}

/*=================================================
Search:
Parameters:
Returns:
=================================================*/
template <typename T>
RBTreeNode<T>* RBTree<T>::search(T value) const{
    RBTreeNode<T>* current = root;
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

/*=================================================
TreeMin:
Parameters:
Returns:
=================================================*/
template <typename T>
RBTreeNode<T>* RBTree<T>::treeMin() const{
    RBTreeNode<T>* track = root;
    while (root && track->left != nullptr){
        track = track -> left;
    }
    return track;
}

/*=================================================
TreeMax:
Parameters:
Returns:
=================================================*/
template <typename T>
RBTreeNode<T>* RBTree<T>::treeMax() const{
    RBTreeNode<T>* track = root;
    while (root && track->right != nullptr){
        track = track -> right;
    }
    return track;
}

/*=================================================
PrintPreOrderTraversal:
Parameters:
Returns:
=================================================*/
template <typename T>
void RBTree<T>::printPreOrderTraversal() const{
    if (root != nullptr){
        root -> printPreOrderTraversal();
    }
}

/*=================================================
PrintInOrderTraversal:
Parameters:
Returns:
=================================================*/
template <typename T>
void RBTree<T>::printInOrderTraversal() const{
    if (root != nullptr){
        root -> printInOrderTraversal();
    }
}

/*=================================================
PrintPostOrderTraversal:
Parameters:
Returns:
=================================================*/
template <typename T>
void RBTree<T>::printPostOrderTraversal() const{
    if (root != nullptr){
        root -> printPostOrderTraversal();
    }
}

/*=================================================
CopySubTree:
Parameters:
Returns:
=================================================*/
template <typename T>
RBTreeNode<T>* RBTree<T>::copySubTree(const RBTreeNode<T>* node){
    if (node == nullptr){
        return nullptr;
    }

    RBTreeNode<T>* newNode = new RBTreeNode<T>(node->data);
    newNode -> left = copySubTree(node->left);
    newNode -> right = copySubTree(node->right);

    return newNode;
}

/*=================================================
DeleteSubTree:
Parameters:
Returns:
=================================================*/
template <typename T>
void RBTree<T>::deleteSubTree(RBTreeNode<T>* node){
    if (node == nullptr){
        return;
    }
    deleteSubTree(node->left);
    deleteSubTree(node->right);

    delete node;
}