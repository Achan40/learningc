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



int main(int argc, char const *argv[])
{
	/* mem allocation before smart pointers*/
	// int amtToStore = 5;  
	// std::cout << "How many numbers to store: ";
	// std::cin >> amtToStore;
	// int *pNums = (int *) malloc(amtToStore * sizeof(int));
	// if(pNums != NULL){
	// 	int i = 0;
	// 	while(i < amtToStore){
	// 		std::cout << "Enter a Number: ";
	// 		std::cin >> pNums[i];
	// 		i++;
	// 	}
	// }
	// std::cout << "You entered these numbers\n";
	// for(int i = 0; i < amtToStore; i++){
	// 	std::cout << pNums[i] << "\n";
	// }

	// delete pNums;

	/*Smart Pointers*/
	int amtToStore = 5;  
	std::cout << "How many numbers to store: ";
	std::cin >> amtToStore;

	std::unique_ptr<int[]> pNums(new int[amtToStore]);

	if(pNums != NULL){
		int i = 0;
		while(i < amtToStore){
			std::cout << "Enter a Number: ";
			std::cin >> pNums[i];
			i++;
		}
	}
	std::cout << "You entered these numbers\n";
	for(int i = 0; i < amtToStore; i++){
		std::cout << pNums[i] << "\n";
	}

	return 0;
}