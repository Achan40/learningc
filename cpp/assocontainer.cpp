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

#include <set>
#include <map>
#include <stack>
#include <queue>

int main(int argc, char const *argv[])
{
	//sets
	std::set<int> set1 = {5,4,3,2,1,1};
	std::cout << "Size of set: " << set1.size() << "\n";

	set1.insert(0);
	std::set<int>::iterator it = set1.begin();
	it++;

	std::cout << "2nd value: " << *it << "\n";

	set1.erase(5);

	it = set1.end();
	std::advance(it, -2);
	set1.erase(it, set1.end());

	int arr[] = {6,7,8,9};

	set1.insert(arr,arr+4);

	auto eight = set1.lower_bound(8);
	std::cout << "8: " << *eight << "\n";

	std::set<int> set2 = {10,11};

	set1.swap(set2);

	if(!set1.empty()){
		for(int i : set1) std::cout << i << "\n";
	}

	//multisets like sets but can contain duplicates
	std::multiset<int> mset1 = {1,2,1,3,4};
	mset1.insert(4);
	mset1.insert(2);

	if(!mset1.empty()){
		for(int i : mset1) std::cout << i << "\n";
	}

	//map 
	std::map<int, std::string> map1;
	map1.insert(std::pair<int,std::string> (1,"test"));
	map1.insert(std::pair<int,std::string> (2,"test2"));
	map1.insert(std::pair<int,std::string> (3,"test3"));
	map1.insert(std::pair<int,std::string> (4,"test4"));

	auto match = map1.find(1);
	std::cout << match->second << "\n";
	auto test = map1.lower_bound(1);
	std::cout << "LB: " << test->second << "\n";
	auto test2 = map1.upper_bound(1);
	std::cout << "UB: " << test2->second << "\n";


	std::map<int,std::string>::iterator it2;
	for(it2 = map1.begin(); it2 != map1.end(); it2++){
		std::cout << "Key: " << it2->first << "\n";
		std::cout << "Value: " << it2->second << "\n";
	}

	//multi map, duplicate keys as long as the values are different
	std::multimap<int, std::string> mmap1;
	mmap1.insert(std::pair<int,std::string> (1,"test"));
	mmap1.insert(std::pair<int,std::string> (1,"test2"));
	mmap1.insert(std::pair<int,std::string> (3,"test3"));

	std::map<int,std::string>::iterator it3;
	for(it3 = mmap1.begin(); it3 != mmap1.end(); it3++){
		std::cout << "Key: " << it3->first << "\n";
		std::cout << "Value: " << it3->second << "\n";
	}

	//container adapters (stacks)
	std::stack<std::string> custs;
	custs.push("Aaron");
	custs.push("Frog");
	custs.push("Not");
	int size = custs.size();
	if(!custs.empty()){
		for(int i = 0; i < size; i++){
			std::cout << custs.top() << "\n";
			custs.pop();
		}
	}

	//queues
	std::queue<std::string> cast;
	cast.push("Brid");
	cast.push("test");
	cast.push("original");
	int size2 = cast.size();
	if(!cast.empty()){
		for(int i = 0; i < size2; i++){
			std::cout << cast.front() << "\n";
			cast.pop();
		}
	}

	//priority queue largest value at the top
	std::priority_queue<int> nums;
	nums.push(1);
	nums.push(5);
	nums.push(3);
	int size3 = nums.size();
	if(!nums.empty()){
		for(int i = 0; i < size3; i++){
			std::cout << nums.top() << "\n";
			nums.pop();
		}
	}	

	//enums
	enum day{Mon=1, Tues, Weds=3, Thurs, Fri=6};
	enum day tuesday = Tues;
	std::cout << "Tuesday is the: " << tuesday << "nd day of the week\n";
	for(int i = Mon; i <= Fri; i++){
		std::cout << i << "\n";
	}


	return 0;
}