#include "Karen.hpp"

Karen::Karen(void)
{
    f[0] = &Karen::debug;
    f[1] = &Karen::info;
    f[2] = &Karen::warning;
    f[3] = &Karen::error;
}

void Karen::complain(std::string level)
{
    std::string table[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    std::string* p = std::find(table, table + 4, level);//요소가 4개니까
    if (p == table + 4)
    {
        std::cout << "[ Probably complaining about insignificant problems ]\n";
        return;
    }

    (this->*f[p - table])();
}

void Karen::debug(void)
{
    std::cout << "[ DEBUG ]\n" << 
    "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!\n";
}

void Karen::info(void)
{
    std::cout << "[ INFO ]\n" <<
    "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!\n";
}

void Karen::warning(void)
{
    std::cout << "[ WARNING ]\n" <<
    "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month.\n";
}

void Karen::error(void)
{
    std::cout << "[ ERROR ]\n" <<
    "This is unacceptable, I want to speak to the manager now.\n";
}