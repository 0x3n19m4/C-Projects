#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *passwd = "biba";
	char *inpt;

	inpt = malloc(5 * sizeof(inpt));

	printf("Enter a password: \n");
	fgets(inpt, sizeof(inpt), stdin);

	if (inpt != passwd)
	{
		printf("Invalid Password");
	}
	else
	{
		printf("Welcome\n");
	}

	free(inpt);

	return 0;
}
