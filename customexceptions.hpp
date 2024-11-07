#ifndef CUSTOMEXCEPTIONS_HPP
#define CUSTOMEXCEPTIONS_HPP

#include <exception>
using namespace std;

class value_not_in_tree_exception : public exception {
    private:

        const char* message;

    public:

        value_not_in_tree_exception(const char * msg) : message(msg) {}

        const char* what() const throw() {
            return message;
        }
};

class empty_tree_exception : public exception {
    private:

        const char* message;

    public:

        empty_tree_exception(const char * msg) : message(msg) {}

        const char* what() const throw() {
            return message;
        }
};


#endif 
