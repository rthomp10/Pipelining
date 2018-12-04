#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#define MSGSIZE 256 //buffer size

int main()
{
 char inbuf[MSGSIZE];	//buffer initialization
 int p[2];	//the pipe array
 pid_t pid; //holds process IDs
 
 if (pipe(p) == -1) //creates pipe and throws an error if not
 {
  perror("Pipe fail");
  exit(EXIT_FAILURE);
 }
 
 //pid is assigned with 
 switch(pid = fork()) 
 {
	 //In case there's a lack of resources or insufficient
	 //storage space is available
 	 case -1: 
	       perror("fork call");
	       exit(EXIT_FAILURE);
		   break;
		   
 	  case 0: //child writes
	       dup2(p[1], STDOUT_FILENO); //redirects error and std ouput
		   close(p[0]); //closes the link from child to pipe
		   close(p[1]);
		   execl( "./pre", "pre", (char *)0);
		   perror("The pre-process could not be executed");
		   return(EXIT_FAILURE);
	       break;
		   
	 default: //parent reads
	 	   close(p[1]);
	       dup2(p[0], STDIN_FILENO);
		   close(p[0]);
		   execl("./sort", "sort", (char *)0);
		   return(EXIT_FAILURE);
	}
	exit(0);
}
