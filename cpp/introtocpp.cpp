#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

/*pass-in arguements via terminal when you run the program*/
int main(int argc, char const *argv[])
{
	
	std::cout << "Hello World" << std::endl;

	if(argc != 1){
		std::cout << "You entered " << argc << " arguments\n";
	}

	for(int i = 0; i < argc; i++){
		std::cout << argv[i] << "\n";
	}

	/*datatypes*/
	bool bSingle = true;
	const char chMygrade = 'A';
	int randNum = 0;
	unsigned short int u16Age = 43;
	short int siWeight = 180;
	int nDays = 7;
	long lBigNum = 100000;
	float fPi = 3.14;
	double dbBigFloat = 1.1111111111111111111111;
	auto whatWillIBe = true;

	std::cout << "Min bool " << std::numeric_limits<bool>::min() << "\n";

	float fBigFloat = 3.12159278;
	float fBigFloat2 = 1.111111111;
	float fFloatSum = fBigFloat2 + fBigFloat;

	printf("fFloatSum Prescision : %.10f\n", fFloatSum);

	/*Math operations and receiving data from user*/
	std::string sQuestion("Enter Number 1: ");
	std::string sNum1, sNum2;
	std::cout << sQuestion;

	getline(std::cin, sNum1);

	std::cout << "Enter Number 2: ";

	getline(std::cin, sNum2);
 	
 	int nNum1 = std::stoi(sNum1);
 	int nNum2 = std::stoi(sNum2);

 	printf("%d + %d = %d\n", nNum1, nNum2, (nNum1 + nNum2) );
 	printf("%d - %d = %d\n", nNum1, nNum2, (nNum1 - nNum2) );
 	printf("%d / %d = %d\n", nNum1, nNum2, (nNum1 / nNum2) );
 	printf("%d %% %d = %d\n", nNum1, nNum2, (nNum1 % nNum2) );

 	/*Converting miles to kilometers*/
 	std::string sMilesQ("Enter Miles: ");
 	std::string sMiles;
 	std::cout << sMilesQ;

 	getline(std::cin, sMiles);

 	double dMiles, dKilometers;
 	dMiles = std::stod(sMiles);
 	dKilometers = dMiles * 1.60934;

 	printf("%f miles is: %f kilometers\n", dMiles, dKilometers);

	return 0;
}
