#ifndef MYSTRING_H 
#define MYSTRING_H

#include <string>

class MyString {

private:
    unsigned int length;
    char* chain;

public:

    MyString();

    // Copy Constructor
    MyString(const MyString & string);

    // Move Constructor
    MyString(MyString && string);

    MyString(const char* chars);

    MyString(char c);

    ~MyString();

    // Copy Assignment
    const MyString & operator=(const MyString & string);

    // Move Assignment
    const MyString & operator=(MyString && string);

    friend std::ostream & operator<<(std::ostream & os, const MyString & string);

    char operator[](unsigned int i) const;

    char & operator[](unsigned int i);

    static unsigned int getCharsLen(const char* chars);

};

#endif