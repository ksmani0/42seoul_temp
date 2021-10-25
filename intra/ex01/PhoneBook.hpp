#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Contact.hpp"

enum
{
    SIZE = 8
};

class PhoneBook
{
    public:
    static int mNum;
    int mIndex;
    Contact mList[SIZE];

    PhoneBook();
    void AddList();
    void PrintListDigit(const std::string s, bool isEnd) const;
    void ShowAllList() const;
    void ShowOneContact() const;
};

#endif
