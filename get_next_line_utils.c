/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlucena- <mlucena-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:43:01 by mlucena-          #+#    #+#             */
/*   Updated: 2025/06/20 15:42:33 by mlucena-         ###   ########.fr       */
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
int	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len] && str[len] != '\n')
		len++;
	if (str && str[len] == '\n')
		len++;
	return (len);
}

char	*ft_join(char *line, char *buffer)
{
	int		x;
	int		j;
	char	*new;

	x = 0;
	j = 0;
	new = malloc((ft_strlen(line) + ft_strlen(buffer) + 1) * (sizeof(char)));
	if (!new)
		return (free(line), NULL);
	while (line && line[x] != '\0')
	{
		new[x] = line[x];
		x++;
	}
	while (buffer[j] && buffer[j] != '\n')
	{
		new[x + j] = buffer[j];
		j++;
	}
	if (buffer[j] == '\n')
		new[x + j++] = '\n';
	new[x + j] = '\0';
	free(line);
	return (new);
}

void	ft_buffer_organize(char *buffer)
{
	int	x;
	int	j;

	x = 0;
	j = 0;
	while (buffer[x] != '\0' && buffer[x] != '\n')
		x++;
	if (buffer[x] == '\n')
		x++;
	while (buffer[j])
		buffer[j++] = buffer[x++];
	buffer[j] = '\0';
}
