#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <ctime>

std::string CaesarCipher(std::string theString, int key, bool encrypt);

std::vector<std::string> StringToVector(std::string theString, char separator);

void SolveForX(std::string equation);

std::vector<int> Range(int start, int max, int step);

bool IsPrime(int num);

std::vector<int> GetPrimes(int maxNum);

std::vector<int> GenerateRandVec(int numOfNums, int min, int max);

int main(int argc, char const *argv[])
{
	// Caesar Cipher function
	std::string theString = "Make me secret";
	std::string encryptedStr = CaesarCipher(theString, 5, true);
	std::string decryptedStr = CaesarCipher(encryptedStr, 5, false);

	std::cout << "Encrypted: " << encryptedStr << "\n";
	std::cout << "Decrypted: " << decryptedStr << "\n";

	// Solving for x function
	std::string equation = "x + 4 = 25";
	SolveForX(equation);

	// Checking if a number is prime, generate list of primes up to a certain number
	int num = 5;
	std::cout << "Is " << num << " Prime? " << IsPrime(num) << "\n";

	int maxPrime = 50;
	std::vector<int> primeList = GetPrimes(maxPrime);
	for(auto x: primeList) std::cout << x << "\n";
		
	// Generate random vector full of numbers
	std::vector<int> vecVals = GenerateRandVec(10, 5, 50);
	for(auto x: vecVals) std::cout << x << "\n";

	return 0;
}

std::string CaesarCipher(std::string theString, int key, bool encrypt){
	std::string returnString = "";
	int charCode = 0;
	char letter;
	if(encrypt) key = key * -1;

	for(char& c: theString){
		if(isalpha(c)){
			charCode = (int)c;
			charCode += key;

			if(isupper(c)){
				if(charCode	> (int)'Z'){
					charCode -= 26;
				} else if(charCode < (int)'A'){
					charCode += 26;
				}
			} else {
				if(charCode	> (int)'z'){
					charCode -= 26;
				} else if(charCode < (int)'a'){
					charCode += 26;
				}
			}
			letter = charCode;
			returnString += letter;

		} else {
			letter = c;
			returnString += c;
		}
	}
	return returnString;
}

std::vector<std::string> StringToVector(std::string theString, char separator){
	std::vector<std::string> vecsWords;
	std::stringstream ss(theString);
	std::string sIndivStr;
	while(getline(ss, sIndivStr, separator)){
		vecsWords.push_back(sIndivStr);
	}
	return vecsWords;
}

// format of x + 4 = 9
void SolveForX(std::string equation){
	std::vector<std::string> vectorEquation = StringToVector(equation, ' ');
	int num1 = std::stoi(vectorEquation[2]);
	int num2 = std::stoi(vectorEquation[4]);
	int xVal = num2 - num1;
	std::cout << "x = " << xVal << "\n";
}

std::vector<int> Range(int start, int max, int step){
	int i = start;
	std::vector<int> range;
	while(i <= max){
		range.push_back(i);
		i += step;
	}
	return range;
}


bool IsPrime(int num){
	for(auto n: Range(2, num - 1, 1)){
		if((num % n) == 0) return false;
		}
	return true;
}

std::vector<int> GetPrimes(int maxNum){
	std::vector<int> primeVec;
	for(auto n: Range(2, maxNum, 1)){
		if(IsPrime(n))
			primeVec.push_back(n);
	}
	return primeVec;
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