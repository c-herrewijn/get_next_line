/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 14:34:02 by cherrewi      #+#    #+#                 */
/*   Updated: 2022/11/10 14:05:19 by cherrewi      ########   odam.nl         */
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
			line_str = create_line_str(fd_part, gnl_strlen(fd_part));
			free(fd_part);
			fd_part = NULL;
		}
	}
	if (get_line_break(fd_part) != -1)
	{
		line_str = create_line_str(fd_part, get_line_break(fd_part) + 1);
		fd_part = realloc_fd_part(fd_part, get_line_break(fd_part) + 1, 0);
	}
	return (line_str);
}
