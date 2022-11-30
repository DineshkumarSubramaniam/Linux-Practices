/* program to demonstrate a echo command*/

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdlib.h>
int main(int argc ,char *argv[])
{
        // condition to check whether the arguments are passed or not
	if(argc < 2)
	{
		printf("\n");
		//write(1,"\n",1);
		//return 0;
	}
	int c;
	
	// condition to create a the required files
	for(c=1;c<argc;c++)
	{
		write(1,argv[c],strlen(argv[c]));
		write(1," ",1);
		//printf(" ");
	}
	//write(1,"\n",1);
	printf("\n");
}

