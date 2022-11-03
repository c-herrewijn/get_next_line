/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 14:34:02 by cherrewi      #+#    #+#                 */
/*   Updated: 2022/11/03 16:44:08 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_buff	buff = {NULL, 0, 0, 0, 0, 0};
	char			*str;
	int				r_chars;

	str = NULL;
	buff.line_len = 0;
	while (buff.line_len == 0)
	{
		if (buff.eof_flag == 0)
		{
			if (buff.total_size < buff.filled_len + BUFFER_SIZE)
				re_alloc_buff(&buff);
			r_chars = read_chars(&buff, fd);
			if (r_chars < 0)
			{
				if (buff.start != NULL)
					free(buff.start);
				buff.start = NULL;
				return (NULL);
			}
		}
		set_line_len(&buff);
		if (buff.line_start >= buff.total_size)
			break ;
	}
	if (buff.line_len > 0)
		str = create_line(&buff);
	if (buff.eof_flag == 1 && buff.line_start + buff.line_len == buff.total_size)
	{			
		free(buff.start);
		buff.start = NULL;
	}
	buff.line_start += buff.line_len;
	return (str);
}
