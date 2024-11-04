#ifndef BST_NODE_HPP
#define BST_NODE_HPP

#include <iostream>
using namespace std;

template <class T>
class BSTNode {
public:
    T data;
    BSTNode<T>* left;
    BSTNode<T>* right;

                BSTNode(const T& value);       
                BSTNode(const T& value, BSTNode<T>* left, BSTNode<T>* right);                                     
                BSTNode(const BSTNode<T>& other);      
    BSTNode<T>& operator=(const BSTNode<T>& other); 
         
    BSTNode<T>* treeMin();
    BSTNode<T>* treeMax();
    void        printPreOrderTraversal() const;
    void        printInOrderTraversal() const;
    void        printPostOrderTraversal() const;
};

#endif