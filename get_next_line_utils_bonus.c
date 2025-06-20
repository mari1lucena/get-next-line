/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlucena- <mlucena-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 04:36:57 by mlucena-          #+#    #+#             */
/*   Updated: 2025/06/20 12:06:09 by mlucena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	x;

	if (!str)
		return (0);
	x = 0;
	while (str[x] && str[x] != '\n')
		x++;
	if (str[x] == '\n')
		x++;
	return (x);
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
