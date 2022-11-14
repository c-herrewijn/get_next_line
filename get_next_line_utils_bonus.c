/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 14:34:08 by cherrewi      #+#    #+#                 */
/*   Updated: 2022/11/14 15:12:08 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
Locates the first occurrence of c (converted to a char) in string s.
returns NULL if the character does not appear in the string
*/
char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	if ((char)c == 0)
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	else
	{
		while (*s)
		{
			if (*s == (char)c)
				return ((char *)s);
			s++;
		}
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	c;

	if (s == NULL)
		return (0);
	c = 0;
	while (*s)
	{
		s++;
		c++;
	}
	return (c);
}

/*
Copies src to dst; always null terminates
Returns the length of src (excl. null terminator)
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	i = 0;
	while (i < src_len && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

/*
copies a substring to new memory
starting at position 'start' not more than 'len' chars
copies not more chars than present in the string
one extra byte is allocated for the new string, so it is null terminated
note: 'start' is a zero-based index!
if malloc fails, NULL is returned
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new_str;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		new_str = malloc(1 * sizeof(char));
	else if (ft_strlen(s) - start > len)
		new_str = malloc(len + 1 * sizeof(char));
	else
		new_str = malloc((ft_strlen(s) - start + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s) - start && i < len && start < ft_strlen(s))
	{
		new_str[i] = s[i + start];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
