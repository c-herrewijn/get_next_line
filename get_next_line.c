/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 14:34:02 by cherrewi      #+#    #+#                 */
/*   Updated: 2022/11/13 14:26:16 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

/*
adds data from file to file_part->content unit eof or '\n' has been found
*/
static int	read_file(int fd, t_file_part *file_part)
{
	int		read_len;
	char	*read_str;
	size_t	malloc_size;

	read_len = BUFFER_SIZE;
	malloc_size = 1 + ft_strlen(file_part->content);
	while (ft_strchr(file_part->content, '\n') == NULL && read_len == BUFFER_SIZE)
	{
		malloc_size += BUFFER_SIZE;
		read_str = ft_calloc(malloc_size, sizeof(char));
		if (read_str == NULL)
			return (-1);
		if (file_part->content != NULL)
			ft_strlcpy(read_str, file_part->content, malloc_size);
		read_len = read(fd, read_str + ft_strlen(file_part->content), BUFFER_SIZE);
		if (read_len <= 0)
		{
			free (read_str);
			return (read_len);
		}
		free (file_part->content);
		file_part->content = read_str;
	}
	return (read_len);
}

/*
returns the next line
removes the returned line from file_part->content
function is only called when file_part->content != NULL
*/
static char	*create_next_line(t_file_part *file_part)
{
	char	*next_line;
	char	*new_filepart;
	size_t	len_next_line;

	new_filepart = NULL;
	if (ft_strchr(file_part->content, '\n') != NULL)
		len_next_line = ft_strchr(file_part->content, '\n') - file_part->content + 1;
	else
		len_next_line = ft_strlen(file_part->content);
	next_line = ft_substr(file_part->content, 0, len_next_line);
	if (next_line == NULL)
		return (NULL);
	if (len_next_line < ft_strlen(file_part->content))
		new_filepart = ft_substr(file_part->content, len_next_line, ft_strlen(file_part->content));
	free(file_part->content);
	file_part->content = new_filepart;
	return (next_line);
}

char	*get_next_line(int fd)
{
	static t_file_part	file_part = {NULL, 0};
	int					read_len;
	char				*next_line;

	read_len = 0;
	next_line = NULL;
	read_len = read_file(fd, &file_part);
	if (read_len < 0)
	{
		free (file_part.content);
		file_part.content = NULL;
	}
	if (file_part.content != NULL)
	{
		next_line = create_next_line(&file_part);
		if (next_line == NULL)
		{
			free (file_part.content);
			file_part.content = NULL;
		}
	}
	return (next_line);
}
