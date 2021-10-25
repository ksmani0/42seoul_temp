#include "Brain.hpp"

Brain::Brain(void) : num(0) {}
Brain::Brain(const Brain& ref) : num(ref.num)
{
    for (unsigned int i = 0; i < ref.num; ++i)
        ideas[i] = ref.ideas[i];
}

Brain& Brain::operator=(const Brain& ref)
{
    for (unsigned int i = 0; i < ref.num; ++i)
        ideas[i] = ref.ideas[i];
    num = ref.num;

    return *this;
}
bool Brain::AddIdea(std::string idea)
{
    if (num == 100)
    {
        std::cout << "My head already full!\n";
        return false;
    }
    this->ideas[num] = idea;
    ++num;
    return true;
}

Brain::~Brain(void) {}