#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal
{
public:
	std::string name;
	Animal(std::string name);
	virtual ~Animal();

private:
};

#endif /* ANIMAL_H */