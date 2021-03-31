#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <ctime>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <functional>
#include <math.h>

/*Object Oriented Programming*/

// Declare variables, methods of the class
class Animal{
// values specific to a certain object
private:
	std::string name;
	double height;
	double weight;

	// shared values for all objects of this class
	static int numOfAnimals;

// values accecible outside of the class
public:
	std::string GetName(){return name;}
	void SetName(std::string name){this->name = name;}
	double GetHeight(){return height;}
	void SetHeight(double height){this->height = height;}
	double GetWeight(){return weight;}
	void SetWeight(double weight){this->weight = weight;}

	void SetAll(std::string, double, double);

	// Constructor, called each time an object is created
	Animal(std::string, double, double);
	// Overload constructor
	Animal();
	// Deconstructor
	~Animal();

	static int GetNumOfAnimals(){return numOfAnimals;}
	void ToString();
};

// implement the methods of the class (this does not need to be outside the class)
int Animal::numOfAnimals = 0;
void Animal::SetAll(std::string name, double height, double weight){
	this->name = name; 
	this->weight = weight;
	this->height = height;
	Animal::numOfAnimals++;
}

// Creating Constructor
Animal::Animal(std::string name, double height, double weight){
	this->name = name; 
	this->weight = weight;
	this->height = height;
	Animal::numOfAnimals++;
}

// Default Constructor (no attributes passed)
Animal::Animal(){
	this->name = ""; 
	this->weight = 0;
	this->height = 0;
	Animal::numOfAnimals++;
}

// Deconstructor
Animal::~Animal(){
	std::cout << "Animal " << this -> name << " is destroyed\n";
}

void Animal::ToString(){
	std::cout << 
		this -> name << " is " << 
		this -> height << " cms tall and " << 
		this -> weight << " kgs in weight\n";
}

// Inheritance
class Dog: public Animal{
private:
	std::string sound = "Worf";
public:
	void MakeSound(){
		std::cout << "The dog " << 
		this -> GetName() << " says" << 
		this -> sound << "\n";
	}

	Dog(std::string, double, double, std::string);
	// Default constructor calls the animal constructor
	Dog(): Animal(){};
	void ToString();

};

Dog::Dog(std::string name, double height, double weight, std::string sound) : Animal(name, height, weight){
	this -> sound = sound;
}

// Overwrite inherited method (Keep in mind variables are in a private class)
void Dog::ToString(){
	std::cout << 
		this -> GetName() << " is " << 
		this -> GetHeight() << " cms tall and " << 
		this -> GetWeight() << " kgs in weight and says " <<
		this -> sound << "\n";
}

int main(int argc, char const *argv[])
{
	Animal fred;
	fred.ToString();

	// using methods of the class
	fred.SetHeight(33);
	fred.SetWeight(10);
	fred.SetName("Fred");
	fred.ToString();

	// using the constructor
	Animal tom("Tom", 36, 15);
	tom.ToString();

	Dog spot("Spot", 38, 16, "Woof");
	spot.ToString();

	std::cout << "Number of Animals " << Animal::GetNumOfAnimals() << "\n";

	return 0;
}