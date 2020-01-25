#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "Checker.h"

int main(int argc, char *argv[]) {
	
	int divisor = atoi(argv[1]);
	
	int dividends[4];
	dividends[0] = atoi(argv[2]);
	dividends[1] = atoi(argv[3]);
	dividends[2] = atoi(argv[4]);
	dividends[3] = atoi(argv[5]);
	
	for (int i = 0; i < 4; ++i) {
		int childpid = fork();
		int divisible = -1;
		if (childpid == -1) {
			perror("Failed to fork");
			return 1;
		}
		if (childpid == 0) { 	/* Child process */
			char first[10], second[10];
			sprintf(first, "%d", divisor);
			sprintf(second, "%d", dividends[i]);
			execlp("Checker", first, second, (char *)NULL);
			perror("Failed to execlp");
			exit(0);
		} else { 				/* Parent process */
			printf("Coordinator: forked process with ID %d.\n", childpid);
			printf("Coordinator: waiting for process [%d].\n", childpid);
			int status;
			wait(&status);
			printf("Coordinator: child process %d returned %d.\n", childpid, WEXITSTATUS(status));
		}
	}
	
	printf("Coordinator: exiting.\n");
	
	return 0;
}
