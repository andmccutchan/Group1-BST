#include <iostream>
#include "BST.cpp"
#include "BSTNode.cpp"
using namespace std;

void testBST();

int main(void){
    testBST();
    return 0;
}

void testBST() {
    BST<int> bst;
    cout << "Size of bst: " << bst.size() << endl;
    cout << "Inserting 7, 5, 18, 1, 4, 9, 12" << endl;
    bst.insert(7);
    bst.insert(5);
    bst.insert(18);
    bst.insert(1);
    bst.insert(4);
    bst.insert(9);
    bst.insert(12);
    bst.insert(19);

    cout << "Size of bst: " << bst.size() << endl;

    cout << "Print In-order traversal: ";
    bst.printInOrderTraversal();
    cout << endl;

    cout << "Removing..." << endl;
    cout << bst.size() << endl;
    bst.remove(19);
    cout << bst.size() << endl;
    bst.remove(18);
    cout << bst.size() << endl;
    bst.remove(12);
    cout << bst.size() << endl;
    bst.remove(9);
    cout << bst.size() << endl;
    bst.remove(7);
    cout << bst.size() << endl;
    bst.remove(5);
    cout << bst.size() << endl;
    bst.remove(4);
    cout << bst.size() << endl;
    bst.remove(1);
    cout << bst.size() << endl;
    cout << "Print In-order traversal: ";
    bst.printInOrderTraversal();
    cout << endl;
    // cout << "Print Pre-order traversal: ";
    // bst.printPreOrderTraversal();
    // cout << endl;
    // cout << "Print Post-order traversal: ";
    // bst.printPostOrderTraversal();
    // cout << endl;
    

    cout << "Min of tree: " << bst.treeMin()->data << endl;
    cout << "Max of tree: " << bst.treeMax()->data << endl;

    // cout << "Searching for 4 in tree: " << bst.search(4)->data << endl;



}