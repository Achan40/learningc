#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>


int main(int argc, char const *argv[])
{
	
	std::cout << "Hello World" << std::endl;

	if(argc != 1){
		std::cout << "You entered " << argc << " arguments\n";
	}

	for(int i = 0; i < argc; i++){
		std::cout << argv[i] << "\n";
	}

	return 0;
}
