#include <stdio.h>
#include <sys/types.h>

int main(void)
{
	pid_t pid = fork();
	int exit;
	if(pid != 0){
		waitpid(-1, &exit, 0);
	}
	printf("Hello World\n: %d\n", pid);

	return 0;
}
