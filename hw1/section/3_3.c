#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigint_handler(int sig)
{
	char c;
	printf("\nOuch, you just hit CTRL-C?. Do you really want to quit [y/n]? ");
	c = getchar();
	if(c == 'y' || c == 'Y')
	{
		exit(1);
	}
	else if(c == 'n' || c == 'N') return;
}

int main()
{
	struct sigaction sig;
	sig.sa_flags = 0;
	sig.sa_handler = sigint_handler;

	sigaction(SIGINT, &sig, NULL);

	while(1);

	return 0;
}
