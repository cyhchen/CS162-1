#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

void* helper(void* arg)
{	
	char* message = (char*) arg;
	strcpy(message, "I am the child");
	return NULL;
}

int main(){
	char* message = malloc(100);
	strcpy(message, "I am the parent");
	pthread_t thread;
	pthread_create(&thread, NULL, &helper, message);
	pthread_join(thread, NULL);
	printf("%s\n", message);

	return 0;
}
