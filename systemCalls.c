// System Calls

// PID of child process and parent process

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	int pid;
	pid = fork();
	
	if (pid < 0) {
		printf("Fork Failed");
	}
	
	else if (pid == 0) {
		printf("Child Process Created \n");
		printf("PID of Child Process is %d\n", getpid());
		printf("PID of Parent Process is %d\n\n",getppid());
		execlp("/bin/ls", "ls", NULL);
		exit(1);
	}
	
	else {
		wait(NULL);
		printf("Child Process Complete!\n\n");
		printf("PID of Parent Process is %d\n", getpid());
	}
	
	return 0;
}

