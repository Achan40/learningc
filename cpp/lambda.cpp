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

std::vector<int> GenerateRandVec(int numOfNums, int min, int max);

std::vector<int> GenerateFibList(int numOfFib);

int main(int argc, char const *argv[])
{
	
	std::vector<int> vecVals = GenerateRandVec(10, 1, 50);
	for(auto val: vecVals) std::cout << val << "\n";

	/* Lambda Expressions */
	// sorted by least to greatest
	std::sort(vecVals.begin(), vecVals.end(), [](int x, int y){return x < y;});
	for(auto val: vecVals) std::cout << val << "\n";

	// copy if
	std::vector<int> evenVals;
	
	std::copy_if(vecVals.begin(), vecVals.end(), std::back_inserter(evenVals), [](int x){return (x % 2) == 0;});
	for(auto val: evenVals) std::cout << val << "\n";

	// For each 
	int sum = 0;
	std::for_each(vecVals.begin(), vecVals.end(), [&](int x){sum += x;});
	std::cout << "Sum of vector values: " << sum << "\n";

	// dynamic list divisible by a value
	int divisor = 5;
	std::vector<int> vecVals2;
	std::copy_if(vecVals.begin(), vecVals.end(), std::back_inserter(vecVals2), [divisor](int x){return (x % divisor) == 0;});
	for(auto val: vecVals2) std::cout << val << "\n";

	// multiply all values inside of a vector
	std::vector<int> doubleVec;
	std::for_each(vecVals.begin(), vecVals.end(), [&](int x){doubleVec.push_back(x * 2);});
	for(auto val: doubleVec) std::cout << val << "\n";

	// add values stored in two different vectors and store in another
	std::vector<int> vec1 = {1,2,3,4,5};
	std::vector<int> vec2 = {1,2,3,4,5};
	std::vector<int> vec3(5);

	transform(vec1.begin(), vec1.end(), vec2.begin(), vec3.begin(), [](int x, int y){return x + y;});
	for(auto val: vec3) std::cout << val << "\n";

	/*Ternary Operator, compact if statement*/
	int age = 43;
	bool canIVote = (age >= 18) ? true : false;

	// print out true or false instead of 1 or 0
	std::cout.setf(std::ios::boolalpha);
	std::cout << "Can I Vote: " << canIVote << "\n";

	// Generate Fibbonaci numbers using lambda expression
	std::function<int(int)> Fib = [&Fib](int n) {return n < 2 ? n : Fib(n - 1) + Fib(n - 2);};
	std::cout << "Fibbonaci of the 4th index: " << Fib(4) << "\n";

	// Generate a vector of Fibbonacci numbers using lambda expressions	
	std::vector<int> listOfFibs = GenerateFibList(10);
	for(auto val: listOfFibs) std::cout << val << "\n";



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

std::vector<int> GenerateFibList(int numOfFib){
	std::vector<int> listOfFibs;
	std::function<int(int)> Fib = [&Fib](int n) {return n < 2 ? n : Fib(n - 1) + Fib(n - 2);};

	for(int i = 0; i < numOfFib; i++){
		listOfFibs.push_back(Fib(i));
	}
	return listOfFibs;
}