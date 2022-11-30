/* WAP to demonstrate the cat program*/

#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main( int argc,char *argv[])
{
        // declaration of variables
	int fd,file;
	char buf[100];
	// opening a file which is passed in command line argument
	fd=open(argv[1],O_RDONLY);
	
	// condition to check whether the arguments are passed or not
	if(fd<0)
	{
		printf("File open error found");
	}
	else
	{ 
	        // condition to read a content of a file
		while((file=read(fd,buf,1))>0)
		{
		        // printing the content of a file
			printf("%s",buf);
		}
		close(fd);
	}
}



