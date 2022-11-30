/* program to demonstrate the gethar() */

#include <stdio.h>
#include <unistd.h>
#include<sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
int main()
{
  // declaration of variables
  int fd;
  char buffer[200];
  // reading a character from terminal
  fd = read(0,buffer,200);
  fd = write(0,buffer,1);
  write(1,"\n",1);
  //printf("\n");
  return 0;
}
