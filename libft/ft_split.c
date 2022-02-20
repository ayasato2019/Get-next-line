/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysato <aysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:47:39 by aysato            #+#    #+#             */
/*   Updated: 2022/01/30 11:24:50 by aysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_block(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			while (*s != '\0' && *s != c)
				s++;
			count++;
		}
	}
	return (count);
}

static char	**ft_free(char **container)
{
	size_t	i;

	i = 0;
	while (container[i])
		free(container[i++]);
	free(container);
	return (NULL);
}

static char	**split_block(char const *s,
		char c, const char *temp, char **container)
{
	size_t	len;
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s == c && c != 0)
			s++;
		temp = s;
		len = 0;
		while (*s != c && *s != '\0')
		{
			s++;
			len++;
		}
		if (*(s - 1) != c)
		{
			container[i] = ft_substr(temp, 0, len);
			if (container[i] == NULL)
				return (ft_free(container));
			i++;
		}
	}
	container[i] = NULL;
	return (container);
}

char	**ft_split(char const *s, char c)
{
	const char	*temp;
	char		**container;

	if (s == NULL)
		return (NULL);
	container = (char **)malloc((sizeof(char *) * (ft_count_block(s, c)) + 1));
	if (container == NULL)
		return (NULL);
	return (split_block(s, c, temp, container));
}
