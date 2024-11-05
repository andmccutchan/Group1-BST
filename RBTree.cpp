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
