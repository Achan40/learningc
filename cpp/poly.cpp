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

struct Shape
{
	double length, width;

	// constructor
	Shape(double l = 1, double w =1){
		length = 1;
		width = 1;
	}

	// methods
	double Area(){
		return length * width;
	}

private:
	int id;
};

// inheritance w strucs
struct Circle : Shape
{
	// constructor overriding inherited variable
	Circle(double width){
		this->width = width;
	}

	double Area(){
		return 3.14159 * std::pow((width / 2), 2);
	}
};

// Friendly classes, access private varibles of another class
class Customer
{
private:
	friend class GetCustomerData;
	std::string name;

public:
	Customer(std::string name){
		this->name = name;
	}
	
};

class GetCustomerData{
public:
	static std::string GetName(Customer &customer){
		return customer.name;
	}
};

/* Polymorphism */
class Shape2{
protected: 
	double height;
	double width;
public:	
	Shape2(double length){
		height = length;
		width = length;
	}
	Shape2(double h, double w){
		height = h;
		width = w;
	}
	virtual double Area(){
		return height * width;
	}
};

class Circle2 : public Shape2{
public:
	Circle2(double w): Shape2(w){};
	double Area(){return 3.13159 * std::pow((width / 2), 2);}
};

void ShowArea(Shape2 &shape){
	std::cout << "Area: " << shape.Area() << "\n";
}

/* Abstract classes */
class SHAPE
{
public:
	virtual double Area() = 0;
};

class CIRCLE : public SHAPE{
protected:
	double width;
public:
	CIRCLE(double w){
		width = w;
	}
	// always override to make sure the base classes virtual function is the same as the subclass
	double Area() override{
		return 3.13159 * std::pow((width / 2), 2);
	}
};

class RECTANGE : public SHAPE{
protected:
	double height, width;
public: 
	RECTANGE(double h , double w){
		height = h;
		width = w;
	}
	// subclasses may no longer override function if it is final
	double Area() override final{
		return height * width;
	}
};

void SHOWAREA(SHAPE &shape){
	std::cout << "Area: " << shape.Area() << "\n";
}

int main(int argc, char const *argv[])
{
	Shape shape(10, 10);
	std::cout << "Square Area: " << shape.Area() << "\n";

	Circle circle(10);	
	std::cout << "Circle Area: " << circle.Area() << "\n";

	Shape rectangle{10,15};
	std::cout << "Rectangle Area: " << rectangle.Area() << "\n";

	Customer tom("tom");
	GetCustomerData getName;

	std::cout << "Name: " << getName.GetName(tom) << "\n";

	Shape2 rectangle2(10,5);
	Shape2 rectangle3(10);
	Circle2 circle2(10);
	ShowArea(rectangle2);
	ShowArea(rectangle3);
	ShowArea(circle2);

	RECTANGE RECTanlge(15,15);
	CIRCLE CIRCle(5);
	SHOWAREA(RECTanlge);
	SHOWAREA(CIRCle);

	return 0;
}
