#include <iostream>
#include <exception>

using namespace std;

class custom_exceptions : public std::exception {
    private:
    char * message;

    public:
    custom_exceptions(char * msg) : message(msg) {}
    char * what () {
        return message;
    }
};