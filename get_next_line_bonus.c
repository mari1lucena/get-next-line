/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlucena- <mlucena-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 03:31:32 by mlucena-          #+#    #+#             */
/*   Updated: 2025/06/05 04:48:56 by mlucena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			len;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	while (*buffer[fd] || read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		line = ft_join(line, buffer[fd]);
		if (!line)
			return (NULL);
		len = ft_strlen(line);
		ft_buffer_organize(buffer[fd]);
		if (line[len - 1] == '\n')
			return (line);
	}
	return (line);
}

void	ft_buffer_organize(char *buffer)
{
	int	x;
	int	j;

	x = 0;
	j = 0;
	while(buffer[x] != '\0' && buffer[x] != '\n')
		x++;
	if(buffer[x] == '\n')
		x++;
	while(buffer[j])
		buffer[j++] = buffer[x++];
	buffer[j] = '\0';
}