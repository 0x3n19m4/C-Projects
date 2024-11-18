#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
	char h[6] = "hello";

	h[0] = toupper(h[0]);
	
	printf("%s \n", h);
	return 0;
} 
