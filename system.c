/* own version of system library*/

// standard function's
#include<stdio.h>
// exit function 
#include<stdlib.h>
//for finding error no
#include<errno.h>
////for Linux access
#include<unistd.h>
// for pid 
#include<sys/types.h>

// function declaration 
void my_system(char *);


int main(int argc, char* argv[])
{
    // function call
    my_system(argv[1]);
    exit(0);
} 

// called function
void my_system(char * id)
{
    // declaration of variables
    pid_t pid;
    int i, err;
    pid = fork();
    if (pid == 0)
    {
        i = execl("/bin/sh", "sh", "-c", id, (char*) NULL);
        if (i == -1)
        {
            perror("Execve fails");
            exit(0);
        }
    }
    else
    {
        wait(&err);
    }
}
