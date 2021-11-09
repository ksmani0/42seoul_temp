#include "ScalarConversion.hpp"

ScalarConversion::ScalarConversion(void)
: mValue(""), mDouble(0), mNan(false), mInf(false) {}
ScalarConversion::ScalarConversion(std::string value) : mValue(value)
{
    mDouble = atof(value.c_str());
    mNan = isnan(mDouble);//C99 매크로
    if (value == "nan")
        mNan = true;
    mInf = isinf(mDouble);
    if (value == "+inf" || value == "inf" || value == "-inf")
        mInf = true;
}
ScalarConversion::ScalarConversion(const ScalarConversion& ref)
: mValue(ref.mValue), mDouble(ref.mDouble), mNan(ref.mNan), mInf(ref.mInf) {}

ScalarConversion& ScalarConversion::operator=(const ScalarConversion& ref)
{
    mValue = ref.mValue;
    mDouble = ref.mDouble;
    mNan = ref.mNan;
    mInf = ref.mInf;
    return *this;
}

//////////

void ScalarConversion::ToChar(void) const
{
    std::cout << "char: ";
    try
    {
        if (mDouble < 0 || mNan == true || mInf == true)
            throw ConversionException("impossible");
        
        char result = static_cast<char>(mDouble);
        if (result < 32 || result > 122)
            throw ConversionException("Non displayable");
        std::cout << "'" << static_cast<char>(mDouble) << "'\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }    
}
void ScalarConversion::ToInt(void) const
{
    std::cout << "int: ";
    try
    {
        if (mNan == true || mInf == true)
            throw ConversionException("impossible");
        std::cout << static_cast<int>(mDouble) << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }    
}
void ScalarConversion::ToFloat(void) const
{
    std::cout << "float: ";
    try
    {
        if (mNan == true)
            throw ConversionException("nanf");
        else if (mInf == true && mDouble < 0)
            throw ConversionException("-inff");
        else if (mInf == true)
            throw ConversionException("+inff");

        float fValue = static_cast<float>(mDouble);
        if (fValue - static_cast<int>(fValue) == 0.0f)
            std::cout << fValue << ".0f\n";
        else
            std::cout << fValue << "f\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
void ScalarConversion::ToDouble(void) const
{
    std::cout << "double: ";
    try
    {
        if (mNan == true)
            throw ConversionException("nan");
        else if (mInf == true && mDouble < 0)
            throw ConversionException("-inf");
        else if (mInf == true)
            throw ConversionException("+inf");

        if (mDouble - static_cast<int>(mDouble) == 0.0)
            std::cout << mDouble << ".0\n";
        else
            std::cout << mDouble << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }    
}

//////////

ScalarConversion::ConversionException::ConversionException(std::string m)
: mMessage(m) {}
const char* ScalarConversion::ConversionException::what(void) const throw()
{
    return mMessage.c_str();
}
ScalarConversion::ConversionException::~ConversionException(void) throw() {}

//////////

ScalarConversion::~ScalarConversion(void) {}

/*
        double difference = mDouble - static_cast<int>(mDouble);
        std::stringstream s(mDouble);
        std::string str(s.str());

        if (mDouble == 0 || difference == 0)
            std::cout << mDouble << ".0\n";
        else if (difference != 0 || str.find('.') != std::string::npos)
            std::cout << mDouble << "\n";
        else if (str.find('.') == std::string::npos)
            std::cout << mDouble << ".0\n";
*/