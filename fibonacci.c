#include <stdio.h>

int main()
{
    int prev, result;
    int curr = 1;

    for (int i = 0; i < 20; i++)
    {
        result = curr + prev;
        prev = curr;
        curr = result;
        print("%d\n", result);
    }

    return 0;
}