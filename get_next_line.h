/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 14:33:55 by cherrewi      #+#    #+#                 */
/*   Updated: 2022/11/02 10:23:06 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE     
#  define BUFFER_SIZE 10
# endif

/*
start		= start of malloc volume
total_size	= total malloc volume
filled_len	= number of chars stored in malloc volume
line_start	= index of start of the line
line_len	= length of the line to return, only set when the full line is read
eof_flag	= put to 1 if EOF has been read
*/
typedef struct s_buff
{
	char	*start;
	size_t	total_size;
	size_t	filled_len;
	size_t	line_start;
	size_t	line_len;
	size_t	eof_flag;
}	t_buff;

char	*get_next_line(int fd);
void	set_line_len(t_buff *buff);
void	re_alloc_buff(t_buff *buff);
char	*create_line(t_buff *buff);

#endif
