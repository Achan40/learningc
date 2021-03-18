#include <stdio.h>
#include <stdlib.h>

int	main(){

	/*for loops*/
	int i = 1;
	while(i <= 5){
		printf("%d\n", i);
		i++;
	}

	int luckyNumbers[] = {4, 8, 12, 16, 15};
	int j;
	for(j = 1; j < 5; j++){
		printf("%d\n", luckyNumbers[j]);
	}

	/*nested loops and 2D arrays*/
	int nums[3][2] = {
		{1,2},
		{3,4},
		{5,6}
	};

	int x,y;
	for(x = 0; x < 3; x++){
		for(y = 0; y < 2; y++){
			printf("%d\n", nums[x][y]);
		}
		printf("\n");
	}

	/*Memory adresses and pointers*/
	int age = 30;
	double gpa = 3.4;
	char grade = 'A';

	printf("age: %p\ngpa: %p\ngrade: %p\n", &age, &gpa, &grade);

	/*pointers*/
	int * pAge = &age;
	double * pGpa = &gpa;
	char * pGrafe = &grade;

	/*dereferencing pointers*/
	printf("%d\n", *pAge);
	printf("%d\n", *&age);


	return 0;
}