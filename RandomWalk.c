#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

	/*declaration*/
	float p = 0.5;
	float q = 1 - p;

	int N = 1000;
	int walk = 1000;                   //total
	int a = 0;                      //right
	int b = 0;                      //left
	int m[100000] = { 0, };			//position
	float avr = 0;
	float var = 0;

	int tmp = 0;
	int initN = N;
	int initWalk = walk;

	int i = 0;
	srand(time(NULL));

	/*implemetation*/
	while (N > 0) {
		while (walk > 0) {
			tmp = rand();
			tmp = tmp % 2;

			if (tmp == 0) {
				b++;
			}
			else if (tmp == 1) {
				a++;
			}

			walk--;
		}

		m[initN - N] = a - b; //store the position
		printf("%dth position is %+d\n", initN - N, m[initN - N]);
		N--;

		//initialization
		a = 0;
		b = 0;
		walk = initWalk;
	}

	/*find average*/
	for (i = 0; i < initN; i++) {
		avr = avr + m[i];
	}

	if (avr != 0) {
		avr = avr / initN;
	}

	/*find variation*/
	for (i = 0; i < initN; i++) {
		var = var + (m[i] - avr)*(m[i] - avr);
	}

	var = var / initN;

	/*print result*/
	printf("-----------------result-------------------\n");
	printf("avr: %f\nvar: %f\n", avr, var);

}