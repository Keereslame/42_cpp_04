/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 04:02:53 by alexis            #+#    #+#             */
/*   Updated: 2026/03/01 18:41:35 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Dog.hpp"

Dog::Dog() : AAnimal("Dog")
{
	std::cout << "Default Dog constructor called." << std::endl;
	_brain = new Brain();
}

Dog::Dog(const Dog& copy) : AAnimal(copy)
{
	std::cout << copy._type << " created with copy constructor." << std::endl;
	_brain = new Brain(*copy._brain);
}

Dog& Dog::operator=(const Dog& copy)
{
	if (this != &copy)
	{
		_type = copy._type;
		delete _brain;
		_brain = new Brain(*copy._brain);
	}
	return (*this);
}

Dog::~Dog()
{
	delete _brain;
	std::cout << _type << " destructor called." << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Wouaf Wouaf!" << std::endl;
}

void Dog::setIdea(int index, const std::string idea)
{
	_brain->setIdea(index, idea);
}

const std::string Dog::getIdea(int index) const
{
	return (_brain->getIdea(index));
}