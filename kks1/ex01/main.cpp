#include "Data.hpp"

int         main(void)
{
    void    *tester = serialize();
	Data	*remv_p = reinterpret_cast<Data *>(tester);
    Data    *sample = deserialize(tester);

	std::cout << "=======size of void *=========" << std::endl;
	std::cout << sizeof(*remv_p)<< std::endl;
	std::cout << "s1: " << sizeof(remv_p->s1)<< std::endl;
	std::cout << "n:  " << sizeof(remv_p->n)<< std::endl;
	std::cout << "s2: " << sizeof(remv_p->s2)<< std::endl;
	std::cout << "=======origin=========" << std::endl;
    std::cout << remv_p->s1 << "  " << remv_p->n << "  " << remv_p->s2 << std::endl;
	std::cout << "=======decoded=========" << std::endl;
    std::cout << sample->s1 << "  " << sample->n << "  " << sample->s2 << std::endl;
    
    delete remv_p;
    delete sample;
    return (0);
}
