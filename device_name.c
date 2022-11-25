/*2. Write a program to read framebuffer fixed size information*/

#include<stdio.h>
// for creating and reading a file
#include<fcntl.h>
// linux access
#include<linux/input.h>
// ioctl access
#include<sys/ioctl.h>
// For perror function
#include<errno.h>
int main(int argc, char *argv[])
{
	// Declaration of variables
	int fd;
	char name[200];

	//argv[1] has in format /dev/input/event0

	// opening an file 
	fd = open(argv[1], O_RDONLY);

	// condition to check whether the required argument are passed or not
	if (fd < 3)
	{
		perror("ERROR");
		return 0;
	}
	//function call to get device name
	ioctl(fd, EVIOCGNAME(sizeof(name)), name);
	printf("Entered device name: %s", name);
	printf("\n");

	return 0;
}

