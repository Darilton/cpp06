#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

class ScalarConverter {
    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter operator=(const ScalarConverter& other);
        ~ScalarConverter();

        static void convert(const char *str);

    private:
        static bool convert_int(const char *str);
        static bool convert_char(const char *str);
        static bool convert_double(const char *str);
        static bool convert_float(const char *str);
        static bool convert_special(const char *str);
        static bool error();
        static void print(char ch_value, long long int_value, float float_value, double doubel_value);
};

#endif
