#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid = fork();
	int exit;
	if(pid != 0){
		wait(&exit);
		char** argv = (char**)malloc(3 * sizeof(char*));
		argv[0] = "/bin/ls";
		argv[1] = ".";
		argv[2] = NULL;
		execv("/bin/ls", argv);
	}
	else{
		for(int i = 0; i < 10; i++)
		{
			printf("%d\n", i);
		}
	}

	return 0;
}
