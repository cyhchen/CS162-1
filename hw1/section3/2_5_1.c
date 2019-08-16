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
	void* ret;
	int value;

	pid_t pid = fork();
	
	if(pid == 0){	
		pthread_create(&thread, NULL, &worker, &data);
		pthread_join(thread, (void**)&ret);
		value = (int)ret;
		printf("Return Value: %d\n", value);
	}
	else{	
		pthread_create(&thread, NULL, &worker, &data);
		pthread_join(thread, (void**)&ret);
		value = (int)ret;
		printf("Return Value: %d\n", value);
		
		pthread_create(&thread, NULL, &worker, &data);
		pthread_join(thread, (void**)&ret);
		value = (int)ret;
		printf("Return Value: %d\n", value);

		wait(&status);
	}
	return 0;
}
