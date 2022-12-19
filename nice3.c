/* Program to demonstrate nice command in Linux*/

// Inclusion of header file
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(int argc , char*argv[])
{
       // condition to check the required argument is passed or not
       if(argc != 3)
        {
          printf("give the process id and nice value\n");
          return 1;
        }
        
        // dec of variables
        int id, priority,ret,nice;
        
        // converting string to integer
        // process id
        id = atoi(argv[1]);
        // nice value
        nice= atoi(argv[2]);
    
    // getting the priority values
    priority = getpriority(PRIO_PROCESS, id);
    
    // set priority and saving in a variable
    ret = setpriority(PRIO_PROCESS, id,nice);

    // condition to print the set priority
    if (ret == 0)
    {
        printf("priority is set\n");
        priority = getpriority(PRIO_PROCESS, id);
        printf("new priority : %d\n",priority);
    }
    // condition to print if priority set is not found 
    else
    {
        printf("Error in setting the priority\n");
    }   
}



/*
PRIO_PROCESS
indicates that the who argument is to be interpreted as a process ID

PRIO_PGRP
indicates that the who argument is to be interpreted as a process group ID

PRIO_USER
indicates that the who argument is to be interpreted as a user ID
*/
