#include <stdio.h>

int main(void)
{
	int n;

	do
	{
		n = scanf("%d", &n);
	}
	while(n < 1);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("#");
		}
		printf("\n");
	}

	/*
	int i = 0;

	for (int i = 0; i < 3; i++)
	{
		printf("meow\n");
	}
	*/
	
	/*
	while (counter > 0)
	{
		printf("meow\n");
		counter = counter - 1;
	}
	*/

	/*
	char c;

	c = getchar();

	if (c == 'y' || c == 'Y')
	{
		printf("Agreed.\n");
	}
	else if (c == 'n' || c == 'N')
	{
		printf("Not agreed.\n");
	}
	*/

	/*
	int x;
	int y;

	scanf("%d", &x);
	scanf("%d", &y);

	if (x < y)
	{
		printf("x is less than y");
	}
	else
	{
		printf("x is not less than y");
	}
	*/
	
	/*
	else if (x > y)
	{
		printf("x is greater than y");
	}
	else if (x == y)
	{
		printf("x is equal to y");
	}
	*/
	
	/*
	char name[10];
	
	printf("What's your name? ");
	fgets(name, sizeof(name), stdin);
	printf("Hello, %s", name);
	return 0;
	*/	
}