/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_next_line_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 21:48:10 by lmartin2          #+#    #+#             */
/*   Updated: 2022/08/22 12:58:02 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Function to allocate and zero-initialize memory
void	*ft_calloc(size_t count, size_t size)
{
	void	*res;
	size_t	num;

	res = malloc(size * count);
	if (!res)
		return (NULL);
	num = count * size;
	while (num--)
		*((unsigned char *)(res + num)) = 0;
	return (res);
}

// Function to locate the first occurrence of a character in a string
char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		++s;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}

// Function to concatenate two strings
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)ft_calloc(sizeof(char), (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	ft_memcpy((void *)str, (void *)s1, s1_len);
	ft_memcpy((void *)(str + s1_len), (void *)(s2), s2_len);
	return (str);
}

// Function to copy strings with explicit length
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srcsize;

	srcsize = ft_strlen(src);
	if (size == 0)
		return (srcsize);
	if (srcsize + 1 < size)
		ft_memcpy((void *)dst, (void *)src, srcsize + 1);
	else
	{
		ft_memcpy((void *)dst, (void *)src, size - 1);
		dst[size - 1] = '\0';
	}
	return (srcsize);
}

// Function to copy memory area
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (dst == NULL && src == NULL )
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n-- > 0)
		*d++ = *s++;
	return (dst);
}

// Function to determine the length of a string
size_t	ft_strlen(const char *s)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr)
		ptr++;
	return ((size_t)(ptr - s));
}

// Function to free memory
char    *ft_free(char *str)
{
	if (str)
		free(str);
	return (NULL);
}