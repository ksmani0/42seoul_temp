#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <cctype>
# include <climits>
# include <cmath>
# include <iomanip>

class Converter
{
    private:
        double _val;

    public:
        Converter(char *argv);
        ~Converter();
        Converter(Converter const &copy);
        Converter const &operator = (Converter const &obj);

        unsigned char   to_uchar(void) const;
        int             to_int(void) const;
        float           to_float(void) const;
        double          to_double(void) const;

        class ConvertException : public std::exception
        {
            private:
                const char  *_msg;

            public:
                ConvertException(const char *msg) throw();
                virtual ~ConvertException() throw();
                virtual const char *what() const throw();
        };
};

#endif