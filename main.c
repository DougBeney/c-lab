#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	int i, howMany;
	int total;
	float average = 0.0;
	int * pointsArray;

	printf("how many numbers do u want to avg?\n");
	scanf("%d", &howMany);

	pointsArray = (int *) malloc(howMany * sizeof(int));

	for(i=0; i < howMany; i++) {
		scanf("%d", &pointsArray[i]);
		total += pointsArray[i];
	}

	average = (float)total / (float)howMany;
	printf("avg is %f", average);

	free(pointsArray);

	return 0;
}

