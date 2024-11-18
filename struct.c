#include <stdio.h>

typedef struct
{
	int age;
	char * name;
} person;

int main(void)
{
	person tom = {23, "Tom"};
	printf("Age: %d \t Name: %s", tom.age, tom .name);
	return 0;
}

