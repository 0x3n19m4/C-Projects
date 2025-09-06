#include <stdio.h>

int main(int argc, char *argv[])
{
        int x0 = 7;
        double a = x0;

        for (int i = 0; i < 3; i++)
        {
                a = (a + 123/a)/2;
        }

        printf("%lf\n", a);

        return 0;

}