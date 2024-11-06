#ifndef RBTREE_HPP
#define RBTREE_HPP

#include <iostream>
#include "RBTreeNode.hpp"
using namespace std;

template <class T>
class RBTree {
private:
    RBTreeNode<T>* root;
    long nodeCount;

    void deleteSubTree(RBTreeNode<T>* node);                //helper function to delete nodes
    RBTreeNode<T>* copySubTree(const RBTreeNode<T>* node);  //helper function for copying nodes of a tree

public:
                    RBTree();
                    RBTree(const RBTree<T>& other);
                    ~RBTree();
    RBTree<T>&      operator=(const RBTree<T>& other);

    void            transplant(RBTreeNode<T> *oldNode, RBTreeNode<T> *newNode);
    void            leftRotate(RBTreeNode<T> *x);
    void            rightRotate(RBTreeNode<T> *x);
    bool            isEmpty() const;
    long            size() const;
    RBTreeNode<T>*  insert(T value);
    void            remove(T value);
    RBTreeNode<T>*  search(T value) const;
    RBTreeNode<T>*  treeMin() const;
    RBTreeNode<T>*  treeMax() const;
    void            printPreOrderTraversal() const;
    void            printInOrderTraversal() const;
    void            printPostOrderTraversal() const;

};

#endif
