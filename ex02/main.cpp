/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmario <dmario@student.42luanda.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 11:36:18 by dmario            #+#    #+#             */
/*   Updated: 2026/09/24 15:16:01 by dmario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

Base *generate(void) {
    Base *base = NULL;

    int random = std::rand() % 3;
    if (random == 0)
        base = new A();
    else if (random == 1)
        base = new B();
    else
        base = new C();
    return base;
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        (void) a;
        } catch (std::exception&) {
        try {
            B& b = dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
            (void) b;
        } catch (std::exception&) {
            try {
                C& c = dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
                (void) c;
            } catch (std::exception&) {
                std::cout << "Unknown type" << std::endl;
            }
        }
    }
}

int main(void)
{
    std::srand(time(NULL));
    Base *base = generate();

    std::cout << "Identifying by pointer: ";
    identify(base);
    std::cout << "Identifying by reference: ";
    identify(*base);
    delete base;

    return 0;
}