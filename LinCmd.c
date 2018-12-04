#include <stdlib.>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#define MSGSIZE 256 //buffer size

//argc = number of commands
//argv = commands saved and accesed with a parameter
int main(int argc,char* argv[]) 
{
	int pid;
	pid = fork();
	switch(pid) 
	{
		case 1: //No input detected
			printf("Please input a command \n");
		
		case 0: //child
			printf("\nParent PID: %d" , getppid());
			printf("\nChild PID: %d" , getpid()); 
			printf("\nCompleted: %d" , getpid());
			execvp(argv[1], &argv[1]);
			break;
		
		default: //parent
			wait(&pid);
			printf("\nCompleted: %d \n" , getpid());
			exit(0);
	}
}


