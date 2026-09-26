#include "ScalarConverter.hpp"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <limits>

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void) other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other){
    (void) other;
    return *this;
}

ScalarConverter::~ScalarConverter(){}

void ScalarConverter::print(char ch_value, long int_value, float float_value, double double_value){
    if (int_value < std::numeric_limits<char>::min() || int_value > std::numeric_limits<char>::max())
        std::cout << "char: " << "impossible" << std::endl;
    else if(!isprint(int_value))
        std::cout << "char: " << "Non displayable" << std::endl;
    else
        std::cout << "char: " << "'" << ch_value << "'" << std::endl;

    bool is_integer = double_value == std::floor(double_value);

    std::cout << std::fixed;

    if(double_value < std::numeric_limits<int>::min() || double_value > std::numeric_limits<int>::max())
        std::cout << "int: " << "impossible" << std::endl;
    else
        std::cout << "int: " << int_value << std::endl;

    std::cout << std::setprecision(is_integer ? 1 : 7);
    if(double_value < -std::numeric_limits<float>::max() || double_value > std::numeric_limits<float>::max())
        std::cout << "float: " << "impossible" << std::endl;
    else
        std::cout << "float: " << float_value << 'f' << std::endl;

    std::cout << std::setprecision(is_integer ? 1 : 16);
    std::cout << "double: " << double_value << std::endl;
}
bool ScalarConverter::convert_char(const char *str){
   std::string sstr(str);
   char ch = '\0';

   if(sstr.size() && sstr[sstr.size()-1] == '\'')
    sstr.erase(sstr.size() - 1);
   else 
    return false;
   if(sstr[0] == '\'')
    sstr.erase(0,1);
   else
    return false;
   if(!sstr.size() || sstr.size() > 1) return false;
   ch = sstr[0];
   print(static_cast<char>(ch), static_cast<long>(ch), static_cast<float>(ch), static_cast<double>(ch));

   return true;
}

bool ScalarConverter::convert_double(const char *str){
    std::string value(str);
    std::stringstream sstream(value);
    double num;
    size_t i = 0;
    if(value[i] == '-' || value[i] == '+')
        i++;
    if(value[i] == '.')
        return false;
    for(; value[i] && value[i] != '.'; i++)
        if(!isdigit(value[i]))
            return false;
    if(value[i++] != '.') return false;
    if(!value[i]) return false;
    for(; i < value.size(); i++)
        if(!isdigit(value[i]))
            return false;
    sstream >> num;
    if(sstream.fail()) return false;
    print(static_cast<char>(num), static_cast<long>(num), static_cast<float>(num), static_cast<double>(num));
    
    return true;
}

bool ScalarConverter::convert_float(const char *str){
    std::string value(str);
    if(!value.size() || value[value.size() - 1] != 'f') return false;
    value.erase(value.size() - 1 );
    std::stringstream sstream(value);
    float num;
    size_t i = 0;
    if(value[i] == '-' || value[i] == '+')
        i++;
    if(value[i] == '.')
        return false;
    for(; value[i] && value[i] != '.'; i++)
        if(!isdigit(value[i]))
            return false;
    if(value[i++] != '.') return false;
    if(!value[i]) return false;
    for(; i < value.size(); i++)
        if(!isdigit(value[i]))
            return false;
    sstream >> num;
    if(sstream.fail()) return false;
    
    print(static_cast<char>(num), static_cast<long>(num), static_cast<float>(num), static_cast<double>(num));
    
    return true;
}

bool ScalarConverter::convert_special(const char *str){
    std::string sstr(str);
    bool flag = false;
    if(sstr == "nan") flag = true;
    if(sstr == "nanf") flag = true;
    if(sstr == "+inf") flag = true;
    if(sstr == "-inf") flag = true;
    if(sstr == "-inff") flag = true;
    if(sstr == "+inff") flag = true;

    if(!flag) return false;
    if(sstr == "nanf") sstr.erase(sstr.size() - 1);
    if(sstr == "+inff") sstr.erase(sstr.size() - 1);
    if(sstr == "-inff") sstr.erase(sstr.size() - 1);

    std::cout << "char: " << "impossible" << std::endl;
    std::cout << "int: " << "impossible" << std::endl;
    std::cout << "float: " << sstr << 'f' << std::endl;
    std::cout << "double: " << sstr << std::endl;

    return true;
}



bool ScalarConverter::error(){
    std::cout << "char: " << "impossible" << std::endl;
    std::cout << "int: " << "impossible" << std::endl;
    std::cout << "float: " << "impossible" << std::endl;
    std::cout << "double: " << "impossible" << std::endl;

    return true;
}

bool ScalarConverter::convert_int(const char *str){
    std::string value(str);
    std::stringstream sstream(value);
    int num;

    if(str[0] != '-' && str[0] != '+' && !isdigit(str[0]))
        return false;
    for(size_t i = 1; i < value.size(); i++)
        if(!isdigit(value[i]))
            return false;
    sstream >> num;
    if(sstream.fail()) return false;

    print(static_cast<char>(num), static_cast<long>(num), static_cast<float>(num), static_cast<double>(num));

    return true;
}

void ScalarConverter::convert(const char *str) {
    bool flag = false;
    flag = convert_char(str);
    if(!flag) flag = convert_int(str);
    if(!flag) flag = convert_double(str);
    if(!flag) flag = convert_float(str);
    if(!flag) flag = convert_special(str);
    if(!flag) error();
}
