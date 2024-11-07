mytests: tree mytests.cpp BST.hpp BST.cpp RBTree.hpp RBTree.cpp customexceptions.hpp
	g++ -std=c++17 -c mytests.cpp -o mytests.o
	g++ -std=c++17 -o mytests BST.o mytests.o 
	./myTests

tree: BST.hpp BST.cpp RBTree.hpp RBTree.cpp
	g++ -std=c++17 -c BST.cpp -o BST.o
	g++ -std=c++17 -c RBTree.cpp -o RBTree.o