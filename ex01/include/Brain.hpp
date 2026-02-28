#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain
{
	public:
		Brain();
		Brain(const Brain& copy);
		Brain& operator=(const Brain& copy);
		~Brain();

		std::string getIdea(int index) const;
		void setIdea(int index, const std::string idea);

	private:
		std::string _ideas[100];
};

#endif