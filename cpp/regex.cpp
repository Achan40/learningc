#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
#include <thread>
#include <chrono>
#include <ctime>
#include <mutex>
#include <regex>

void PrintMatches(std::string str, std::regex reg){
	std::smatch matches;	
	std::cout << std::boolalpha;
	while(std::regex_search(str, matches, reg)){
		std::cout << "Is there a match: " << matches.ready() << "\n";
		std::cout << "Are there no match: " << matches.empty() << "\n";
		std::cout << "Number of matches: " << matches.size() << "\n";
		std::cout << matches.str(1) << "\n";
		str = matches.suffix().str();
		std::cout << "\n";
	}
}

void PrintMatches2(std::string str, std::regex reg){
	std::sregex_iterator currentMatch(str.begin(), str.end(), reg);
	std::sregex_iterator lastMatch;
	while(currentMatch != lastMatch){
		std::smatch match = *currentMatch;
		std::cout << match.str() << "\n";
		currentMatch++;
	}
	std::cout << "\n";
}

void PrintMatches3(std::string str, std::regex reg){
	std::smatch matches;
	while(std::regex_search(str, matches, reg)){
		std::cout << matches.str(1) << "\n";
		str = matches.suffix().str();
	}
	std::cout << "\n";
}

int main(int argc, char const *argv[])
{
	std::string str = "The ape was at the apex";

	// anything that has ape, is not a space after ape, and is not required to be a match
	std::regex reg("(ape[^ ]?)");
	PrintMatches(str, reg);

	std::string str2 = "I picked the pickle";
	std::regex reg2("(pic([^ ]+)?)");
	PrintMatches2(str2, reg2);

	//matchiing for characters
	std::string str3 = "Cat rat mat fat pat";
	std::regex reg3("([crmfp]at)");
	PrintMatches2(str3, reg3);

	//matching through a range
	std::regex reg4("([C-Fc-f]at)");
	PrintMatches2(str3, reg4);

	//match for all not upper c or lower r
	std::regex reg5("([^Cr]at)");
	PrintMatches2(str3, reg5);

	//replace matches
	std::string str6 = "Cat rat mat fat pat";
	std::regex reg6("([Cr]at)");
	std::string owlFood = std::regex_replace(str6,reg6,"Owl");
	std::cout << owlFood << "\n";

	// match any character
	std::string str7 = "F.B.I. I.R.S. CIA";
	std::regex reg7("([^ ]\..\..\.)");
	PrintMatches2(str7, reg7);

	// match white space
	std::string str8 = "This is a\n multiline string\n" "that has many lines";
	std::regex reg8("\n");
	std::string noLBStr = std::regex_replace(str8, reg8, " ");
	std::cout << noLBStr << "\n";

	// match single numbers
	std::string str9 = "12345";
	std::regex reg9("\\d");
	PrintMatches2(str9, reg9);

	// match single numbers within a range
	std::string str10 = "12345 123 123456 1234567";
	std::regex reg10("\\d{5,7}");
	PrintMatches2(str10, reg10);	

	// match any single letter or number
	std::string str11 = "412-867-5309";
	std::regex reg11("\\w{3}-\\w{3}-\\w{4}");
	PrintMatches2(str11, reg11);

	// match one or more characters
	std::string str13 = "a as ape bug";
	std::regex reg13("a[a-z]+");
	PrintMatches2(str13, reg13);

	//matching emails
	std::string str14 = "db@aol.com m@.com @apple.com db@.com";
	std::regex reg14("[\\w._%+-]{1,20}@[\\w.-]{2,20}.[A-Za-z]{2,3}");
	PrintMatches2(str14, reg14);

	// matching zero or 1 of an item
	std::string str15 = "cats cats";
	std::regex reg15("([cat]+s?)");
	PrintMatches3(str15, reg15);

	// matching zero or more items
	std::string str16 = "doctor doctors doctor's";
	std::regex reg16 ("([doctor]+['s]{0,2})");
	PrintMatches3(str16, reg16);

	std::string str17 = "Just some words\n" "and some more\r\n" "and more\n";
	std::regex reg17("[\r]?\n");
	std::string line = std::regex_replace(str17, reg17, " ");
	std::cout << line << "\n";

	// lazy matching
	std::string str18 = "<name>Life On Mars</name>" "<name>Freaks and Geeks</name>";
	std::regex reg18("<name>(.*?)</name>");
	PrintMatches3(str18, reg18);

	// word boundaries
	std::string str19 = "ape at the apex";
	std::regex reg19("(\\bape\\b)");
	PrintMatches3(str19, reg19);

	// string boundaries
	std::string str20 = "Match everthing up to @";
	std::regex reg20("(^.*[^@])");
	PrintMatches3(str20, reg20);

	// getting numbers minues the area codes from a string
	std::string str21 = "206-709-3100 202-456-1111 212-832-2000";
	std::regex reg21(".{3}-(.{8})");
	PrintMatches3(str21, reg21);

	// multiple subexpressions
	std::string str22 = "My number is 904-285-3700";
	std::regex reg22("(.{3})-(.*)-(.*)");
	std::smatch matches;
	if(std::regex_search(str22, matches, reg22)){
		for(int i = 1; i < matches.size(); i++){
			std::cout << matches[i] << "\n";
		}
	}

	//back reference
	std::string str23 = "The cat cat fell out the window";
	std::regex reg23("(\\b\\w+)\\s+\\1");
	PrintMatches3(str23, reg23); 

	//back reference substitution
	std::string str24 = "<a href='#'><b>The Link</b></a>";
	std::regex reg24("<b>(.*?)</b>");
	std::string result;

	std::regex_replace(std::back_inserter(result),str24.begin(), str24.end(), reg24, "$1");

	std::cout << result << "\n";

	std::string str25 = "412-555-1212";
	std::regex reg25("([\\d]{3})-([\\d]{3}-[\\d]{4})");
	std::string result2;

	std::regex_replace(std::back_inserter(result2),str25.begin(), str25.end(), reg25, "($1)$2");

	std::cout << result2 << "\n";

	// grab url and output something
	std::string str26 = "https://www.youtube.com " "http://www.google.com";
	std::regex reg26("(https?://([\\w.]+))");
	std::string result3;

	std::regex_replace(std::back_inserter(result3),str26.begin(), str26.end(), reg26, "<a href='$1'>$2</a>\n");

	std::cout << result3 << "\n";

	// look aheads (define pattern and match but not return)
	std::string str27 = " one two three four ";
	std::regex reg27("(\\w+(?=\\b))");
	PrintMatches3(str27, reg27);

	// or condition (define matches that you WILL accept)
	std::string str28 = "1. Dog 2. cat 3. Turtle";
	std::regex reg28("\\d\\.\\s(Dog|cat)");
	PrintMatches3(str28, reg28);

	// practice
	std::string str29 = "12345 12345-1234 1234 12346-333";
	std::regex reg29("(\\d{5}-\\d{4}|\\d{5}\\s)");
	PrintMatches3(str29, reg29);

	std::string str30 = "14125551212 4125551212 (412)5551212 412 555 1212 412-555-1212 1-412-555-1212";
	std::regex reg30("((1?)(-| ?)(\\()?(\\d{3})(\\)|-| |\\))?(\\d{3})(-| )?(\\d{4}|\\d{4}))");
	PrintMatches3(str30, reg30);
 
	return 0;
} 