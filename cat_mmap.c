/* Write a program show the /dev/input/event0 device name*/
// for input and output file
#include <stdio.h>
// for using mmap
#include <sys/mman.h>
//for Linux access
#include <unistd.h>
// for creating and reading a file
#include <fcntl.h>
// for fstat 
#include<sys/stat.h>
int main(int argc, char* argv[])
{
	// condition to check whether the required argument are passed or not
	if(argc < 2)
	{
		printf("Error : Less argument passed\n");
		return 0;
	}
	// Declaration of variables
	int fd;
	char * file;
	struct stat str;
	//opening and Reading an file  
	fd = open(argv[1], O_RDWR); 
	//stores the memory indicated in buffer   
	fstat(fd,&str);
	// mapping a file
	file = mmap(NULL,str.st_size,PROT_READ,MAP_SHARED,fd, 0);
	// Loop to print the cat file
	for(int i = 0;i<str.st_size;i++)
	{
		printf("%c",file[i]);
	}

	munmap(file, str.st_size);
	close(fd);
	return 0;
}
