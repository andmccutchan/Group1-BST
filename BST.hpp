#include <iostream>

using namespace std;

#ifndef BST_HPP
#define BST_HPP

template <class T>
class BST
{
private:
    struct Node
    {
        T value;
        Node* left;
        Node* right;
    };

public:
    void        transplant(BSTNode<T> *oldNode, BSTNode<T> *newNode);
    bool        isEmpty() const;
    long        size() const;
    BSTNode<T>* insert(T value);
    void        remove(T value);
    BSTNode<T>* search(T value) const;
    BSTNode<T>* treeMin() const;
    BSTNode<T>* treeMax() const;
    void        printPreOrderTraversal() const;
    void        printInOrderTraversal() const;
    void        printPostOrderTraversal() const;  
};

#endif