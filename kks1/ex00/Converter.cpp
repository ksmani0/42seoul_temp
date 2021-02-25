#include "Converter.hpp"

Converter::Converter(char *argv)
{
    std::string str = std::string(argv);
    char        *last_idx;
    int         idx = 0;
    int         k8s = 0;

    while (argv[idx])
    {
        if (argv[idx] == '.')
            k8s = 1;
        idx++;
    }
    if (!idx)
        throw Converter::ConvertException("No input");
    if (idx == 3 && argv[0] == '\'' && argv[2] == '\'')
        _val = static_cast<double>(argv[1]);
    else if (str == "+inf" || str == "+inff")
        _val = INFINITY;
    else if (str == "-inf" || str == "-inff")
        _val = -INFINITY;
    else if (str == "nan" || str == "nanf")
        _val = nan("");
    else
    {
        strtod(argv, &last_idx);
        if (idx == 1 && *last_idx != 0)
            _val = static_cast<double>(argv[0]);
        else
        {
            if (*last_idx && *last_idx != 'f' && *last_idx != ' ')
            {
                throw Converter::ConvertException("Wrong input");
            }
            if (*last_idx == 'f')
            {
                k8s = 2;
                last_idx++;
            }
            while (*last_idx)
            {
                if (*last_idx != ' ')
                    throw Converter::ConvertException("Wrong input");
                last_idx++;
            }
            _val = atof(argv);
            if (!k8s && (_val > INT_MAX || _val < INT_MIN))
                throw Converter::ConvertException("INT: out of range");
            else if (k8s == 1 && (_val > __DBL_MAX__ || _val < -__DBL_MAX__))
                throw Converter::ConvertException("FLOAT: out of range");
            else if (k8s == 2 && (_val > __FLT_MAX__ || _val < -__FLT_MAX__))
                throw Converter::ConvertException("DOUBLE: out of range");
        }
    }
}

Converter::~Converter() {}

Converter::Converter(Converter const &copy)
{
    _val = copy.to_double();
}

Converter const &Converter::operator = (Converter const &obj)
{
    if (this == &obj)
        return (*this);
    _val = obj.to_double();
    return (*this);
}

unsigned char   Converter::to_uchar(void) const
{
    unsigned char ch;

    if (_val < CHAR_MIN || _val > CHAR_MAX || isnan(_val))
        throw Converter::ConvertException("impossible");
    ch = static_cast<unsigned char>(_val);
    if (std::isprint(ch))
        return (ch);
    else
        throw Converter::ConvertException("Non displayable");
    
}

int     Converter::to_int(void) const
{
    if (_val > INT_MAX || _val < INT_MIN || isnan(_val))
        throw Converter::ConvertException("impossible");
    else
        return (static_cast<int>(_val));
}

float   Converter::to_float(void) const
{
    if (_val != INFINITY && _val != -INFINITY && (_val > __FLT_MAX__ || _val < -__FLT_MAX__))
        throw Converter::ConvertException("impossible");
    return (static_cast<float>(_val));   
}

double  Converter::to_double(void) const
{
    return (_val);
}

Converter::ConvertException::ConvertException(const char *msg) throw() : _msg(msg) {}

Converter::ConvertException::~ConvertException() throw() {}

const char *Converter::ConvertException::what() const throw()
{
    return (_msg);
}