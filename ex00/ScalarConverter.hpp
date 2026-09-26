/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmario <dmario@student.42luanda.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 11:04:04 by dmario            #+#    #+#             */
/*   Updated: 2026/09/26 11:04:04 by dmario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

class ScalarConverter {
    public:
        static void convert(const char *str);

    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
        static bool convert_int(const char *str);
        static bool convert_char(const char *str);
        static bool convert_double(const char *str);
        static bool convert_float(const char *str);
        static bool convert_special(const char *str);
        static bool error();
        static void print(char ch_value, long int_value, float float_value, double doubel_value);
};

#endif
