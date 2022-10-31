/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 14:34:02 by cherrewi      #+#    #+#                 */
/*   Updated: 2022/10/31 19:55:35 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/*
scenarios: 
- end line not yet found
- one end line in buffer
- multiple lines in buffer
*/
char	*get_next_line(int fd)
{
	static t_buff	buff = {NULL, 0, 0, 0, 0};

	while (buff.eof_flag == 0 && buff.line_length == 0)
	{
		if (buff.total_size < buff.filled_len + BUFFER_SIZE)
			re_alloc_buff(&buff);
		read(fd, buff.start + buff.filled_len, BUFFER_SIZE);
		buff.filled_len += BUFFER_SIZE;
		set_line_len(&buff);
		if (buff.line_length > 0)
			break ;
	}
	if (buff.line_length > 0)
	{
		return (create_line(&buff));
	}
	else
		return (NULL);
}
