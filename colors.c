#include <stdio.h>
#include <unistd.h>

int main()
{
        for (int i = 0; i < 10; i++)
	{
		sleep(1);
		printf("\033[0;31m");
		printf("#");
		printf("\033[0m");
		fflush(stdout);
	}
	return 0;
}
