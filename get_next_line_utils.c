/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlucena- <mlucena-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:43:01 by mlucena-          #+#    #+#             */
/*   Updated: 2025/05/15 20:45:34 by mlucena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char  *str)
{
	int x;

	if (!str)
		return (0);
	x = 0;
	while(*str && *str != '\n')
	{
		x++;
		str++;
	}
	if (*str == '\n')
	{
		x++;
		str++;
	}
	return(x);
}
char *ft_join(char *line, char *buffer)
{
	int	x;
	int	j;
	char *new;

	x = 0;
	j = 0;
	new = malloc((ft_strlen(line) + ft_strlen(buffer) + 1) * (sizeof(char)));
	if (!new)
		return (free(new), NULL);
	while(line && line[x])
	{
		 new[x] = line[x];
		 x++;
	}
	while(buffer[j] && buffer[j] != '\n')
		new[x++] = buffer[j++];
	if (buffer[j] == '\n')
		new[x++] = '\n';
	new[x] = '\0'; //x++?
	free(line);
	return (new);
}

void	ft_buffer_organize(char *buffer)
{
	int	x;
	int	j;

	x = 0;
	j = 0;
	while(buffer[x] && buffer[x] != '\n')
		x++;
	if(buffer[x] == '\n')
		x++;
	while(buffer[x])
		buffer[j++] = buffer[x++];
	buffer[j] = '\0';
}
