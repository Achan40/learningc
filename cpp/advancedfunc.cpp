#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <fstream>
#include <functional>

double MultBy2(double num){
	return num * 2;
}

double DoMath(std::function<double(double)> func, double num){
	return func(num);
}

double MultBy3(double num){
	return num * 3;
}

bool checkOdd(int num){
	if(num % 2 == 0){
		return false;
	} else {
		return true;
	}
}

std::vector<int> ListOfOdds(std::function<bool(int)> func, std::vector<int> num){
	std::vector<int> temp;
	for(int i = 0; i < num.size(); i++){
		if(func(i)){
			temp.push_back(i);
		} 
	}
	return temp;
}

std::vector<char> GetHAndTList(std::vector<char> possibleValues, int numberValuesToGenerate){
	srand(time(NULL));
	std::vector<char> hAndTList;
	for(int i = 0; i < numberValuesToGenerate; ++i){
		int randIndex = rand() % 2;
		hAndTList.push_back(possibleValues[randIndex]);
	}
	return hAndTList;
}

int GetNumberOfMatchers(std::vector<char> list, char valueToFind){
	int numOfMatchers = 0;
	for(char i: list){
		if(i == valueToFind){
			numOfMatchers++;
		}
	}
	return numOfMatchers;
}

int main(int argc, char const *argv[])
{
	// storing function into variable
	auto times2 = MultBy2;
	std::cout << "5 * 2 = " << times2(5) << "\n";

	// passing a function into another function
	std::cout << "6 * 2 = " << DoMath(times2, 6) << "\n";

	// store functions in a vector, the function must have the same return type and attribute to work
	std::vector<std::function<double(double)>> funcs(2);
	funcs[0] = MultBy2;
	funcs[1] = MultBy3;
	std::cout << "2 * 10 = " << funcs[0](10) << "\n";

	// practice
	std::vector<int> listOfNums {1,2,3,4,5};
	std::vector<int> oddList = ListOfOdds(checkOdd, listOfNums);
	std::cout << "List of Odds\n";
	for(auto i: oddList){
		std::cout << i << "\n";
	}

	// randomly generate n number of heads or tails
	std::vector<char> possibleValues{'H','T'};

	std::vector<char> hList = GetHAndTList(possibleValues,100);
	std::cout << "Number of Heads: " << GetNumberOfMatchers(hList, 'H') << "\n";
	std::vector<char> TList = GetHAndTList(possibleValues,100);
	std::cout << "Number of Tails: " << GetNumberOfMatchers(TList, 'L') << "\n";

	for(auto i: hList){
		std::cout << i << "\n";
	}

	for(auto i:TList){
		std::cout << i << "\n";
	}

	return 0;
}