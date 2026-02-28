/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 03:26:12 by alexis            #+#    #+#             */
/*   Updated: 2026/02/28 04:25:20 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(const Animal& copy) : _type(copy._type)
{
	std::cout << _type << " created from a copy." << std::endl;
}

Animal::Animal(const std::string& type) : _type(type)
{
	std::cout << "Aniaml created." << std::endl;
}

Animal& Animal::operator=(const Animal& copy)
{
	std::cout << _type << " called assignement operator." << std::endl;
	if (this != &copy)
	{
		_type = copy._type;
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called." << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << _type << " make a sound..." << std::endl;
}

std::string Animal::getType() const
{
	return (_type);
}