
#include "get_next_line.h"

#include <stdio.h>

int main()
{
	int fd = open("test.txt", O_APPEND);
	if (fd == -1)
	{
		printf("ERROR\n");
		return 0;
	}
	printf("1: %s\n", get_next_line(fd));
	printf("2: %s\n", get_next_line(fd));
	printf("3: %s\n", get_next_line(fd));

/*
	char *c = (char *) calloc(100, sizeof(char));

	int fd = open("test.txt", O_RDWR);
	int check;
	if (fd == -1)
	{
		printf("ERROR\n");
		return 0;
	}
	printf("fd: %d\n", fd);
	check = write(fd, "ABC", 3);
	printf("write: %d\n", check);
	read(fd, c, 100);
	printf("file content: % s", c);
	fd = close(fd);
	if (fd == 0)
	{
		printf("FILE CLOSED\n");
		return 0;
	}
	else
		printf ("CLOSING ERROR\n");
*/
}
