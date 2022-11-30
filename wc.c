/* program to count the words, lines and characters*/

// Header file inclusion
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main( int argc,char *argv[])
{
        // Declaration of variables
	int fd,file,cha;
	char buf[100];
	
	// Opening a file
	fd=open(argv[1],O_RDONLY);
	// condition to check whether the argument is passed or not
	if(fd<0)
	{
		printf("File open error found");
	}
	else
	{  
		int line=0,word=0,chara=0;
		// condition to traverse till the last character
		while((file=read(fd,buf,1))>0)
		{       
		        //printf("i value is %d\n",cha);
			chara++;
			// condition to count the lines
			if(buf[cha] =='\n')
				line++;
				
			// condition to count the words	
			if(buf[cha] ==' '|| buf[cha] == '\n')
				word++;
		}
		//printf("After loop %d\n",cha);
		printf(" %d  %d  %d %s",line,word,chara,argv[1]);
		printf("\n");
		close(fd);
	}
}


