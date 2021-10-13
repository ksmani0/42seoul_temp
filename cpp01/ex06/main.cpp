#include "Karen.hpp"

int main(int ac, char* av[])
{
    if (ac != 2)
    {
        std::cout << "Invalid number of arguments!\n";
        return 0;
    }

    Karen karen;
    karen.complain(av[1]);

    return 0;
}
/*
std::string table[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
std::string* p = std::find(table, table + 4, av[1]);
int idx = p - table;

switch (idx)
	{
	case 0:
		karen.debug();
        break;
	case 1:
		karen.info();
        break;
	case 2:
		karen.warning();
        break;
	case 3:
		karen.error();
        break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]\n";
		break;
	}
*/