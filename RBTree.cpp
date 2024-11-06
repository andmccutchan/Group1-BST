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
    if(oldNode == root){
        root = newNode;
         return
    }

    RBTreeNode<T>* parent = nullptr;
    RBTreeNode<T>* grandparent = nullptr;
    RBTreeNode<T>* uncle = nullptr;
    RBTreeNode<T>* current = root;

    while(newNode->color == false && newNode->parent->color == false){
        parent = newNode -> parent;
        grandparent = parent -> parent;

        if(parent == grandparent -> left){
            uncle = grandparent -> right;

            if(uncle != nullptr && uncle->color == false){
                grandparent -> color = false;
                parent -> color = true;
                uncle -> color = true;
                newNode = grandparent;
            }
            else {
                if (newNode == parent->right){
                    newNode = parent;
                    leftRotate(newNode);
                }

                parent->color = true;
                grandparent->color = false;
                rightRotate(grandparent);
            }
            else{
                uncle = grandparent -> left;
                if(uncle != nullptr && uncle->color == false){
                grandparent -> color = false;
                parent -> color = true;
                uncle -> color = true;
                newNode = grandparent;
            }
            else {
                if (newNode == parent->left){
                    newNode = parent;
                    rightRotate(newNode);
                }

                parent->color = true;
                grandparent->color = false;
                leftRotate(grandparent);
            }
        }
    }
    root -> color = true;
}

/*=================================================
Left Rotate:
Parameters:
Returns:
=================================================*/
void RBTree<T>::leftRotate(RBTreeNode<T> *x){
    RBTreeNode<T>* current = x -> right;
    x -> right = current -> left;

    if (current->left != nullptr){
        x = current -> left -> parent;
    }
    current -> left = x;
    if (x == root) {
        root = current;
    }
    else if(x == parent->left){
        x = current;
    }
    else (x == parent->right){
        x = current;
        current -> left = x;
        parent = y;
    }
}

/*=================================================
Right Rotate:
Parameters:
Returns:
=================================================*/
void RBTree<T>::rightRotate(RBTreeNode<T> *x){
    RBTreeNode<T>* current = x -> left;
    x -> left = current -> right;

    if (current->right != nullptr){
        x = current -> right -> parent;
    }
    current -> right = x;
    if (x == root) {
        root = current;
    }
    else if(x == parent->right){
        x = current;
    }
    else (x == parent->left){
        x = current;
        current -> right = x;
        parent = y;
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

/*=================================================
Insert:
Parameters:
Returns:
=================================================*/
template <typename T>
RBTreeNode<T>* RBTree<T>::insert(T value){
    RBTreeNode<T>* newNode = new RBTreeNode<T>(value);
    newNode -> color = false;
    nodeCount++;
    if (root == nullptr){
        root = newNode;
        root -> color = true;
        return newNode;
    }

    RBTreeNode<T>* current = root;
    RBTreeNode<T>* parent = nullptr;
    while (current != nullptr){
        parent = current;
        if (value < current->data){
            current = current -> left;
        }
        else {
            current = current -> right;
        }
    }

    if (value <= parent->data){
        parent->left = newNode;
    }
    else{
        parent->right = newNode;
    }
    transplant(root, newNode);
    return newNode;
}

/*=================================================
Remove:
Parameters:
Returns:
=================================================*/
template <typename T>
void RBTree<T>::remove(T value){

}

/*=================================================
Search:
Parameters:
Returns:
=================================================*/
template <typename T>
RBTreeNode<T>* RBTree<T>::search(T value) const{
    RBTreeNode<T>* current = root;
    while (current != nullptr){
        if (current->data == value){
            return current;
        }
        else if (value < current->data){
            current = current -> left;
        }
        else {
            current = current -> right;
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
