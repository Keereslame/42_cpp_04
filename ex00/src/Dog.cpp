/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 04:02:53 by alexis            #+#    #+#             */
/*   Updated: 2026/02/28 04:15:06 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Default Dog constructor called." << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
	std::cout << copy._type << " created with copy constructor." << std::endl;
}

Dog& Dog::operator=(const Dog& copy)
{
	if (this != &copy)
	{
		_type = copy._type;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << _type << " destructor called." << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Wouaf Wouaf!" << std::endl;
}