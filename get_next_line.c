/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 14:34:02 by cherrewi      #+#    #+#                 */
/*   Updated: 2022/11/11 11:35:25 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*fd_part = NULL;
	char		*line_str;
	int			final_read_len;

	line_str = NULL;
	if (get_line_break(fd_part) == -1)
	{		
		final_read_len = read_from_file(fd, &fd_part);
		if (final_read_len >= 0
			&& final_read_len < BUFFER_SIZE && get_line_break(fd_part) == -1)
		{
			line_str = create_line_str(&fd_part, gnl_strlen(fd_part));
		}
	}
	if (get_line_break(fd_part) != -1)
	{
		line_str = create_line_str(&fd_part, get_line_break(fd_part) + 1);
		if (gnl_strlen(fd_part) == 1)
		{
			free (fd_part);
			fd_part = NULL;
		}
		else
		{
			fd_part = realloc_fd_part(fd_part, get_line_break(fd_part) + 1, 0);
			if (fd_part == NULL)
			{
				free (line_str);
				line_str = NULL;
			}
		}		
	}
	if (line_str == NULL)
	{
		free(fd_part);
		fd_part = NULL;
	}
	return (line_str);
}
