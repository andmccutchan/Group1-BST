#ifndef CUSTOM_EXCEPTIONS_HPP
#define CUSTOM_EXCEPTIONS_HPP

#include <exception>
using namespace std;

class value_not_in_tree_exception : public exception {
public:
    const char* what() const noexcept override { 
        return "Value not found in the tree.";
    }
};

class empty_tree_exception : public exception {
public:
    const char* what() const noexcept override { 
        return "The tree is empty.";
    }
};

#endif 
