#ifndef RBTREE_NODE_HPP
#define RBTREE_NODE_HPP

#include <iostream>
using namespace std;

template <class T>
class RBTreeNode {
	public:
        T data;
        RBTreeNode<T>* left;
        RBTreeNode<T>* right;

        bool color;                             //Black = True, Red = False

                    RBTreeNode(const T& value);
                    RBTreeNode(const T& value, RBTreeNode<T>* left, RBTreeNode<T>* right);
                    RBTreeNode(const RBTreeNode<T>& other);
        RBTreeNode<T>& operator=(const RBTreeNode<T>& other);

        RBTreeNode<T>* treeMin();
        RBTreeNode<T>* treeMax();
        void        printPreOrderTraversal() const;
        void        printInOrderTraversal() const;
        void        printPostOrderTraversal() const;
};

#endif
