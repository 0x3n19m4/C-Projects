#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
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
        	perror("There is no inverse element");
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
	int primes[50] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 
                                47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 
                                107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 
                                167, 173, 179, 181, 191, 193, 197, 199 };
    
    	int size = sizeof(primes) / sizeof(primes[0]);
	int randomIndex = rand() % size;
	return primes[randomIndex];
}

int ModForLarge(long long base, int exp, int mod)
{
	long long result = 1;
	base = base % mod;

	while(exp > 0)
	{
		if(exp % 2 == 1)
		{
			result = (result * base) % mod;
		}

		exp = exp >> 1;

		base = (base * base) % mod;
	}

	return result;
}

int encrypt(long x, int e, int N)
{
	return ModForLarge(x, e, N);
}

char *FileRead(const char *input)
{
	FILE *in = fopen(input, "rb");
	if(!in)
	{
		perror("File doesn't open");
		return NULL;
	}

	char *buffer = NULL;
	size_t size = 0;
	size_t capacity = 1024;
	buffer = malloc(capacity);
	if(!buffer)
	{
		perror("Memory allocating error.");
		fclose(in);
		return NULL;
	}

	size_t bytes_read;
	while((bytes_read = fread(buffer + size, 1, 1024, in)) > 0)
	{
		size += bytes_read;
		if(size + 1024 > capacity)
		{
			capacity *= 2;
			buffer = realloc(buffer, capacity);
			if(!buffer)
			{
				perror("Memory allocating error.");
				fclose(in);
				return NULL;
			}
		}
	}

	buffer[size] = '\0';
	fclose(in);
	return buffer;
}

int FileEncrypt(const char *input_file, const char *output_file, int e, int N)
{
	FILE *out = fopen(output_file, "w");

	if(!out)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}

	char *data = FileRead(input_file);
	int lenght = strlen(data);
	char *encrypted_data = malloc(lenght);
	int ascii_codes[100], i;
	

	if(!encrypted_data)
	{
		perror("Memory allocating error");
		fclose(out);
		exit(EXIT_FAILURE);
	}

	if(data)
	{
		printf("Text: %s\n", data);
	}

	for (i = 0; i < lenght; i++) 
	{
		ascii_codes[i] = (int)data[i];
		printf("ASCII %c = %d\n", data[i], ascii_codes[i]);
	}

	for(int i = 0; i < lenght; i++)
	{
		encrypted_data[i] = encrypt(data[i], e, N);
		printf("Encrypted: %d\n", (unsigned char)encrypted_data[i]);
	}

	fwrite(&encrypted_data, sizeof(char), strlen(encrypted_data), out);

	fclose(out);
	free(data);
	free(encrypted_data);
	return 0;
}

int decrypt(long long x, int d, int N)
{
	return ModForLarge(x, d, N);
}

int FileDecrypt(const char *input_file, const char *output_file, int d, int N)
{
	FILE *out = fopen(output_file, "wb");

	if(!out)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}

	char *data = FileRead(input_file);
	int lenght = strlen(data);
	char *decrypted_data = malloc(lenght);

	if(data)
	{
		printf("Text: %s\n", data);
	}

	if(!decrypted_data)
	{
		perror("Memory allocating error");
		fclose(out);
		free(data);
		exit(EXIT_FAILURE);
	}

	for(int i = 0; i < lenght; i++)
	{
		decrypted_data[i] = decrypt(data[i], d, N);
		printf("Decrypted: %d\n", (unsigned char)decrypted_data[i]);
	}

	fwrite(&decrypted_data, sizeof(char), strlen(decrypted_data), out);

	/*
	int encrypted;
	while(fread(&encrypted, sizeof(int), 1, in))
	{
		//int encrypted_file = ModForLarge(byte, e, N);
		//fwrite(encrypted_file, sizeof(encrypted_file), 1, out);
		unsigned char decrypted = decrypt(encrypted, d, N);
		fwrite(&decrypted, sizeof(unsigned char), 1, out);
	}
	*/

	fclose(out);
	free(data);
	free(decrypted_data);
	return 0;
}

int main(int argc, char *argv[])
{
	srand(time(NULL));
		
    	int p = generateRandom();
    	int q = generateRandom();

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

	printf("Usage: \n");
	printf("\t --encypt <file to encrypt>\n");
	printf("\t --decrypt <file to decrypt>\n");

    	printf("p: %d\tq: %d\n", p, q);
    	printf("N: %d\tPhi(N): %d\n", N, phi_N);
    	printf("e: %d\td: %d\n", e, d);

	long ToEncrypt = 404;

	long long encrypted = encrypt(ToEncrypt, e, N);
	printf("Encrypted: %d\n", encrypted);

	long long decrypted = decrypt(encrypted, d, N);
	printf("Decrypted: %d\n", decrypted);

	FileEncrypt(argv[1], argv[2], e, N);
	FileDecrypt(argv[2], argv[3], d, N);

	return 0;
}
