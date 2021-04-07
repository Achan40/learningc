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

#include <deque>
#include <list>
#include <forward_list>

bool isEven(const int &val){
	return(val % 2) == 0;
}

int main(int argc, char const *argv[])
{
	//deques
	std::deque<int> deq1;
	deq1.assign({11,12});
	deq1.push_back(5);
	deq1.push_front(1);
	std::cout << "Size: " << deq1.size() << "\n";
	std::cout << deq1[0] << "\n";
	std::cout << deq1.at(0) << "\n";
	std::deque<int>::iterator it = deq1.begin() + 1;
	deq1.insert(it, 3);
	int tempArr[5] = {6,7,8,9,10};
	deq1.insert(deq1.end(), tempArr, tempArr+5);
	deq1.erase(deq1.end());
	deq1.erase(deq1.begin(), deq1.begin()+2);
	deq1.pop_front();
	deq1.pop_back();
	std::deque<int> deq2(2,50);
	deq1.swap(deq2);

	for(int i: deq1){
		std::cout << i << "\n";
	}

	//lists
	int arr[5] = {1,2,3,4,5};
	std::list<int> list1;
	list1.insert(list1.begin(), arr, arr + 5);
	list1.assign({10,20,30});
	list1.push_front(5);
	list1.push_back(1);
	std::cout << "Size of List: " << list1.size() << "\n";
	//cannot access list items by index directly
	std::list<int>::iterator it2 = list1.begin();
	std::advance(it2, 1);
	std::cout << "2nd Index: " << *it2 << "\n";
	it2 = list1.begin();
	list1.insert(it2,8);
	list1.erase(list1.begin());
	it2 = list1.begin();
	std::list<int>::iterator it3 = list1.begin();
	std::advance(it3,2);
	list1.erase(it2,it3);
	list1.pop_front();
	list1.pop_back();
	int arr2[6] = {10,9,8,7,6,6};
	std::list<int> list2;
	list2.insert(list2.begin(), arr2, arr2 + 6);
	list2.sort();
	list2.reverse();
	list2.unique();

	for(int i: list1){
		std::cout << i << "\n";
	}

	std::cout << "\n";

	for(int i: list2){
		std::cout << i << "\n";
	}

	//forward lists, move forward, cannot move back
	std::forward_list<int> fl1;
	fl1.assign({1,2,3,4});
	fl1.push_front(0);
	fl1.pop_front();
	std::cout << "Front: " << fl1.front();
	std::forward_list<int>::iterator it4 = fl1.begin();

	it4 = fl1.insert_after(it4, 5);
	it4 = fl1.erase_after(fl1.begin());
	fl1.emplace_front(6);
	fl1.remove(6);
	fl1.remove_if(isEven);

	std::forward_list<int> fl2;
	fl2.assign({9,8,7,6,6});
	fl2.unique();
	fl2.sort();
	fl2.reverse();
	fl1.merge(fl2);


	for(int i: fl1){
		std::cout << i << "\n";
	}
	
	for(int i: fl2){
		std::cout << i << "\n";
	}

	return 0;
}