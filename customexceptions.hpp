#ifndef CUSTOMEXCEPTIONS_HPP
#define CUSTOMEXCEPTIONS_HPP

#include <exception>
using namespace std;


class value_not_in_tree_exception : public std::exception { 
public:
    const char* what() const noexcept override { 
        return "Value not found in the tree.";
    }
};

class empty_tree_exception : public std::exception { 
public:
    const char* what() const noexcept override { 
        return "The tree is empty.";
    }
};


#endif 