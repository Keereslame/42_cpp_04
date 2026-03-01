#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	public:
		Dog();
		Dog(const Dog& copy);
		Dog& operator=(const Dog& copy);
		~Dog();

		void				makeSound() const;
		void				setIdea(int index, const std::string idea);
		const std::string	getIdea(int index) const;
	
	private:
		Brain*	_brain;
};

#endif