#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
	int myInt;
	char myChar;
};

/*members in a union share a memeory size*/
union myUnion
{
	int myInt; /// 4 bytes of memory
	char myChar; /// 1 byte of memory
};

int main()
{
	union myUnion uni;
	struct student record;

	record.myInt = 5;
	record.myChar = 6;

	uni.myInt = 4; 
	uni.myChar = 9; /// as soon as you assign myChar, memory is overwritten

	printf("%i\n", uni.myInt);
	printf("%i\n", uni.myChar);
	printf("The size of struct: %zu\n", sizeof(record));
	printf("The size of union: %zu\n", sizeof(uni));

	return 0;
}