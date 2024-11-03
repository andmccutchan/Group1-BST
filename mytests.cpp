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
    cout << "Inserting 7, 5, 18, 1, 4, 9, 12" << endl;
    bst.insert(7);
    bst.insert(5);
    bst.insert(18);
    bst.insert(1);
    bst.insert(4);
    bst.insert(9);
    bst.insert(12);

    cout << "Print In-order traversal: ";
    bst.printInOrderTraversal();
    cout << endl;

    cout << "Min of tree: " << bst.treeMin()->data << endl;
    cout << "Max of tree: " << bst.treeMax()->data << endl;

    cout << "Searching for 4 in tree: " << bst.search(4)->data << endl;



}