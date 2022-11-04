/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 14:34:02 by cherrewi      #+#    #+#                 */
/*   Updated: 2022/11/04 12:42:09 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*fd_part = NULL;
	char		*line_str;
	int			i_linebreak;

	i_linebreak = 0;
	line_str = NULL;
	if (fd_part != NULL)
		i_linebreak = get_line_break(fd_part);
	if (i_linebreak >= 0)
	{
		line_str = create_line_str(fd_part, i_linebreak);
		fd_part = realloc_fd_part(fd_part, i_linebreak);
	}
	else
	{
		// aditional reads to find next line
	}
}
