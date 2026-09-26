/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmario <dmario@student.42luanda.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 11:03:46 by dmario            #+#    #+#             */
/*   Updated: 2026/09/26 11:03:47 by dmario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char **argv){
    if(argc != 2){
        std::cout << "Error" << std::endl;
        std::cout << "Usage: " << argv[0] << " <Value to convert>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}
