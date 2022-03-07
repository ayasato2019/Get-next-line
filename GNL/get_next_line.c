/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysato <aysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 22:53:59 by aysato            #+#    #+#             */
/*   Updated: 2022/03/07 18:21:38 by aysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_free(char **dst, char *src)
{
	free(*dst);
	*dst = src;
}

/*memoの中から改行までをlineに渡す*/
static char	*ft_extraction_line(char **memo, char **line)
{
	char	*temp;
	char	*ptr_after;
	char	*ptr_before;
	size_t	len_total;
	size_t	len_after;
	size_t	len_before;

	*line = NULL;
	temp = ft_strchr(*memo, '\n');
	len_total = ft_strlen(*memo);
	if (temp == NULL && len_total)
	{
		*line = *memo;
		*memo = NULL;
		printf("memo-extraction:%s\n", *memo);
		return (*line);
	}
	else if(!len_total)
	{
		ft_free(memo, NULL);
		return (NULL);
	}
	len_after = ft_strlen(temp);
	printf("total:%zu\n", len_total);
	len_before = len_total - len_after;
	ptr_after = ft_substr(*memo, (len_before + 1), len_total);
	if (!ptr_after)
		return (NULL);
	ptr_before = ft_strndup(*memo, (len_before + 1));
	ft_free(memo, NULL);
	*line = ptr_before;
	*memo = ptr_after;
	printf("memo-EXT:%p\n", *memo);
	return (*line);
}

static char	*ft_read(int fd, char *memo, char *buff)
{
	// char		*temp;
	ssize_t		read_text_byte;

	read_text_byte = 1;//memoにNULLを返すパターンを考える
	// printf("memo0:%s\n", memo);
	while (read_text_byte > 0)// && !ft_strchr(memo, '\n')大きなファイルの時に扱えない可能性　メモに入りきらないかも
	{
		// printf("memo-read:%s\n", memo);
		read_text_byte = read(fd, buff, BUFFER_SIZE);
		if (read_text_byte == -1)
		{
			ft_free(&buff, NULL);
			return (memo);
		}
		// printf("buffp:%p\n", buff);
		buff[read_text_byte] = '\0';
		printf("memo:%p\n", memo);
		memo = ft_strjoin(memo, buff);
		// ft_free(&buff, NULL);
		printf("memo-join-after:%p\n", memo);
		printf("memo-join-after:%s\n", memo);
		if (read_text_byte == 0 && memo == NULL)
			return (NULL);
		// if (memo[0] != '\0')// || memo[0] == '\n'
		// {
		// 	printf("buff1-1:%s\n", buff);
			
		// 	return (NULL);
		// }
		// printf("memo2:%s\n", memo);
	}
	ft_free(&buff, NULL);
	return (memo);
}

char	*get_next_line(int fd)
{
	static char	*memo = NULL;
	char		*line;
	char		*buff;

	line = NULL;
	if (0 > fd || 0 > BUFFER_SIZE || BUFFER_SIZE > SSIZE_MAX)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	// if (memo == NULL)
	// 	ft_strdup("");
	// printf("memop:%p\n", memo);
	memo = ft_read(fd, memo, buff);
	if(!memo)
		return (NULL);
	line = ft_extraction_line(&memo, &line);
	printf("memo-GNL:%s\n", memo);
	return (line);
}

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
    int i = 0;
    // bool flag = true;

	int fd = open("test.txt", O_RDONLY);
	while (i < 20)
	{
		line = get_next_line(fd);
		printf("%4d : %s\n", i++, line);
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