#include <stdio.h>
#include <stdlib.h>

int main(){

	/*writing files*/
	FILE * fpointer = fopen("employees.txt", "w");

	fprintf(fpointer, "Person 1, Aaron\nPerson 2, Test");

	fclose(fpointer);

	return 0;
}