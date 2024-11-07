mytests: tree mytests.cpp BST.hpp BST.cpp RBTree.hpp RBTree.cpp customexceptions.hpp
	g++ -c mytests.cpp -o mytests.o
	g++ -o mytests BST.o mytests.o 
	./myTests

tree: BST.hpp BST.cpp RBTree.hpp RBTree.cpp
	g++ -c BST.cpp -o BST.o
	g++ -c RBTree.cpp -o RBTree.o