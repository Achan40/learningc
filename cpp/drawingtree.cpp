#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

std::vector<int> Range(int iStart, int iMax, int iIncrement);

int main(int argc, char const *argv[])
{
	/*Drawing a tree*/
	std::cout << "How tall is the tree: ";
	int treeHeight = 0, spaces = 0, hashes = 1, stumpSpaces = 0;
	std::cin >> treeHeight;
		
	spaces = treeHeight - 1;
	stumpSpaces = treeHeight - 1;

	while(treeHeight != 0){
		for(auto x: Range(1, spaces, 1)) std::cout << " ";
		for(auto x: Range(1, hashes, 1)) std::cout << "#";
		std::cout << "\n";
		spaces -= 1;
		hashes += 2;
		treeHeight -= 1;
	}

	for(auto x: Range(1,stumpSpaces, 1)) std::cout << " ";
	std::cout << "#";

		return 0;
	}

std::vector<int> Range(int iStart, int iMax, int iIncrement){
	std::vector<int> vRange;
	for(int i = iStart; i < iMax; i = i + iIncrement){
		vRange.push_back(i);
	}
	return vRange;
}
