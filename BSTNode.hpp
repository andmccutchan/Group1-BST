#include <iostream>

using namespace std;

#ifndef BST_NODE_HPP
#define BST_NODE_HPP

template <class T>
class BSTNode
{
private:
    BSTNode<T>* treeMin();
    BSTNode<T>* treeMax();
    void printPreOrderTraversal() const;
    void printInOrderTraversal() const;
    void printPostOrderTraversal() const;

public:
       
};

#endif