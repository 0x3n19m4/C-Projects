#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
	char bar[13] = "[";
	int percent = 0;

	memset(bar+1, ' ', 10);
	bar[11] = ']';
	bar[12] = '\0';

	for (int i = 0; i < 10; i++)
	{
		bar[i + 1] = '#';
		printf("\r%s %d%%", bar, percent += 10);
		fflush(stdout);
		usleep(200000);
	}

	printf("\nDone!\n");

	return 0;
}