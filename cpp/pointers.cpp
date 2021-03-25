#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

void AssignAge3(int* pAge);

void DoubleArray(int* arr, int size);

std::vector<int> Range(int iStart, int iMax, int iIncrement);

int main(int argc, char const *argv[])
{
	/* pointers */
	int age = 43;
	// Initialize pointer variable
	int* pAge = NULL;

	// set it equal to mem location of variable
	pAge = &age;

	std::cout << "Address: " << pAge << "\n";

	// derefernce the pointer variable to see its value
	std::cout << "Value at Address: " << *pAge << "\n";

	int intArray[] = {1,2,3,4,5};
	// do not need & symbol for arrays
	int* pIntArray = intArray;

	// cycling through arrays 
	std::cout << "1st " << *pIntArray << "Address " << pIntArray << "\n";
	pIntArray++;
	std::cout << "2nd " << *pIntArray << "Address " << pIntArray << "\n";
	pIntArray--;
	std::cout << "1st " << *pIntArray << "Address " << pIntArray << "\n";

	// using pointers in functions, changing a pointers value using its dereference
	AssignAge3(&age);
	std::cout << "Pointer Age: " << age << "\n";

	// changing value of array using pointers
	int arr[] = {1,2,3,4,5};
	DoubleArray(arr, 5);

	for(int i = 0; i < 4; i++){
		std::cout << "Array " << arr[i] << "\n";
	}
	
	//Using my own range function
	std::vector<int> vect = Range(1,10,1);
	for(auto y: vect) std::cout << y << "\n";

	//compound interest funciton using user input
	double iInitial;
	double iRate;

	std::cout << "How much to invest: ";
	std::cin >> iInitial;
	std::cout << "interest Rate: ";
	std::cin >> iRate;

	iRate = iRate * .01;

	for(auto y: Range(1,10,1)){
		iInitial += (iInitial * iRate);
	}
	std::cout << "Value after 10 years: " << iInitial << "\n";

	return 0;
}

void AssignAge3(int* pAge){
	*pAge = 22;
}

void DoubleArray(int* arr, int size){
	for(int i = 0; i < size; i++){
		arr[i] = arr[i] * 2;
	}
}

std::vector<int> Range(int iStart, int iMax, int iIncrement){
	std::vector<int> vRange;
	for(int i = iStart; i < iMax; i = i + iIncrement){
		vRange.push_back(i);
	}
	return vRange;
}
