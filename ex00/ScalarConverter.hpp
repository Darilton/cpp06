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
};

#endif
