#include <iostream>
#include <exception>

using namespace std;

class custom_exceptions : public std::exception {
    private:
        const char* message;

    public:
        custom_exceptions(const char* msg) : message(msg) {}

        const char* what() const throw() {
            return message;
        }
};