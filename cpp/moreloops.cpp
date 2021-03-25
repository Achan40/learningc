#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

std::vector<int> Range(int start, int max, int step);

int main(int argc, char const *argv[])
{
	/*do while loops*/
	srand(time(NULL));
	int secretNum = std::rand() % 11;
	int guess = 0;

	do{
		std::cout << "Guess the number: ";
		std::cin >> guess;
		if(guess > secretNum) std::cout << "Too Big\n";
		if(guess < secretNum) std::cout << "Too Small\n";
	} while(secretNum != guess);

	std::cout << "You win!";

	return 0;
}

std::vector<int> Range(int start, int max, int step){
	int i = start;
	std::vector<int> range;

	while(i <= max){
		int y = start += step;
		range.push_back(y);
	}
	return range;
}