/*Write a program to read framebuffer fixed size information*/
// for input and output file
#include<stdio.h>
// for creating and reading a file
#include<fcntl.h>
// linux access
#include<linux/input.h>
// ioctl access
#include<sys/ioctl.h>
#include<linux/fb.h>
// For perror function
#include<errno.h>
int main(int argc, char *argv[])
{
	// Declaration of variables
	int fd;
	// Opening a file
	fd = open (argv[1], O_RDONLY);

	// condition to check whether the required argument are passed or not
	if(fd < 3)
	{
		perror("ERROR");
		return -1;
	}


	// structure for 
	struct fb_var_screeninfo varInfo;

	// function to find the resolution        
	ioctl(fd, FBIOGET_VSCREENINFO,&varInfo);

	// Printing the pixel's
	printf("visible resolution %u\n", varInfo.xres);
	printf("visible resolution %u\n", varInfo.yres);
	printf("bits for pixel %u\n", varInfo.bits_per_pixel);

	return 0;
}
