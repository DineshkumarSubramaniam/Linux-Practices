/* program to demonstrate execve */

//execve function
#include <unistd.h>
// standard function's
#include <stdio.h>
// exit function 
#include <stdlib.h>

// Function declaration
char *const exec_argv[] = {"ps","-eaf",0};

int main()
{ 
        // variable declaration
	int val;
        
	printf("STARTED HERE\n");
        // assigning execve to variable
	val = execve("/bin/ps",exec_argv,NULL);
	
	// condition to check the operation failed or not
	if (val < 0)
	{
		perror("exec operation fails");
		exit(0);
	}
	
	printf("Everything Printed\n");
}
