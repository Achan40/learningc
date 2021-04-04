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

#include "animal.h"

#define PI 3.14159
#define AREA_CIRCLE(radius)(PI * (std::pow(radius, 2)))

/*Templates*/
template<typename T>
void Times2(T val){
	std::cout << val << " * 2 = " << val * 2 << "\n";
}

template<typename T>
T Add(T val, T val2){
	return val + val2;
}

template<typename T>
T Max(T val, T val2){
	return (val < val2) ? val2 : val;
}

// Template classes
template<typename T, typename U>
class Person{
public: 
	T height;
	U weight;
	static int numOfPeople;
	Person(T h, U w){
		height = h, weight = w;
		numOfPeople++;
	}
	void GetData(){
		std::cout << "Height: " << height << " and Weight: " << weight << "\n";
	}
};
template<typename T, typename U> int Person<T,U>::numOfPeople;



int main(int argc, char const *argv[])
{
	std::cout << "Circle Area: " << AREA_CIRCLE(5) << "\n";
	Times2(5);
	Times2(5.3);

	std::cout << "5 + 4 = " << Add(5,4) << "\n";
	std::cout << "5.2 + 4.2 = " << Add(5.2,4.2) << "\n";
	std::cout << "Max of 4 or 8 = " << Max(4,8) << "\n";
	std::cout << "Max of A or B = " << Max('A','B') << "\n";
	std::cout << "Max of Dog or Cat = " << Max("Dog","Cat") << "\n";

	Person<double,int> mikeTyson(5.83,216);
	mikeTyson.GetData();
	std::cout << "Number of People: " << mikeTyson.numOfPeople << "\n";

	/* Iterators */
	std::vector<int> nums2 = {1,2,3,4};
	std::vector<int>::iterator itr;
	for(itr = nums2.begin(); itr < nums2.end(); itr++){
		std::cout << *itr << "\n";
	}

	std::vector<int>::iterator itr2 = nums2.begin();
	advance(itr2, 2);
	std::cout << "advance two spaces: " <<*itr2 << "\n";

	auto itr3 = next(itr2, 1);
	std::cout << "advance to next value: " << *itr3 << "\n";

	auto itr4 = prev(itr2, 1);
	std::cout << "advance to previous value: " << *itr4 << "\n";

	std::vector<int> nums3 = {1,4,5,6,7};
	std::vector<int> nums4 = {2,3};
	auto itr5 = nums3.begin();
	advance(itr5, 1);
	copy(nums4.begin(), nums4.end(), inserter(nums3, itr5));
	for(int &i: nums3) std::cout << i << "\n";

	return 0;
}