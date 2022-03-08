/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysato <aysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 22:53:59 by aysato            #+#    #+#             */
/*   Updated: 2022/03/08 23:28:00 by aysato           ###   ########.fr       */
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
		return (*line);
	}
	else if (!len_total)
	{
		ft_free(memo, NULL);
		return (NULL);
	}
	len_after = ft_strlen(temp);
	len_before = len_total - len_after;
	ptr_after = ft_substr(*memo, (len_before + 1), len_total);
	if (!ptr_after)
		return (NULL);
	ptr_before = ft_strndup(*memo, (len_before + 1));
	ft_free(memo, NULL);
	*line = ptr_before;
	*memo = ptr_after;
	return (*line);
}

static char	*ft_read(int fd, char *memo, char *buff)
{
	char		*temp;
	ssize_t		read_text_byte;

	read_text_byte = 1;
	printf("read_before:%s\n", memo);
	while (read_text_byte > 0 && memo == NULL)
	{
		printf("read_before:%s\n", memo);
		read_text_byte = read(fd, buff, BUFFER_SIZE);
		if (read_text_byte == -1)
		{
			ft_free(&buff, NULL);
			return (memo);
		}
		buff[read_text_byte] = '\0';
		temp = memo;
		memo = ft_strjoin(memo, buff);
		if (memo == NULL)
			return (NULL);
		ft_free(&temp, NULL);
		if (read_text_byte == 0 && memo == NULL)
			return (NULL);
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
	memo = ft_read(fd, memo, buff);
	if (!memo)
		return (NULL);
	line = ft_extraction_line(&memo, &line);
	return (line);
}
