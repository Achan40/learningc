#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	/*basic variables and string insertions*/
	char myName[] = "Aaron";
	int myAge = 22;	

	printf("There once was an individual named: %s\n", myName);

	myAge = 23;

	printf("He was approximately %d years old\n", myAge);

	/*basic data types*/
	int age = 40;
	double score = 3.4;
	char grade = 'D';
	char arrayofChars[] = "This is a string(array)";

	/*Exploring printf function*/
	printf("Hello World\n");
	printf("Print out Number: %d\n",age);
	printf("Print out Text: %s\n",arrayofChars);
	printf("Print out double: %f\n",score);

	/*Working with numbers in C*/
	printf("%f", 5 * 6.0 );
	printf("If you do math w just ints, you will get ints back %d\n", 5 / 4 );
	printf("using functions from math library %f %f \n", pow(3,2), floor(36.343));

	return 0;
}