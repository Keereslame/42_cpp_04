/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 04:02:53 by alexis            #+#    #+#             */
/*   Updated: 2026/02/28 04:35:21 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "Default WrongCat constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy)
{
	std::cout << copy._type << " created with copy constructor." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& copy)
{
	if (this != &copy)
	{
		_type = copy._type;
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << _type << " destructor called." << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Wrong Miaouuuuuuu!" << std::endl;
}