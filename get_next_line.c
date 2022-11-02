/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 14:34:02 by cherrewi      #+#    #+#                 */
/*   Updated: 2022/11/02 10:44:35 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_buff	buff = {NULL, 0, 0, 0, 0, 0};
	int				read_chars;

	while (buff.line_len == 0)
	{
		if (buff.eof_flag == 0)
		{
			if (buff.total_size < buff.filled_len + BUFFER_SIZE)
				re_alloc_buff(&buff);
			read_chars = read(fd, buff.start + buff.filled_len, BUFFER_SIZE);
			if (read_chars < BUFFER_SIZE)
			{
				buff.eof_flag = 1;
				buff.total_size = buff.total_size + read_chars - BUFFER_SIZE;
			}
			if (read_chars > 0)
				buff.filled_len += read_chars;
		}
		set_line_len(&buff);
		if (buff.line_start >= buff.total_size)
			break ;
	}
	if (buff.line_len > 0)
		return (create_line(&buff));
	else
		return (NULL);
}
