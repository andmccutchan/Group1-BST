#include <iostream>
#include "BST.hpp"
using namespace std;

void testBST() {
    BST<int> tree;

    // Insert elements into the BST
    std::cout << "Inserting elements: 50, 30, 70, 20, 40, 60, 80\n";
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
}


int main(void){
    
    testBST();
    return 0;  
}