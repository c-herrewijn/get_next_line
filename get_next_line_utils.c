/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 14:34:08 by cherrewi      #+#    #+#                 */
/*   Updated: 2022/11/09 17:17:12 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_line_break(char *fd_part)
{
	int	i;

	if (fd_part == NULL)
		return (-1);
	i = 0;
	while (fd_part[i] != '\0')
	{
		if (fd_part[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*create_line_str(char *fd_part, int len)
{
	char	*line_str;
	int		i;

	i = 0;
	line_str = malloc((len + 1) * sizeof(char));
	if (line_str == NULL)
		return (NULL);
	while (i < len)
	{
		line_str[i] = fd_part[i];
		i++;
	}
	line_str[i] = '\0';
	return (line_str);
}

// realloc fd_part: remove bytes from front and/or add bytes to back
// fill bytes added to back with '\0'
char	*realloc_fd_part(char *fd_part, int front, int back)
{
	int		count;
	int		i;
	char	*new_fd_part;

	count = gnl_strlen(fd_part);
	new_fd_part = malloc((count + 1 - front + back) * sizeof(char));
	if (new_fd_part == NULL)
	{
		free(fd_part);
		return (NULL);
	}
	i = 0;
	while (i < count - front)
	{
		new_fd_part[i] = fd_part[i + front];
		i++;
	}
	while (i < count + 1 - front + back)
	{
		new_fd_part[i] = '\0';
		i++;
	}
	free(fd_part);
	return (new_fd_part);
}

int	read_from_file(int fd, char **fd_part)
{
	int	i_linebreak;
	int	str_len;
	int	read_len;

	read_len = 0;
	i_linebreak = get_line_break(*fd_part);
	while (i_linebreak == -1)
	{
		str_len = gnl_strlen(*fd_part);
		*fd_part = realloc_fd_part(*fd_part, 0, BUFFER_SIZE);
		if (*fd_part == NULL)
			return (-1);
		read_len = read(fd, *fd_part + str_len, BUFFER_SIZE);
		if ((read_len <= 0 && gnl_strlen(*fd_part) == 0) || read_len < 0)
		{
			free(*fd_part);
			*fd_part = NULL;
			return (-1);
		}
		if (read_len < BUFFER_SIZE)
			break ;
		i_linebreak = get_line_break(*fd_part);
	}
	return (read_len);
}

int	gnl_strlen(char *s)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
