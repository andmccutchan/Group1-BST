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
void testRBTree_insert(int &passCounter);
void testRBTree_remove(int &passCounter);
void testRBTree_search(int &passCounter);
void testRBTree_min_max(int &passCounter);

int main(void){
    int passCounter = 0;
    cout << "this is working" << endl;
    // BST Tests
    // testBST_insert(passCounter);
    // testBST_remove(passCounter);
    // testBST_search(passCounter);
    // testBST_min_max(passCounter);

    // RBT Tests
    testRBTree_insert(passCounter);
    testRBTree_remove(passCounter);
    testRBTree_search(passCounter);
    testRBTree_min_max(passCounter);

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

void testRBTree_insert(int &passCounter){
    cout << "Test Code for Insert" << endl;
    cout << "===========================" << endl;
    cout << "Inserting 15, 22, 18, 10, 5, 8, 30..." << endl;
    RBTree<int> RBTree;
    RBTree.insert(15);
    RBTree.insert(22);
    RBTree.insert(18);
    RBTree.insert(10);
    RBTree.insert(5);
    RBTree.insert(8);
    RBTree.insert(30);

    cout << "Tree size: " << RBTree.size() << endl;

    cout << "Pre-Order traversal: ";
    RBTree.printPreOrderTraversal();
    cout << endl;
    cout << "In-Order traversal: ";
    RBTree.printInOrderTraversal();
    cout << endl;
    cout << "Post-Order traversal: ";
    RBTree.printPostOrderTraversal();
    
    cout << endl;
    cout << "===========================" << endl;
    cout << endl;
    passCounter++;
}

void testRBTree_remove(int &passCounter){
    cout << "Test Code for Remove" << endl;
    cout << "===========================" << endl;
    cout << "Inserting 15, 22, 18, 10, 5, 8, 30..." << endl;
    RBTree<int> RBTree;
    RBTree.insert(15);
    RBTree.insert(22);
    RBTree.insert(18);
    RBTree.insert(10);
    RBTree.insert(5);
    RBTree.insert(8);
    RBTree.insert(30);

    cout << "Tree size: " << RBTree.size() << endl;
    cout << "Pre-Order traversal: ";

    RBTree.printPreOrderTraversal();
    cout << endl;
    cout << "In-Order traversal: ";
    RBTree.printInOrderTraversal();
    cout << endl;
    cout << "Post-Order traversal: ";
    RBTree.printPostOrderTraversal();
    cout << endl;

    cout << "Remove 10..." << endl;
    RBTree.remove(10);

    cout << "New Tree Size: " << RBTree.size() << endl;

    cout << "In-Order traversal: ";
    RBTree.printInOrderTraversal();
    cout << endl;
    cout << "Post-Order traversal: ";
    RBTree.printPostOrderTraversal();

    cout << endl;
    cout << "===========================" << endl;
    cout << endl;
    passCounter++;
}

void testRBTree_search(int &passCounter){
    cout << "Test Code for Search" << endl;
    cout << "===========================" << endl;
    cout << "Inserting 15, 22, 18, 10, 5, 8, 30..." << endl;
    RBTree<int> RBTree;
    RBTree.insert(15);
    RBTree.insert(22);
    RBTree.insert(18);
    RBTree.insert(10);
    RBTree.insert(5);
    RBTree.insert(8);
    RBTree.insert(30);

    cout << "Search for the value 18..." << endl;
    (RBTree.search(18) != nullptr) ? cout << "Found!" << endl : cout << "Not Found" << endl;
    cout << "Search for the value 5..." << endl;
    (RBTree.search(5) != nullptr) ? cout << "Found!" << endl : cout << "Not Found" << endl;

    cout << "===========================" << endl;
    cout << endl;
    passCounter++;
}

void testRBTree_min_max(int &passCounter){
    cout << "Test Code for Minimum and Maximum" << endl;
    cout << "===========================" << endl;
    cout << "Inserting 15, 22, 18, 10, 5, 8, 30..." << endl;
    RBTree<int> RBTree;
    RBTree.insert(15);
    RBTree.insert(22);
    RBTree.insert(18);
    RBTree.insert(10);
    RBTree.insert(5);
    RBTree.insert(8);
    RBTree.insert(30);

    RBTreeNode<int>* RBTmin = RBTree.treeMin();
    cout << "Tree Min: " << RBTmin -> data << endl;

    RBTreeNode<int>* RBTmax = RBTree.treeMax();
    cout << "Tree Max: " << RBTmax -> data << endl;

    cout << "===========================" << endl;
    cout << endl;
    passCounter++;
}
