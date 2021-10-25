#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
    public:
    std::string ideas[100];
    unsigned int num;

    Brain();
    Brain(const Brain& ref);

    Brain& operator=(const Brain& ref);
    bool AddIdea(std::string idea);
    ~Brain();
};

#endif