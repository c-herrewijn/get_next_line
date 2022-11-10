/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 14:33:55 by cherrewi      #+#    #+#                 */
/*   Updated: 2022/11/10 14:02:43 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
int		read_from_file(int fd, char **fd_part);
int		get_line_break(char *fd_part);
char	*create_line_str(char *fd_part, int len);
char	*realloc_fd_part(char *fd_part, int front, int back);
int		gnl_strlen(char *s);

#endif
