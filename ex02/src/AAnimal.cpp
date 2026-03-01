/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 03:26:12 by alexis            #+#    #+#             */
/*   Updated: 2026/03/01 18:31:41 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal")
{
	std::cout << "AAnimal default constructor called." << std::endl;
}

AAnimal::AAnimal(const AAnimal& copy) : _type(copy._type)
{
	std::cout << _type << " created from a copy." << std::endl;
}

AAnimal::AAnimal(const std::string& type) : _type(type)
{
	std::cout << "Aniaml created." << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& copy)
{
	std::cout << _type << " called assignement operator." << std::endl;
	if (this != &copy)
	{
		_type = copy._type;
	}
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called." << std::endl;
}

void	AAnimal::makeSound() const
{
	std::cout << _type << " make a sound..." << std::endl;
}

std::string AAnimal::getType() const
{
	return (_type);
}