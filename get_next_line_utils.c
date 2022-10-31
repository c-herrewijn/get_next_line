/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 14:34:08 by cherrewi      #+#    #+#                 */
/*   Updated: 2022/10/31 19:57:37 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
returns the position of the end of the line char in a buffer
0 implies the buffer contains no line end
*/
void	set_line_len(t_buff *buff)
{
	size_t	i;

	i = 0;
	while (
		buff->start[i] != '\n'
		&& buff->start[i] != '\0'
		&& buff->start[i] != EOF
		&& i < buff->filled_len
	)
		i++;
	if (buff->start[i] == EOF)
		buff->eof_flag = 1;
	if (i != buff->filled_len)
		buff->line_length = i;
}

/*
increases the malloc space for a string
copies the old malloc content to the new malloc volume
free the old malloc volume.
*/
void	re_alloc_buff(t_buff *buff)
{
	size_t	i;
	char	*str_new;

	str_new = malloc(buff->total_size + BUFFER_SIZE);
	if (str_new != NULL)
	{		
		i = 0;
		while (i < buff->total_size)
		{
			str_new[i] = buff->start[i];
			i++;
		}
		if (buff->start != NULL)
			free(buff->start);
		buff->start = str_new;
		buff->total_size += BUFFER_SIZE;
	}
	else
	{
		if (buff->start != NULL)
			free(buff->start);
		buff->start = NULL;
	}
}

char	*create_line(t_buff *buff)
{
	size_t	i;
	char	*str;

	str = malloc((buff->line_length + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < buff->line_length)
	{
		str[i] = buff->start[i];
		i++;
	}
	str[i] = '\0';
	buff->start += buff->line_length;
	buff->total_size -= buff->line_length;
	buff->filled_len -= buff->line_length;
	buff->line_length = 0;
	return (str);
}
