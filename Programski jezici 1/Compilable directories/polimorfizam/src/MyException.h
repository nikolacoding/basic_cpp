#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <exception>
#include <string>

class MyException : public std::exception {
private:
    std::string m_message;

public:
    MyException(std::string message) : m_message(message) {}

    const char* what() const throw(){
        return m_message.c_str();
    }
};

#endif