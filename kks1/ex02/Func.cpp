#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base        *generate(void)
{
    static unsigned int     my_seed;
    unsigned int            chice;

    srand(time(NULL) + my_seed);
    chice = (unsigned int)rand() % 3;
    my_seed++;
    if (!chice)
	{
		std::cout << "generate A!!" << std::endl;
        return (new A());
	}
    else if (chice == 1)
	{
		std::cout << "generate B!!" << std::endl;
        return (new B());
	}
    else
	{
		std::cout << "generate C!!" << std::endl;
        return (new C());
	}
}

void        identify_from_pointer( Base *p )
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else
        std::cout << "C" << std::endl;
}

void        identify_from_reference( Base &p )
{
    identify_from_pointer(&p);
}
