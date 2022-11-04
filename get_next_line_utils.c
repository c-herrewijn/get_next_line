/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 14:34:08 by cherrewi      #+#    #+#                 */
/*   Updated: 2022/11/04 12:43:39 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_line_break(char *fd_part)
{
	int	i;

	i = 0;
	while (fd_part[i] != '\0')
	{
		if (fd_part[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*create_line_str(char *fd_part, int i_linebreak)
{
	char	*line_str;
	int		i;

	i = 0;
	line_str = malloc((i_linebreak + 1) * sizeof(char));
	if (line_str == NULL)
		return (NULL);
	while (i <= i_linebreak)
	{
		line_str[i] = fd_part[i];
		i++;
	}
	line_str[i] = '\0';
	return (line_str);
}

char	*realloc_fd_part(char *fd_part, int i_linebreak)
{
	int		count;
	int		i;
	char	*new_fd_part;

	count = 0;
	while (fd_part[count] != '\0')
		count++;
	new_fd_part = malloc(count + 1 - i_linebreak);
	if (new_fd_part == NULL)
		return (NULL);
	i = 0;
	while (i < count - i_linebreak)
	{
		new_fd_part[i] = fd_part[i_linebreak + i + 1];
		i++;
	}
	new_fd_part[i] = '\0';
	free(fd_part);
	return (new_fd_part);
}
