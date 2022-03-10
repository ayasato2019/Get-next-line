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
    char *line = NULL;

	int fd = open("test1.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line == NULL)
			break;
		free(line);
	}
	close(fd);
    return (0);
}

// void end(void)__attribute__((destructor));

// void end(void)
// {
//     system("leaks a.out");
// }