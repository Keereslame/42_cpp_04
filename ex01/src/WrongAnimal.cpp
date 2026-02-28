/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 03:26:12 by alexis            #+#    #+#             */
/*   Updated: 2026/02/28 04:43:52 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) : _type(copy._type)
{
	std::cout << _type << " created from a copy." << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) : _type(type)
{
	std::cout << "Aniaml created." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy)
{
	std::cout << _type << " called assignement operator." << std::endl;
	if (this != &copy)
	{
		_type = copy._type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called." << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << _type << " make a wrong sound..." << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (_type);
}