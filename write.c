#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	int dev = open("/dev/mydevice", O_RDWR);
	if (dev == -1)
	{
		printf("Opening was not possible!\n");
		return -1;
	}
	printf("Opening was success!\n");

	char *write_buffer = "Hello, kernel\n";
	char read_buffer[50];

	int bytesWritten = write(dev, write_buffer, sizeof(write_buffer));
	printf("%d bytes written successfully!\n", bytesWritten);	

	int bytesRead = read(dev, read_buffer, strlen(read_buffer));
	printf("%d bytes read successfully!\n", bytesRead);

	close(dev);
	return 0;
}
