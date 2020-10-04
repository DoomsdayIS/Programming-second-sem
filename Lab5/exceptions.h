
#ifndef LAB5_EXCEPTIONS_H
#define LAB5_EXCEPTIONS_H
#include <string>
#include <exception>

class QueueOverflowException : public std::exception {
    const char* what() const throw() override{
        return "Can't add a target! Queue is too full!";
    }
};

class EmptyQueueException : public std::exception {
    const char* what() const throw() override {
            return "Can't get a target! Queue is empty!";
    }
};


#endif //LAB5_EXCEPTIONS_H
