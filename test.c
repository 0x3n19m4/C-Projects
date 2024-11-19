#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "cpu0 3953 7285 7492 2634";
    char *delim = "cpu0";
    char *token;
    char *rest;

    token = strstr(str, delim);
    if (token != NULL) {
        token += strlen(delim);

        while (*token == ' ') {
            token++;
        }

        rest = token;
        printf("%s\n", token);
    } else {
        printf("String '%s' not found in '%s'\n", delim, str);
    }

    return 0;
}

