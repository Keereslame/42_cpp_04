/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 04:15:24 by alexis            #+#    #+#             */
/*   Updated: 2026/02/28 04:45:47 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

int main()
{
	std::cout << "--------Test Animal class----------" << std::endl;
	std::cout << "--------	Creation	----------" << std::endl;
	const Animal* meta = new Animal();
	std::cout << "--------	Sound	----------" << std::endl;
	meta->makeSound();
	std::cout << "--------	Destruction	----------" << std::endl;
	delete meta;
	std::cout << std::endl;

	std::cout << "--------Test Dog class----------" << std::endl;
	std::cout << "--------	Creation	----------" << std::endl;
	const Animal* j = new Dog();
	std::cout << "--------	Sound	----------" << std::endl;
	std::cout << j->getType() << " : ";
	j->makeSound();
	std::cout << "--------	Destruction	----------" << std::endl;
	delete j;
	std::cout << std::endl;

	std::cout << "--------Test Cat class----------" << std::endl;
	std::cout << "--------	Creation	----------" << std::endl;
	const Animal* i = new Cat();
	std::cout << "--------	Sound	----------" << std::endl;
	std::cout << i->getType() << " : ";
	i->makeSound();
	std::cout << "--------	Destruction	----------" << std::endl;
	delete i;
	std::cout << std::endl;

	std::cout << "--------Test WrongAnimal class----------" << std::endl;
	std::cout << "--------	Creation	----------" << std::endl;
	const WrongAnimal* k = new WrongAnimal();
	std::cout << "--------	Sound	----------" << std::endl;
	std::cout << k->getType() << " : ";
	k->makeSound();
	std::cout << "--------	Destruction	----------" << std::endl;
	delete k;
	std::cout << std::endl;

	std::cout << "-------- Test WrongCat class --------" << std::endl;
	std::cout << "--------	Creation	----------" << std::endl;
	const WrongAnimal* l = new WrongCat();
	std::cout << "--------	Sound	----------" << std::endl;
	std::cout << l->getType() << " : ";
	l->makeSound();
	std::cout << "--------	Destruction	----------" << std::endl;
	delete l;
	std::cout << std::endl;

	return (0);
}