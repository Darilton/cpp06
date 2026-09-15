#include "ScalarConverter.hpp"
#include <iostream>
#include <cstring>
#include <sstream>

bool ScalarConverter::convert_char(const char *str){
   int i = 0;
   char ch = '\0';

   if(str[i++] != '\'') return false;
   if(str[i] != '\'' && str[i+1] != '\'') return false;
   if(str[i] != '\'') ch = str[1];

   std::cout << "char: " << ch << std::endl;
   std::cout << "int: " << static_cast<int>(ch) << std::endl;
   std::cout << "float: " << static_cast<float>(ch) << std::endl;
   std::cout << "double: " << static_cast<double>(ch) << std::endl;
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

    std::cout << "char: " << static_cast<char>(num) << std::endl;
    std::cout << "int: " << num << std::endl;
    std::cout << "float: " << static_cast<float>(num) << std::endl;
    std::cout << "double: " << static_cast<double>(num) << std::endl;

    return true;
}

void ScalarConverter::convert(const char *str) {
    bool flag = false;
    flag = convert_char(str);
    if(!flag) flag = convert_int(str);
    //if(!flag) flag = convert_float(str);
}
