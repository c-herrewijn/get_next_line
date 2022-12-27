#include <stdio.h>
#include <fcntl.h>
#include "../get_next_line.h"
#include <stdlib.h>

int main(void)
{
	const char *file1;
	// const char *file2;
	// const char *file3;
	int fd1;
	// int fd2;
	// int fd3;
	char *str;

	// puts("start test");
	// printf("buff size: %d\n", BUFFER_SIZE);

	file1 = "./tests/file1.txt";
	// file2 = "./tests/file2.txt";
	// file3 = "./tests/file3.txt";

    fd1 = open(file1, O_RDONLY);
    // fd2 = open(file2, O_RDONLY);
    // fd3 = open(file3, O_RDONLY);
	// printf("file descriptor 1: %d\n", fd1);
	// printf("file descriptor 2: %d\n", fd2);
	// printf("file descriptor 3: %d\n", fd3);
	// puts("-----");
	
	// str = get_next_line(fd1);
	// printf("%s", str);
	// printf("-----\n");

	// str = get_next_line(0);
	// printf("%s", str);
	// printf("-----");
	
	// str = get_next_line(fd2);
	// printf("%s", str);
	// printf("-----\n");

	// str = get_next_line(fd1);
	// printf("%s", str);
	// printf("-----\n");

	// str = get_next_line(0);
	// printf("%s", str);
	// printf("-----");
	
	// str = get_next_line(fd2);
	// printf("%s", str);
	// printf("-----\n");
	
	// if (str == NULL)
	// 	puts("NULL");

	// if (str != NULL && str[0] == '\0')
	// 	puts("'\\0'");

	str = get_next_line(fd1);
	printf("%s", str);
	puts("-----");

	while (str != NULL)
	{
		str = get_next_line(fd1);
		printf("%s", str);
		puts("-----");
	}

	system("leaks test.out");

}	