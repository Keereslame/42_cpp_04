/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 04:15:24 by alexis            #+#    #+#             */
/*   Updated: 2026/02/28 06:00:54 by alexis           ###   ########.fr       */
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
	{
		std::cout << "\n===== BASIC POLYMORPHISM TEST =====\n" << std::endl;

		const Animal* dog = new Dog();
		const Animal* cat = new Cat();

		std::cout << dog->getType() << " : ";
		dog->makeSound();

		std::cout << cat->getType() << " : ";
		cat->makeSound();

		delete dog;
		delete cat;

		std::cout << "\n===== END BASIC POLYMORPHISM TEST =====\n" << std::endl;
	}

	{
		std::cout << "\n===== DEEP COPY TEST =====\n" << std::endl;

		Dog original;
		original.setIdea(0, "I love bones");
		original.setIdea(1, "I love running");

		Dog copy = original;

		std::cout << "\nOriginal idea[0]: "
				<< original.getIdea(0) << std::endl;

		std::cout << "Copy idea[0]: "
				<< copy.getIdea(0) << std::endl;

		std::cout << "\n--- Modifying original brain ---\n" << std::endl;

		original.setIdea(0, "I love cats");

		std::cout << "Original idea[0]: "
				<< original.getIdea(0) << std::endl;

		std::cout << "Copy idea[0]: "
				<< copy.getIdea(0) << std::endl;

		std::cout << "\n===== ASSIGNMENT OPERATOR TEST =====\n" << std::endl;

		Dog another;
		another = original;

		std::cout << "Another idea[0]: "
				<< another.getIdea(0) << std::endl;

		std::cout << "\n===== END DEEP COPY TEST =====" << std::endl;
		std::cout << "\n===== END ASSIGNEMENT TEST =====\n" << std::endl;
	}

	{
		std::cout << "\n===== ARRAY TEST =====\n" << std::endl;

		Animal* animals[4];

		for (int i = 0; i < 4; i++)
		{
			if (i % 2 == 0)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}

		for (int i = 0; i < 4; i++)
			delete animals[i];

		std::cout << "\n===== END ARRAY TEST =====\n" << std::endl;
	}

	return 0;
}