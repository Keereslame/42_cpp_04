/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 04:02:53 by alexis            #+#    #+#             */
/*   Updated: 2026/02/28 04:30:18 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Default Cat constructor called." << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
	std::cout << copy._type << " created with copy constructor." << std::endl;
}

Cat& Cat::operator=(const Cat& copy)
{
	if (this != &copy)
	{
		_type = copy._type;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << _type << " destructor called." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Miaouuuuuuu!" << std::endl;
}