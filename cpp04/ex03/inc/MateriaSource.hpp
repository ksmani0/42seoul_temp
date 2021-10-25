#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
    AMateria* mInventory[4];//추상클래스이므로 포인터 써야 함

    MateriaSource();
    MateriaSource(const MateriaSource& ref);

    MateriaSource& operator=(MateriaSource const& ref);
    void learnMateria(AMateria* m);
    AMateria* createMateria(std::string const& type);

    ~MateriaSource();
};

#endif