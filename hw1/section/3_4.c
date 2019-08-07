#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main()
{
	struct sigaction intAction;
	sigaction(SIGINT, NULL, &intAction);
	sigaction(SIGQUIT, &intAction, NULL);

	while(1);

	return 0;
}
