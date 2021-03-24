#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <numeric>

/*prototyping functions*/
double AddNumbers(double num1, double num2);

/*functions*/
	double AddNumbers(double num1, double num2){
		return num1 + num2;
	}


int main(){

	 /*Arrays*/
	int arrNums[10] = {1};
	int arrNums2[] = {1,2,3};
	int arrNums3[5] = {8,9};

	std::cout << "1st Value: " << arrNums[0] << "\n";
	std::cout << "Size of array: " << sizeof(arrNums3) / sizeof(*arrNums3) << "\n";

	int arrNums4[2][2][2] = {{{1,2}, {3,4}}, {{5,6},{7,8}}};

	/*Vectors (resizeable arrays)*/
	std::vector<int> vecRandNums(2);
	vecRandNums[0] = 10;
	vecRandNums[1] = 20;
	vecRandNums.push_back(30);

	std::cout << "Last Index: " << vecRandNums[vecRandNums.size() -1] << "\n";

	std::string sSentence = "This is a random string";
	std::vector<std::string> vecsWords;
	std::stringstream ss(sSentence);
	std::string sIndivStr;
	char cSpace = ' ';

	while(getline(ss, sIndivStr, cSpace)){
		vecsWords.push_back(sIndivStr);
	}

	for(int i = 0; i < vecsWords.size(); i++){
		std::cout << vecsWords[i] << "\n";
	}

	/*Creating a calculator*/
	/*double dbNum1 = 0;
	double dbNum2 = 0;
	std::string sCalc = "";
	std::vector<std::string> vecsCalc;

	std::cout << "Enter calculation (ex: 5 + 6): ";
	getline(std::cin, sCalc);

	std::stringstream ss1(sCalc);
	std::string sIndivStr1;
	char cSpace1 = ' ';

	while(getline(ss1, sIndivStr1, cSpace1)){
		vecsCalc.push_back(sIndivStr1);
	}

	dbNum1 = std::stoi(vecsCalc[0]);
	dbNum2 = std::stoi(vecsCalc[2]);
	std::string operation = vecsCalc[1];

	if(operation == "+"){
		printf("%.1f + %.1f = %.1f\n", dbNum1, dbNum2, (dbNum1 + dbNum2));
	} else if(operation == "-"){
		printf("%.1f - %.1f  = %.1f\n", dbNum1, dbNum2, (dbNum1 - dbNum2));
	} else if(operation == "*"){
		printf("%.1f * %.1f  = %.1f\n", dbNum1, dbNum2, (dbNum1 * dbNum2));
	} else if(operation == "/"){
		printf("%.1f / %.1f  = %.1f\n", dbNum1, dbNum2, (dbNum1 / dbNum2));
	}*/

	/*More vectors*/
	std::vector<int> myVec(10);
	std::iota(std::begin(myVec), std::end(myVec), 1);

	for(auto y: myVec) std::cout << y << "\n";

	for(int i = 0; i < myVec.size(); i++){
		if(myVec[i] % 2 == 0){
			std::cout << myVec[i] << " is even\n";
		}
	}


	/*using functions*/
	double num1, num2;
	std::cout << "Enter num1: ";
	std::cin >> num1;
	std::cout << "Enter num2: ";
	std::cin >> num2;

	printf("%.1f + %.1f = %.1f\n", num1, num2, AddNumbers(num1, num2));

	return 0;
}