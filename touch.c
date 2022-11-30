//System programming your own version of touch command
// standard input output 
#include <stdio.h>
//for linux access
#include <unistd.h>
// for command line arguments
#include <stdlib.h>
// for creating and reading a file
#include<fcntl.h>

int main(int argc, char *argv[])
{
         // declaration of variable
	int touch;
             
        //condition to check whether the argument is found or not
	if(argc < 2)
	{
		printf("Less argument found error\n");
	}
	
	//loop to create a file's
	for(int i=0;i<argc;i++)
	{
		touch = open(argv[i],O_CREAT,0777);
	}
	
	// condition to check the error
	if(touch < 0)
	{
		printf("File open error found");
	} 
	return 0;
}



