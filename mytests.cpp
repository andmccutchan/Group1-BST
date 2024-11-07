#include <iostream>
#include "BST.cpp"
#include "BSTNode.cpp"
#include "RBTree.cpp"
#include "RBTreeNode.cpp"
using namespace std;

void testBST_insert(int &passCounter);
void testBST_remove(int &passCounter);
void testBST_search(int &passCounter);
void testBST_min_max(int &passCounter);

int main(void){
    int passCounter = 0;

    // BST Tests
    testBST_insert(passCounter);
    testBST_remove(passCounter);
    testBST_search(passCounter);
    testBST_min_max(passCounter);

    // RBT Tests
    // ...

    cout << "Total tests passed: " << passCounter << endl;

    return 0;
}

void testBST_insert(int &passCounter) {
    cout << "TEST CODE FOR BST INSERTION" << endl;
    cout << "===========================" << endl;
    cout << "Inserting 5, 9, 2, 4, 7, 1, 10..." << endl;
    BST<int> tree;
    tree.insert(5);
    tree.insert(9);
    tree.insert(2);
    tree.insert(4);
    tree.insert(7);
    tree.insert(1);
    tree.insert(10);
    cout << "Tree size: " << tree.size() << endl;
    cout << "Pre-order traversal: "; 
    tree.printPreOrderTraversal(); 
    cout << endl;
    cout << "In-order traversal: "; 
    tree.printInOrderTraversal(); 
    cout << endl;
    cout << "Post-order traversal: "; 
    tree.printPostOrderTraversal(); 
    cout << endl;
    cout << "===========================" << endl;
    cout << endl;
    passCounter++;
}

void testBST_remove(int &passCounter) {
    cout << "TEST CODE FOR BST REMOVE" << endl;
    cout << "===========================" << endl;
    cout << "Inserting 5, 9, 2, 4, 7, 1, 10..." << endl;
    BST<int> tree;
    tree.insert(5);
    tree.insert(9);
    tree.insert(2);
    tree.insert(4);
    tree.insert(7);
    tree.insert(1);
    tree.insert(10);
    cout << "Tree size: " << tree.size() << endl;
    cout << "Pre-order traversal: "; 
    tree.printPreOrderTraversal(); 
    cout << endl;
    cout << "In-order traversal: "; 
    tree.printInOrderTraversal(); 
    cout << endl;
    cout << "Post-order traversal: "; 
    tree.printPostOrderTraversal(); 
    cout << endl;
    cout << "Removing 4..." << endl;
    tree.remove(4);
    cout << "Tree size: " << tree.size() << endl;
    cout << "Pre-order traversal: "; 
    tree.printPreOrderTraversal(); 
    cout << endl;
    cout << "In-order traversal: "; 
    tree.printInOrderTraversal(); 
    cout << endl;
    cout << "Post-order traversal: "; 
    tree.printPostOrderTraversal(); 
    cout << endl;
    cout << "===========================" << endl;
    cout << endl;
    passCounter++;
}

void testBST_search(int &passCounter) {
    cout << "TEST CODE FOR BST SEARCH" << endl;
    cout << "===========================" << endl;
    cout << "Inserting 5, 9, 2, 4, 7, 1, 10..." << endl;
    BST<int> tree;
    tree.insert(5);
    tree.insert(9);
    tree.insert(2);
    tree.insert(4);
    tree.insert(7);
    tree.insert(1);
    tree.insert(10);
    cout << "Searching for 7: ";
    (tree.search(7) != nullptr) ? cout << "Found!" << endl :  cout << "Not found :(" << endl;
    cout << "Searching for 6: ";
    (tree.search(6) != nullptr) ? cout << "Found!" << endl :  cout << "Not found :(" << endl;

    cout << "===========================" << endl;
    cout << endl;
    passCounter++;
}

void testBST_min_max(int &passCounter) {
    cout << "TEST CODE FOR BST MIN/MAX" << endl;
    cout << "===========================" << endl;
    cout << "Inserting 5, 9, 2, 4, 7, 1, 10..." << endl;
    BST<int> tree;
    tree.insert(5);
    tree.insert(9);
    tree.insert(2);
    tree.insert(4);
    tree.insert(7);
    tree.insert(1);
    tree.insert(10);
    BSTNode<int>* min = tree.treeMin();
    cout << "Tree Min: " << min->data << endl;
    BSTNode<int>* max = tree.treeMax();
    cout << "Tree Max: " << max->data << endl;

    cout << "===========================" << endl;
    cout << endl;
    passCounter++;
}


