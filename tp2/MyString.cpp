#include "MyString.hpp"

#include <iostream>
#include <cassert>

MyString::MyString() : length(0), chain(new char[1]) {
    std::cout << "MyString::MyString()\n";
    chain[0] = '\0';
}

MyString::MyString(const MyString & string) : length(getCharsLen(string.chain)), chain(new char[length+1]) {
    std::cout << "MyString::MyString(const MyString & string)\n";
    unsigned int i = 0;
    while(string.chain[i] != '\0') {
        chain[i] = string.chain[i];
        ++i;
    }
    chain[i] = '\0';
}

MyString::MyString(MyString && string) : length(getCharsLen(string.chain)), chain(string.chain) {
    std::cout << "MyString::MyString(MyString && string)\n";
    string.chain = nullptr;
}

MyString::MyString(const char* chars) : length(getCharsLen(chars)), chain(new char[length+1]) {
    std::cout << "MyString::MyString(const char* chars)\n";
    unsigned int i = 0;
    while(chars[i] != '\0') {
        chain[i] = chars[i];
        ++i;
    }
    chain[i] = '\0';
}

MyString::MyString(char c) : length(1), chain(new char[2]) {
    std::cout << "MyString::MyString(char c)\n";
    chain[0] = c;
    chain[1] = '\0';
}

MyString::~MyString() {
    std::cout << "MyString::~MyString()\n";
    if (chain) delete [] chain;
}

const MyString & MyString::operator=(const MyString & string) {
    std::cout << "const MyString & MyString::operator=(const MyString & string)\n";
    if (this != &string) {
        if (chain) delete [] chain;
        chain = new char(*string.chain);
    }
    return *this;
}

const MyString & MyString::operator=(MyString && string) {
    std::cout << "const MyString & MyString::operator=(MyString && string)\n";
    if (this != &string) {
        if (chain) delete [] chain;
        chain = string.chain;
        string.chain = nullptr;
    }
    return *this;
}

std::ostream & operator<<(std::ostream & os, const MyString & string) {
    std::cout << "const MyString & MyString::operator=(MyString && string)\n";
    unsigned int i = 0;
    while(string.chain[i] != '\0') {
        os << string.chain[i];
        ++i;
    }
    return os;
}

char MyString::operator[](unsigned int i) const {
    std::cout << "char MyString::operator[](unsigned int i) const\n";
    assert(i < getCharsLen(chain));
    return chain[i];
}

char & MyString::operator[](unsigned int i) {
    std::cout << "char & MyString::operator[](unsigned int i)\n";
    assert(i < getCharsLen(chain));
    return chain[i];
}

unsigned int MyString::getCharsLen(const char* chars) {
    unsigned int i = 0;
    while(chars[i] != '\0') {
        ++i;
    }
    return i;
}