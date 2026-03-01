#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
	public:
		Cat();
		Cat(const Cat& copy);
		Cat& operator=(const Cat& copy);
		~Cat();

		void			makeSound() const;
		void			setIdea(int index, const std::string idea);
		const std::string	getIdea(int index) const;

	private:
		Brain* _brain;
};

#endif