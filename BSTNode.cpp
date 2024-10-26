template <class T>
BSTNode<T>* treeMin() {
    if (this == nullptr) {
        return nullptr;
    }

    BSTNode<T>* currNode = this;
    while (currNode->left != nullptr) {
        currNode = currNode->left;
    }
    return currNode;
}

template <class T>
BSTNode<T>* treeMax() {
    if (this == nullptr) {
        return nullptr;
    }

    BSTNode<T>* currNode = this;
    while (currNode->right != nullptr) {
        currNode = currNode->right;
    }
    return currNode;
}

template <class T>
void printPreOrderTraversal() const {
    
}

template <class T>
void printInOrderTraversal() const {

}

template <class T>
void printPostOrderTraversal() const {

}
