#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int ) 
{
    char str[] = "Hello World";
    int int_str[50];
    int i = 0;

    for(int j = 0; str[j] != '\0'; j++) {
        int_str[i] = (int)str[j];
        i++;
    }

    for (int j = 0; j < i; j++) {
        printf("ASCII code of %c = %d\n", str[j], int_str[j]);
    }
    
}	
