#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int is_divisible(int divisor, int dividend) {
	int id = getpid();
	printf("Checker process [%d]: Starting.\n", id);
	if ( dividend % divisor == 0 ) {
		printf("Checker process [%d]: %d *IS* divisible by %d.\n", id, dividend, divisor);
		printf("Checker process [%d]: Returning 1.\n", id);
		exit(1);
	}
	else {
		printf("Checker process [%d]: %d *IS NOT* divisible by %d.\n", id, dividend, divisor);
		printf("Checker process [%d]: Returning 0.\n", id);
		exit(0);
	}
}

int main(int argc, char *argv[]) {
	is_divisible(atoi(argv[0]), atoi(argv[1]));
	return 0;
}
