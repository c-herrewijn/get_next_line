/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 14:34:08 by cherrewi      #+#    #+#                 */
/*   Updated: 2022/11/02 10:52:06 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
sets the position of the end of the line char in a buffer
0 implies the buffer contains no line end yet
*/
void	set_line_len(t_buff *buff)
{
	size_t	i;

	if (buff->line_start <= buff->total_size)
	{
		i = buff->line_start;
		while (buff->start[i] != '\n' && i < buff->filled_len)
			i++;
		if (buff->start[i] == '\n')
			buff->line_len = i + 1 - buff->line_start;
		if (buff->eof_flag == 1 && buff->line_start == buff->filled_len - 1)
			buff->line_len = i - buff->line_start;
	}
	else
		buff->line_len = 0;
}

char	*create_line(t_buff *buff)
{
	size_t	i;
	char	*str;

	str = malloc((buff->line_len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < buff->line_len)
	{
		str[i] = buff->start[i + buff->line_start];
		i++;
	}
	str[i] = '\0';
	buff->line_start += buff->line_len;
	buff->line_len = 0;
	return (str);
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
