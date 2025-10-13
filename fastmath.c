#include <stdio.h>
#include <stdint.h>

float Q_rsqrt(float number)
{
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y = number;
    i = *(long *) &y;
    i = 0x5f3759df - (i >> 1);
    y = *(float *) &i;
    y = y * (threehalfs - (x2 * y * y));

    return y;
}

static inline uint32_t udiv_magic128(uint32_t x, unsigned long long m, unsigned s)
{
    __uint128_t res = (__uint128_t)x * m;
    return (uint32_t)(res >> s);
}

int main()
{
    float sqrt_result;
    int div_result;

    sqrt_result = Q_rsqrt(121);
    printf("Result %f\n", sqrt_result);

    div_result = udiv_magic128(46, 0xCCCCCCCD, 35);
    printf("Div Result: %d\n", div_result);

    return 0;
