#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
protected:
	std::string _type;
public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal &src);
	~WrongAnimal();
	WrongAnimal &operator=(const WrongAnimal &src);
	std::string getType(void) const;
	void makeSound(void) const;
};

#endif