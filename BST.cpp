template <class T>
void transplant(BSTNode<T> *oldNode, BSTNode<T> *newNode) {

}

template <class T>
bool isEmpty() const {
    return this == nullptr;
}

template <class T>
long size() const {

}

template <class T>
BSTNode<T>* insert(T value) {
    T x = this;
    T y = nullptr;
    while (x != nullptr) {
        y = x;
        if (value < x.value) {
            x = x.left;
        }
        else {
            x = x.right;
        }
    }
}

template <class T>
void remove(T value) {

}

template <class T> 
BSTNode<T>* search(T value) const {

}

template <class T>
BSTNode<T>* treeMin() const {

}

template <class T>
BSTNode<T>* treeMax() const {
    
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
