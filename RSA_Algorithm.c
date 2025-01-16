#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int gcd(int e, int phi)
{
    if (phi == 0) return e;
    return gcd(phi, e % phi);
}

int phi(int N, int p, int q)
{
    return (p - 1) * (q - 1);
}

int extend_gcd(int a, int b, int *x, int *y)
{
    if (b == 0)
    {
	*x = 1;
	*y = 0;
	return a;
    }
    int x1, y1;
    int g = extend_gcd(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    return g;
}

int mod_inverse(int e, int phi_N)
{
    	int x, y;
    	int g = extend_gcd(e, phi_N, &x, &y);
    
    	if (g != 1)
    	{
        	printf("There is no inverse element");
        	exit(1);
    	}
    
    	return (x % phi_N + phi_N) % phi_N;
}

int compute_private_key(int e, int phi_N)
{
    	return mod_inverse(e, phi_N);
}

int generateRandom()
{
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
    int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 
                   47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 
                   107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 
                   167, 173, 179, 181, 191, 193, 197, 199 };
    int size = sizeof(primes) / sizeof(primes[0]);
    return primes[rand() % size];
=======
>>>>>>> e4a4f7a (Update RSA_Algorithm.c)
=======
>>>>>>> fe4bedf (Update RSA_Algorithm.c)
	int primes[50] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 
                                47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 
                                107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 
                                167, 173, 179, 181, 191, 193, 197, 199};
    
    	int size = sizeof(primes) / sizeof(primes[0]);
	int randomIndex = rand() % size;
	return primes[randomIndex];
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 8c5d425 (Update RSA_Algorithm.c)
>>>>>>> e4a4f7a (Update RSA_Algorithm.c)
=======
>>>>>>> fe4bedf (Update RSA_Algorithm.c)
}

int main()
{
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
        srand(time(NULL));
	
        int p = generateRandom();
        int q = generateRandom();
=======
>>>>>>> e4a4f7a (Update RSA_Algorithm.c)
=======
>>>>>>> fe4bedf (Update RSA_Algorithm.c)
		srand(time(NULL));
		
    	int p = generateRandom();
    	int q = generateRandom();
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 8c5d425 (Update RSA_Algorithm.c)
>>>>>>> e4a4f7a (Update RSA_Algorithm.c)
=======
>>>>>>> fe4bedf (Update RSA_Algorithm.c)

    	if(p == q)
    	{
        	q = generateRandom();
    	}

    	int N = p * q;
    	int phi_N = phi(N, p, q);

    	int e;
    	do
    	{
        	e = generateRandom();
    	} while (e >= phi_N || gcd(e, phi_N) != 1);

    	int d = compute_private_key(e, phi_N);

    	printf("p: %d\tq: %d\n", p, q);
    	printf("N: %d\tPhi(N): %d\n", N, phi_N);
    	printf("e: %d\td: %d\n", e, d);

    	return 0;
}
