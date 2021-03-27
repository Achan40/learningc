#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

std::vector<std::string> StringToVector(std::string theString, char separator);

std::string VectorToString(std::vector<std::string> &vec, char separator);

std::string TrimWhiteSpace(std::string theString);

std::vector<int> FindSubstringMatches(std::string theString, std::string substring);

std::string ReplaceAllSubstrings(std::string theString, std::string substring, std::string newString);

int main(int argc, char const *argv[])
{
	// function to create a vector from a string
	std::vector<std::string> vec = StringToVector("This is a random string",' ');

	for(int i = 0; i < vec.size(); i++){
		std::cout << vec[i] << "\n";
	}

	// function to create a string from a vector
	std::vector<std::string> vCusts(3);
	vCusts[0] = "bob";
	vCusts[1] = "sue";
	vCusts[2] = "tom";

	std::string sCusts = VectorToString(vCusts, ' ');
	std::cout << sCusts << "\n";

	// trim whitespace off of strings
	std::string aStr = "    Just some random words     ";
	aStr = TrimWhiteSpace(aStr);
	std::cout << "*" << aStr << "*\n";

	// Finding index of substring matches 
	std::string phrase = "To be or not to be";
	std::vector<int> matches = FindSubstringMatches(phrase, "be");
	for(int i = 0; i < matches.size(); i++){
		std::cout << matches[i] << "\n";
	}

	// Replace all matching substrings in a string
	std::cout << ReplaceAllSubstrings("to know or not to know","know","be") << "\n";

	return 0;
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

std::string VectorToString(std::vector<std::string> &vec, char separator){
	std::string theString = "";
	for(auto cust: vec) theString += cust += separator;
	return theString;
}

std::string TrimWhiteSpace(std::string theString){
	std::string whitespaces(" \t\f\n");
	theString.erase(theString.find_last_not_of(whitespaces) + 1);
	theString.erase(0, theString.find_first_not_of(whitespaces));
	return theString;
}

std::vector<int> FindSubstringMatches(std::string theString, std::string substring){
	std::vector<int> matchingIndex;
	int index = theString.find(substring, 0);
	while(index != std::string::npos){
		matchingIndex.push_back(index);
		index = theString.find(substring, index + 1);
	}
	return matchingIndex;
}

std::string ReplaceAllSubstrings(std::string theString, std::string substring, std::string newString){
	std::vector<int> matches = FindSubstringMatches(theString,substring);

	if(matches.size() != 0){
		int lengthDifference = newString.size() - substring.size();
		int timesLooped = 0;
		for(auto index:matches){
			theString.replace(index + (timesLooped * lengthDifference), substring.size(), newString);
			timesLooped++;
		}
	}
	return theString;
}
