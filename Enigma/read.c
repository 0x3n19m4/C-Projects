#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
/*
char *file_read(const char *input)
{
	FILE *in = fopen(input, "r");
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
	while((bytes_read = fread(buffer + size, 1, 1024, in))> 0)
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
*/
int main(int argc, char *argv[])
{
	FILE *out = fopen("output_file.txt", "r");
	char encrypted_data[50];

	fread(&encrypted_data, sizeof(encrypted_data), 1, out);
	//printf("%d\n", strlen(encrypted_data));
	//fread(&encrypted_data, sizeof(encrypted_data), strlen(encrypted_data), out);
	printf("%c", encrypted_data);
	fclose(out);
	return 0;
}
