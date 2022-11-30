/* Program to access fork*/

// for input and output file
#include<stdio.h>
// standard lib function
#include<stdlib.h>
//for Linux access
#include<unistd.h>
// for pid 
#include<sys/types.h>

int main()
{      
        // Assigning the fork() to pid
	pid_t pid = fork();

        // Condition to check the child process ID
	if (pid==0) 
	{
		printf("This is the Child process and pid is: %d\n",getpid());
		exit(0);
	}
	// Condition to check the parent process ID
	else if (pid > 0)
	{
		printf("This is the Parent process and pid is: %d\n",getpid());
	}
	else 
	{
		printf("Error while forking\n");
		exit(EXIT_FAILURE);
	}
	return 0;
}


