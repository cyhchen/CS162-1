#include <stdio.h>
#include <pthread.h>

void* helper(void* arg)
{	
	int* num = (int*) arg;
	*num = 2;
	return NULL;
}
int main()
{	
	int i;
	pthread_t thread;
	pthread_create(&thread, NULL, &helper, &i);
	pthread_join(thread, NULL);
	printf("i is %d\n", i);
	return 0;
}
