#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <ctime>
#include <cmath>

std::vector<int> GenerateRandVec(int numOfNums, int min, int max);

void BubbleSort(std::vector<int> &theVec);

int Factorial(int number);

void PrintHorzVector(std::vector<int> &vec);

int Fib(int index);

double Area(double radius);
double Area(double height, double width);

int main(int argc, char const *argv[])
{
	/*Bubble Sort*/
	std::vector<int> vecVals = GenerateRandVec(10, 1, 50);
	BubbleSort(vecVals);

	for(auto x: vecVals) std::cout << x << "\n";

	/*Factorials using recursion*/
	std::cout << "Factorial of 3: " << Factorial(3) << "\n";

	/*Array grid image*/
	std::vector<int> theVec = {10,8,5,6,7,7,10,12,14};
	PrintHorzVector(theVec);

	/*Fibonacci numbers using recursion*/
	int index = 10;
	printf("Fib(%d) = %d\n", index, Fib(index));

	/*switch statments*/
	std::cout << "Area Circle (c)  or Rectangle (r): ";
	char areaType;
	std::cin >> areaType;

	switch(areaType){
		case 'c': 
			std::cout << "Enter Radius: ";
			double radius;
			std::cin >> radius;
			std::cout << "Aread = " << Area(radius) << "\n";
			break;
		case 'r':
			std::cout << "Enter Height: ";
			double height, width;
			std::cin >> height;
			std::cout << "Enter Widtht: ";
			std::cin >> width;
			std::cout << "Aread = " << Area(height, width) << "\n";
			break;
		default : std::cout << "Please Enter c or r\n";
	}

	return 0;
}

std::vector<int> GenerateRandVec(int numOfNums, int min, int max){
	std::vector<int> vecValues;
	srand(time(NULL));
	int i = 0, randVal = 0;

	while(i < numOfNums){
		randVal = min + std::rand() % ((max + 1) - min);
		vecValues.push_back(randVal);
		i ++;
	}
	return vecValues;
}

void BubbleSort(std::vector<int> &theVec){
	int i = theVec.size() - 1;

	while(i >= 1){
		int j = 0;

		while(j < i){
			printf("\nIs %d > %d\n", theVec[j], theVec[j + 1]);
			if(theVec[j] >= theVec[j + 1]){
				std::cout << "Switch\n";

				int temp = theVec[j];
				theVec[j] = theVec[j + 1];
				theVec[j + 1] = temp;
			} else {
				std::cout << "Don't Switch\n";
			}
			j += 1;

			for(auto k: theVec){
				std::cout << k << ", ";
			}
		}
		std::cout << "\nEnd of Round\n";
		i -= 1;
	}
}

int Factorial(int number){
	if(number == 1){
		return 1;
	} else {
		int result = number * Factorial(number - 1);
		return result;
	}
}

void PrintHorzVector(std::vector<int> &vec){
	//dashes
	int dashes = vec.size() * 5;
	for(int n = 0; n < dashes; n++) std::cout << "-";
	std::cout << "\n";

	for(int n = 0; n < vec.size(); n++) printf("| %2d ", n);
	std::cout << "\n";

	for(int n = 0; n < dashes; n++) std::cout << "-";
	std::cout << "\n";

	for(int n = 0; n < vec.size(); n++) printf("| %2d ", vec[n]);
	std::cout << "\n";

	for(int n = 0; n < dashes; n++) std::cout << "-";
	std::cout << "\n";
}

int Fib(int index){
	if(index < 2){
		return index;
	} else {
		return Fib(index - 1) + Fib(index - 2);
	}
}

double Area(double radius){
	return 3.14159 * std::pow(radius, 2);
}

double Area(double height, double width){
	return height * width;
}