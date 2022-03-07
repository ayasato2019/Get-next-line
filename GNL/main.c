#include "get_next_line.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <sys/errno.h>
#include <string.h>
#include <libgen.h>
#include <stdio.h>
#include <stdbool.h>


int main()
{
    // (void)av = "test.txt";
    char *line = NULL;
    // int i = 0;
    // bool flag = true;

	int fd = open("test.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		if (line == NULL)
			break;
		free(line);
	}
	close(fd);
    // if (ac == 2)
    // {
    //     int fd = open(av[1], O_RDONLY);
    //     while (i < 20)
    //     {
    //         line = get_next_line(fd);
    //         printf("%4d : %s\n", i++, line);
    //         if (line == NULL)
    //             flag =false;
    //         free(line);
    //     }
    //     close(fd);
    // }
    return (0);
}

void end(void)__attribute__((destructor));

void end(void)
{
    system("leaks a.out");
}