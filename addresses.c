#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char *s[10];
    char *t[] = malloc(strlen(*s) + 1);

    printf("s: ");
    fgets(*s, sizeof(s), stdin);

    for (int i = 0; i < strlen(*s) + 1; i++)
    {
        t[i] = s[i];
    }

    if (strlen(*t) > 0)
    {
        t[0] = toupper(*t[0]);
    }

    printf("s: %p\n", s);
    printf("t: %p\n", t);
}