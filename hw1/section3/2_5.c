#include <stdio.h>
#include <pthread.h>

void* worker(void* arg)
{	
	int* data = (int*) arg;
	*data = *data + 1;
	printf("Data is %d\n", *data);
	return (void*) 42;
}

int data;

int main()
{	
	int status;
	data = 0;
	pthread_t thread;

	pid_t pid = fork();
	
	if(pid == 0){	
		pthread_create(&thread, NULL, &worker, &data);
		pthread_join(thread, NULL);
	}
	else{	
		pthread_create(&thread, NULL, &worker, &data);
		pthread_join(thread, NULL);
		pthread_create(&thread, NULL, &worker, &data);
		pthread_join(thread, NULL);
		wait(&status);
	}
	return 0;
}
