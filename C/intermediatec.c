#include <stdio.h>
#include <stdlib.h>

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

	return 0;
}

/*functions*/
double cubed(double num){
	return num * num * num;
}

