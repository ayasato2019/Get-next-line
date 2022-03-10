/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysato <aysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 22:53:59 by aysato            #+#    #+#             */
/*   Updated: 2022/03/09 23:37:51 by aysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char **dst, char *src)
{
	free(*dst);
	*dst = src;
}

/*memoの中から改行までをlineに渡す*/
static char	*ft_extraction_line(char **memo,
								size_t len_before, size_t len_total)
{
	char	*temp;
	char	*memo_single;
	char	*ptr_after;
	char	*ptr_before;
	size_t	i;

	ptr_after = ft_substr(*memo, (len_before + 1), len_total);
	if (!ptr_after)
		return (NULL);
	i = 0;
	memo_single = *memo;
	if ((len_before + 1) < len_total)
		len_total = (len_before + 1);
	temp = (char *)malloc(sizeof(char) * (len_total + 1));
	if (!temp)
		return (NULL);
	len_before = 0;
	while (i < len_total)
		temp[i++] = memo_single[len_before++];
	temp[i] = '\0';
	ptr_before = temp;
	ft_free(memo, NULL);
	*memo = ptr_after;
	return (ptr_before);
}

static char	*ft_judge_line(char **memo, char **line, size_t len_total)
{
	char	*temp;
	size_t	len_after;
	size_t	len_before;

	*line = NULL;
	temp = ft_strchr(*memo, '\n');
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
	len_after = 0;
	while (temp[len_after] != '\0')
		len_after++;
	len_before = len_total - len_after;
	return (ft_extraction_line(memo, len_before, len_total));
}

static char	*ft_read(int fd, char *memo, char *buff)
{
	char		*temp;
	ssize_t		read_text_byte;

	read_text_byte = 1;
	while (read_text_byte > 0 && BUFFER_SIZE >= 1)
	{
		read_text_byte = read(fd, buff, BUFFER_SIZE);
		if (read_text_byte == -1)
		{
			ft_free(&buff, NULL);
			return (memo);
		}
		buff[read_text_byte] = '\0';
		if (ft_strchr(buff, '\n'))
			read_text_byte = 0;
		temp = memo;
		memo = ft_strjoin(memo, buff);
		if (!memo || (read_text_byte == 0 && memo == NULL))
			return (NULL);
		ft_free(&temp, NULL);
	}
	ft_free(&buff, NULL);
	return (memo);
}

char	*get_next_line(int fd)
{
	static char	*memo = NULL;
	char		*line;
	char		*buff;
	size_t		len_total;

	line = NULL;
	if (0 > fd || 0 > BUFFER_SIZE)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	memo = ft_read(fd, memo, buff);
	if (!memo)
		return (NULL);
	len_total = 0;
	while (memo[len_total] != '\0')
		len_total++;
	line = ft_judge_line(&memo, &line, len_total);
	return (line);
}
