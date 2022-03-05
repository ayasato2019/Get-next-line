/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysato <aysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 22:53:59 by aysato            #+#    #+#             */
/*   Updated: 2022/03/05 23:44:31 by aysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char **dst, char *src)
{
	free(*dst);
	*dst = src;
}

/*memoの中から改行までをlineに渡す*/
static char	*ft_extraction_line(char **memo)
{
	char	*temp;
	char	*ptr_after;
	char	*ptr_before;
	size_t	len_total;
	size_t	len_after;
	size_t	len_before;

	temp = ft_strchr(*memo, '\n');
	len_total = ft_strlen(*memo);
	len_after = ft_strlen(temp);
	len_before = len_total - len_after;
	ptr_after = ft_substr(*memo, (len_before + 1), len_total);
	if (!ptr_after)
		return (NULL);
	ptr_before = ft_strndup(*memo, (len_before + 1));
	ft_free(memo, NULL);
	ft_free(&ptr_after, NULL);
	ft_free(&ptr_before, ptr_before);
	return (ptr_before);
}

/*
judge_n 0 改行あり ft_extraction_line 1
judge_n 1 改行なし line = tmp2; 0
エラー　-1
*/
static int	ft_judge_n(char *memo)
{
	char	*n_ptr;

	n_ptr = ft_strchr(memo, '\n');
	if (n_ptr != NULL)
		return (1);
	else
		return (0);
}

static char	*ft_read(int fd, char *memo, char *buff)
{
	ssize_t		read_text_byte;

	read_text_byte = 1;
	while (read_text_byte > 0)
	{
		read_text_byte = read(fd, buff, BUFFER_SIZE);
		if (read_text_byte == -1)
		{
			ft_free(&buff, NULL);
			return (memo);
		}
		buff[read_text_byte] = '\0';
		memo = ft_strjoin(memo, buff);
	}
	ft_free(&buff, NULL);
	return (memo);
}

char	*get_next_line(int fd)
{
	static char	*memo;
	char		*line;
	char		*buff;
	int			judge_n;

	if (0 > fd || 0 > BUFFER_SIZE || BUFFER_SIZE > INT_MAX)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	memo = ft_read(fd, memo, buff);
	judge_n = ft_judge_n(memo);
	if (judge_n == 1)
		line = ft_extraction_line(&memo);
	else
		line = memo;
	return (line);
}

#include <stdio.h>
#include <fcntl.h>
int main()
{
	int     fd = 0;
	char	*result;

	fd = open("test.txt", O_RDONLY);
	result = get_next_line(fd);
	if (!result)
		return (-1);
	free (result);
	close(fd);
}