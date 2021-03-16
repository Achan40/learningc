#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*functions*/
void sayHi(char name[], int age){
	printf("Hello %s, you are %d\n", name,age);
}

/*If statements*/
int max(int num1, int num2, int num3){
	int result;
	
	if(num1 >= num2 && num1 >= num3){
		result = num1;
	} else if (num2 >= num1 && num2 >= num3){
		result = num2;
	} else {
		result = num3;
	}
	return result;
}

/*prototyping a function*/
double cubed(double num);

/*strucst*/
struct Student
{
	char name[50];
	char major[50];
	int age;
	double gpa;
};

int main()
{
	/*Arrays*/
	int luckyNumbers[] = {4,8,16,24,32};
	luckyNumbers[0] = 40;
	printf("%d\n", luckyNumbers[0]);

	int emptyNums[20];
	emptyNums[1] = 30;
	emptyNums[0] = 10;
	printf("%d\n", emptyNums[0]);

	/*functions*/
	sayHi("Aaron", 22);

	printf("Cubed function Answer: %f\n", cubed(3.0));

	printf("%d\n", max(4, 10, 15));

	/*switch statements*/
	char grade = 'A';
	switch(grade){
		case 'A':
			printf("You did great!\n");
			break;
		case 'B':
			printf("You did okay!\n");
			break;
		case 'C':
			printf("You did poorly!\n");
			break;
		case 'D':
			printf("You did very poorly!\n");
			break;
		case 'F':
			printf("You failed!\n");
			break;
		default:
			printf("Invalid Grade\n");		
	}

	/*using structs*/
	struct Student student1;
	student1.age = 22;
	student1.gpa = 3.2;
	strcpy(student1.name, "Jim");
	strcpy(student1.major, "Economics");


	struct Student student2;
	student2.age = 25;
	student2.gpa = 3.7;
	strcpy(student1.name, "Aaron");
	strcpy(student1.major, "Statistics");

	printf("%f\n", student2.gpa);

	/*while loops*/
	int index = 1;
	while(index <= 5){
		printf("%d\n", index);
		index++;
	}

	/*do while loop, does not check condition beforehand*/
	int newindex = 6;
	do {
		printf("%d\n", newindex);
		newindex++;
	}while(newindex <= 5);

	return 0;
}

/*functions*/
double cubed(double num){
	return num * num * num;
}

