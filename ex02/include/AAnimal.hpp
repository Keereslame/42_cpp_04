#ifndef A_ANIMAL_HPP
# define A_ANIMAL_HPP

#include <string>

class AAnimal
{
	public:
		AAnimal();
		AAnimal(const AAnimal& copy);
		AAnimal(const std::string& name);
		AAnimal& operator=(const AAnimal& copy);
		virtual ~AAnimal();

		virtual void	makeSound() const = 0;
		std::string		getType() const;

	protected:
		std::string	_type;
};

#endif