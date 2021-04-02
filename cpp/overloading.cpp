#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <fstream>

class Box {
public: 
	double length, width, breath;
	std::string boxString;

	Box(){
		length = 1, width = 1, breath = 1;
	}

	Box(double l, double w, double b){
		length = l, width = w, breath = b;
	}

	/*Operator overloading*/
	Box &operator ++ (){
		length++;
		width++;
		breath++;
		return *this;
	}

	operator const char*(){
		std::ostringstream boxStream;
		boxStream << "Box : " << length << ", " << width << ", " << breath;
		boxString = boxStream.str();
		return boxString.c_str();
	}

	Box operator + (const Box &box2){
		Box boxSum;
		boxSum.length = length + box2.length;
		boxSum.width = width + box2.width;
		boxSum.breath = breath + box2.breath;
		return boxSum;
	}

	double operator [] (int x){
		if(x == 0){
			return length;
		} else if(x == 1){
			return width;
		} else if(x == 2){
			return breath;
		} else {
			return 0;
		}
	}

	bool operator == (const	Box &box2){
		return((length = box2.length) && ((length = box2.width)) && ((length = box2.breath)));
	}

	bool operator < (const Box &box2){
		double thisSize = length + width + breath;
		double box2Size = box2.length + box2.width + box2.breath;
		if(thisSize < box2Size){
			return true;
		} else {
			return false;
		}
	}

	bool operator > (const Box &box2){
		double thisSize = length + width + breath;
		double box2Size = box2.length + box2.width + box2.breath;
		if(thisSize > box2Size){
			return true;
		} else {
			return false;
		}
	}

	void operator = (const Box &boxToCopy){
		length = boxToCopy.length;
		width = boxToCopy.width;
		breath = boxToCopy.breath;
	}

};

int main(int argc, char const *argv[])
{
	/* Operator Overloading */
	Box box(10,10,10);
	++box;
	// this works because of one of our classes
	std::cout << box << "\n";

	Box box2(5,5,5);
	std::cout << "Box 1 + Box 2 = " << box + box2 << "\n";

	std::cout << "Box length: " << box[0] << "\n";
	std::cout << std::boolalpha;
	std::cout << "Are boxes equal: " << (box == box2) << "\n";
	std::cout << "Is box < box2: " << (box < box2) << "\n";
	std::cout << "Is box > box2: " << (box > box2) << "\n";
	box = box2;
	std::cout << box << "\n";

	/*File IO*/
	std::ofstream writeToFile;
	std::ifstream readFromFile;
	std::string txtToWrite = "";
	std::string txtFromFile = "";

	writeToFile.open("test.txt", std::ios_base::out | std::ios_base::trunc);
	if(writeToFile.is_open()){
		writeToFile << "Beginnning of File \n";
		std::cout << "Enter data to write: ";
		getline(std::cin, txtToWrite);
		writeToFile << txtToWrite;
		writeToFile.close();
	}

	readFromFile.open("test.txt", std::ios_base::in);
	if(readFromFile.is_open()){
		while(readFromFile.good()){
			getline(readFromFile, txtFromFile);
			std::cout << txtFromFile << "\n";
		}
		readFromFile.close();
	}

	return 0;
}