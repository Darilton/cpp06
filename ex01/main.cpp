/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmario <dmario@student.42luanda.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 10:46:19 by dmario            #+#    #+#             */
/*   Updated: 2026/09/24 11:25:27 by dmario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>
#include <stdint.h>

int main() {
    Data data;
    data.value = 42;

    uintptr_t serialized = Serializer::serialize(&data);

    Data* deserialized = Serializer::deserialize(serialized);

    std::cout << "Original value: " << data.value << std::endl;
    std::cout << "Deserialized value: " << deserialized->value << std::endl;
    std::cout << "Original Pointer: " << &data << std::endl;
    std::cout << "Deserialized Pointer: " << deserialized << std::endl;

    return 0;
}