#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

#include <string>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& copy);
		WrongAnimal(const std::string& name);
		WrongAnimal& operator=(const WrongAnimal& copy);
		~WrongAnimal();

		void	makeSound() const;
		std::string		getType() const;

	protected:
		std::string	_type;
};

#endif