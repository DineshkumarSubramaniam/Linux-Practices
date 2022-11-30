/* WAP create two threads using pthreads and print even no and odd no alternatively */

// for standard library function's
#include <stdlib.h>
// for input and output file
#include <stdio.h>
// for thread operation's
#include <pthread.h>
//for Linux access
#include <unistd.h>


// Global variable declaration
int i = 0;
int maximum;


// function call
void* routine()
{
	// condition check to print till max. value
	while(i <= maximum) 
	{
		// condition to print even numbers
		if(i % 2 == 0)
		{
			printf(" Even number : %d\n",i);
			i++;
			sleep(1);
		}
	}
	pthread_exit(0);
}


void* routine2()
{
	// condition check to print till max. value
	while(i <= maximum) 
	{
		// condition to print odd numbers
		if(i % 2 == 1)
		{
			printf(" Odd number : %d\n",i);
			i++;
			sleep(1);
		}
	}
	pthread_exit(0);
}




int main() 
{   
	// User input maximum range
	printf("Enter the maximum range: ");
	scanf("%d",&maximum);
	printf("\n");
	// declaration of thread structure
	pthread_t p1, p2;

        // Creating a thread1
	pthread_create(&p1, NULL , &routine, NULL);
	
	// Creating a thread1
	pthread_create(&p2, NULL, &routine2, NULL);

	// for maintaining the communication b/w threads we use pthread_join
	pthread_join(p1, 0);
	pthread_join(p2, 0);


	return 0;
}




