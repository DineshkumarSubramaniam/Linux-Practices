/* program to copy a content of a file*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
   // declaration of variables
   int so_file, de_file,n;
   char buff[50];

   
/*if(argc<3)
{
       printf("Error opening a file");
}

if(((so_file= open(argv[1], O_RDONLY)) < 0 || ((de_file=open(argv[2], O_CREAT |  O_WRONLY, 0777))==1)))
    {
       printf("File open error\n");
    }
*/
// opening an source file
so_file = open(argv[1], O_RDONLY);
//creating an destination file
de_file = open(argv[2], O_CREAT | O_WRONLY,0777);

// condition to check whether the arguments passed or not
if(argc < 3)
{
       printf("File open error found");
}

// condition to copy a source file content to des. file 
while((n=read(so_file, buff, 1))>0)

     if(write(de_file, buff, n)!=n)
        {
           printf("problem in writing a content");
        }
       // Closing a file
       close(so_file);
       close(de_file);
       return 0;    
 }
 
 
 
