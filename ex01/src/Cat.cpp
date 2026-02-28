/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 04:02:53 by alexis            #+#    #+#             */
/*   Updated: 2026/02/28 05:41:03 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Default Cat constructor called." << std::endl;
	_brain = new Brain();
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
	std::cout << copy._type << " created with copy constructor." << std::endl;
	_brain = new Brain(*copy._brain);
}

Cat& Cat::operator=(const Cat& copy)
{
	if (this != &copy)
	{
		_type = copy._type;
		delete _brain;
		_brain = new Brain(*copy._brain);
	}
	return (*this);
}

Cat::~Cat()
{
	delete _brain;
	std::cout << _type << " destructor called." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Miaouuuuuuu!" << std::endl;
}

void Cat::setIdea(int index, const std::string idea)
{
	_brain->setIdea(index, idea);
}

const std::string Cat::getIdea(int index) const
{
	return (_brain->getIdea(index));
}