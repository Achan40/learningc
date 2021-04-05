#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <fstream>
#include <functional>
#include <iterator>
#include <cmath>
#include <memory>
#include <stdio.h>

/* Polymorphic templates*/ 
class Pizza
{
public:
	virtual void MakePizza() = 0;
	
};

class NYStyleCrust{
public:
	std::string AddIngredient(){
		return "Crust so thin you can see through it\n\n";
	}
};

class DeepDishCrust{
public:
	std::string AddIngredient(){
		return "DeepDish pizza\n\n";
	}
};

template<typename T>
class LotsOfMeat: public T{
public:
	std::string AddIngredient(){
		return "Lots of Random Meat, " + T::AddIngredient();
	}
};

template<typename T>
class Vegan: public T{
public:
	std::string AddIngredient(){
		return "Vegan Chesses, " + T::AddIngredient();
	}
};

template<typename T>
class MeatNYStyle: public T, public Pizza{
public:
	void MakePizza(){
		std::cout << "Meat NY Style Pizza: " << T::AddIngredient();
	}
};

template<typename T>
class VeganDeepDish: public T, public Pizza{
public:
	void MakePizza(){
		std::cout << "VeganDeepDish: " << T::AddIngredient();
	}
};

int main(int argc, char const *argv[])
{
	std::vector<std::unique_ptr<Pizza>> pizzaOrders;
	pizzaOrders.emplace_back(new MeatNYStyle<LotsOfMeat<NYStyleCrust>>());
	pizzaOrders.emplace_back(new VeganDeepDish<Vegan<DeepDishCrust>>());

	for(auto &pizza: pizzaOrders){
		pizza->MakePizza();
	}


	return 0;
}