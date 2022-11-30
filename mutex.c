/* WAP create two threads using pthreads and print even no and odd no alternatively */


// for standard library function's
#include <stdlib.h>
// for input and output file
#include <stdio.h>
// for thread operation's
#include <pthread.h>
//for Linux access
#include <unistd.h>


// creating an mutex variable
pthread_mutex_t mutex;
int i = 0, maximum;

// function
void* routine()
{
	pthread_mutex_lock(&mutex);
	while (i <= maximum)
	{
		//pthread_mutex_lock(&mutex);
		if(i % 2 == 0)
		{
			printf("%d  ", i);
			i++;
		}
		else if(i % 2 == 1)
		{
			printf("%d  ",i);
			i++;
		}       
		//pthread_mutex_unlock(&mutex);

	}
	pthread_mutex_unlock(&mutex);
}


// driver code
int main()
{
	printf("Enter the maximum value: ");
	scanf("%d",&maximum);
	printf("\n");
	// creating a thread structure
	pthread_t p1, p2;
	// mutex operation
	pthread_mutex_init(&mutex, NULL);

	// creating a thread 1
	if (pthread_create(&p1, NULL, &routine, NULL) != 0) 
	{
		return 1;
	}

	// creating a thread 2
	if (pthread_create(&p2, NULL, &routine, NULL) != 0) 
	{
		return 2;
	}

	if (pthread_join(p1, NULL) != 0)
	{
		return 5;
	}
	if (pthread_join(p2, NULL) != 0) 
	{
		return 6;
	}
	printf("\n");
	// Destroying mutex
	pthread_mutex_destroy(&mutex);
	return 0;
}




