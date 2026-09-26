/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmario <dmario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 10:43:27 by dmario            #+#    #+#             */
/*   Updated: 2026/09/26 10:29:45 by dmario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr){
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}

Serializer::Serializer(){}

Serializer::Serializer(const Serializer& other) {
    (void) other;
}

Serializer& Serializer::operator=(const Serializer& other){
    (void) other;
    return *this;
}

Serializer::~Serializer(){}

