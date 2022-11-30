/* program to demonstrate zombie */

// header file insertion 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
        // Condition to get child id
	if (fork() ==0)
	{
		printf("\nChild pid is = %d\nppid is = %d\n", getpid(),getppid());
		// After 5 seconds child becomes zombie
		sleep(5);
		//printf("Child terminated\n");
	}
	else
	{
		// Parent executing for infinite
		printf("In parent pid = %d\nppid = %d\n", getpid(), getppid());
		//while(1);
	}
	exit(1);
}
