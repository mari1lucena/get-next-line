/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlucena- <mlucena-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:43:01 by mlucena-          #+#    #+#             */
/*   Updated: 2025/05/13 20:32:56 by mlucena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char  *str)
{
	int x;

	if (!str)
		return (0);
	x = 0;
	while(*str)
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
	new = malloc((ft_strlen(line) + ft_strlen(buffer) + 1) * (sizeof(char *)));
	while(line && line[x])
	{
		 new[x] = line[x];
		 x++;
	}
	while(buffer[j] && buffer[j] != '\n')
	{
		new[x] = buffer[j];
		j++;
		x++;
	}
	if (buffer[j] == '\n')
	{
		new[x] = '\n';
		x++;
	}
	new[x] = '\0';
	return (new);
}

int	ft_check(char *buffer)
{
	while(*buffer)
	{
		if (*buffer == '\n')
			return (1);
		buffer++;
	}
	return (0);
}

void cleaning(char *buffer)
{
	int	x;

	x = 0;
	while(buffer[x] && buffer[x] != '\n')
		x++;
	while(buffer[x])
	{
		
	}
}