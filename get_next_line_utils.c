/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:57:15 by rpinchas          #+#    #+#             */
/*   Updated: 2022/12/02 10:48:35 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char			*p;
	size_t			len;
	size_t			i;

	len = nmemb * size;
	p = (char *)malloc(len);
	if (p == NULL || len > 2147483647)
		return (0);
	i = 0;
	while (i < len)
	{
		p[i] = 0;
		i++;
	}
	return ((void *)p);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)s;
	while (s[i] != (char)c && s[i] != '\0')
	{
		i++;
		ptr++;
	}
	if (s[i] == (char)c)
		return (ptr);
	else
		return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		slen;
	int		i;
	int		end;

	if (!s1 || !s2)
		return (NULL);
	slen = ft_strlen(s1) + ft_strlen(s2) + 1;
	s3 = (char *)ft_calloc(sizeof(char), slen);
	if (s3 == NULL)
		return (NULL);
	ft_strlcpy(s3, s1, slen);
	i = 0;
	end = slen - ft_strlen(s2) - 1;
	while (s2[i])
	{
		s3[end + i] = s2[i];
		i++;
	}
	free(s1);
	free(s2);
	return (s3);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	long unsigned int	i;
	long unsigned int	cnt;

	i = 0;
	cnt = 0;
	if (size > 0)
	{
		while (src[cnt])
		{
			while ((i < size - 1) && src[i])
			{
				dst[i] = src[i];
				i++;
			}
			cnt++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
