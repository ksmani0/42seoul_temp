#include "Converter.hpp"

int     main(int argc, char *argv[])
{
    if (argc == 2)
    {
        try
        {
            Converter   num(argv[1]);

            try
            {
                unsigned char   out = num.to_uchar();

                std::cout << "char: " << '\'' << out << '\'' << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cout << "char: " << e.what() << std::endl;
            }

            try
            {
                int             out = num.to_int();

                std::cout << "int: " << out << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cout << "int: " << e.what() << std::endl;
            }

            
            try
            {
                float           out = num.to_float();

                std::cout << "float: " << std::fixed << std::setprecision(1) << out << "f" << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cout << "float: " << e.what() << std::endl;
            }

            try
            {
                double          out = num.to_double();

                std::cout << "double: " << std::fixed << std::setprecision(1) << out << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cout << "double: " << e.what() << std::endl;
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    } 
    return (0);
}