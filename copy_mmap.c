/*Write an Linux System Programming copy one file content to another file using mmap() system call*/

#include<stdlib.h>
//for string 
#include<string.h>
// for input and output file
#include<stdio.h>
// for creating and reading a file
#include<fcntl.h>
// for using mmap
#include<sys/mman.h>
//for Linux access
#include <unistd.h>
// for fstat 
#include <sys/types.h>
#include <sys/stat.h>
int main(int argc, char *argv[])
{
	// condition to check whether the required argument are passed or not
	if(argc<3)
	{
		printf("ERROR:Less argument passed\n");
		return 0;
	}
	// Declaration of variables 
	int so_file, de_file;
	char *sou, *dest;
	// stat is used to find the size of an file
	/* SOURCE */ 
	struct stat s;   
	//opening and Reading an file  
	so_file = open(argv[1], O_RDONLY);

	// calculating the size of source file
	int size = lseek(so_file,0,SEEK_END);

	// mapping the source file     
	sou = mmap(NULL, 1, PROT_READ, MAP_PRIVATE, so_file, 0);

	// creating an destination file
	de_file = creat(argv[2], 0777);
	// allocating the size of des_file by calculating the size of source_file
	ftruncate(de_file, size);
	// Opening an destination file in read/write mode
	de_file = open(argv[2], O_RDWR | O_CREAT ,0777);

	// mapping destination file
	dest = mmap(NULL, 1, PROT_READ | PROT_WRITE, MAP_SHARED, de_file, 0);

	/* COPY */
	/* from source to destination , number of bytes*/
	for(int i = 0; i<size; i++)
	{
		write(de_file,&sou[i], 1);
	}

	// unmapping the files from source
	munmap(sou, s.st_size);
	munmap(dest, s.st_size);

	close(so_file);
	close(de_file);

	return 0;
}


