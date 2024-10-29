mytests: tree mytests.cpp BSTNode.hpp BSTNode.cpp
	g++ -c mytests.cpp -o mytests.o
	g++ -o mytests BSTNode.o mytests.o
	./myTests

tree: BSTNode.hpp BSTNode.cpp
	g++ -c BSTNode.cpp -o BSTNode.o