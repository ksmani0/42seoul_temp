#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int         main(void)
{
    Base    *test1 = generate();
    identify_from_pointer(test1);
    identify_from_reference(*test1);

    Base    *test2 = generate();
    identify_from_pointer(test2);
    identify_from_reference(*test2);

    Base    *test3 = generate();
    identify_from_pointer(test3);
    identify_from_reference(*test3);

    delete test1;
    delete test2;
    delete test3;

    return (0);
}
