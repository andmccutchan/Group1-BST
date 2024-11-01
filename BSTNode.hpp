#ifndef BST_NODE_HPP
#define BST_NODE_HPP

#include <iostream>
using namespace std;

template <class T>
class BSTNode {
private:
    T data;
    BSTNode<T>* left;
    BSTNode<T>* right;
    
    
public:
                BSTNode(const T& value);                                            
                BSTNode(const BSTNode<T>& tree);      
    BSTNode<T>& operator=(const BSTNode<T>& tree); 
                ~BSTNode();      
    BSTNode<T>* treeMin();
    BSTNode<T>* treeMax();
    void        printPreOrderTraversal() const;
    void        printInOrderTraversal() const;
    void        printPostOrderTraversal() const;

};

#include "BSTNode.cpp"

#endif