#pragma once

#include <iostream>

class my_exception : public std::exception {
private:
    char* m_error;
public:
    explicit my_exception(char* error)
            : m_error(error) {}
    const char* what() const noexcept override { return m_error; }
};
