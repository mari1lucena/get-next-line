/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlucena- <mlucena-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:42:49 by mlucena-          #+#    #+#             */
/*   Updated: 2025/05/15 20:00:22 by mlucena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <stdint.h>
# include <fcntl.h>
int		ft_check(char *buffer);
char	*ft_join(char *line, char *buffer);
int		ft_strlen(char  *str);
char	*get_next_line(int fd);
void	ft_buffer_organize(char *buffer);
char	*ft_join_all(char *line, char *buffer);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

#endif