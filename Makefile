mytests: tree mytests.cpp BST.hpp BST.cpp 
	g++ -c mytests.cpp -o mytests.o
	g++ -o mytests BST.o mytests.o 
	./myTests

tree: BST.hpp BST.cpp 
	g++ -c BST.cpp -o BST.o