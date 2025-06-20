/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlucena- <mlucena-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 03:31:32 by mlucena-          #+#    #+#             */
/*   Updated: 2025/06/20 12:05:22 by mlucena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			bts;

	bts = 1;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FOPEN_MAX)
		return (NULL);
	while (*buffer[fd] || bts)
	{
		if (!*buffer[fd])
		{
			bts = read(fd, buffer[fd], BUFFER_SIZE);
			if (bts <= 0)
				break ;
			buffer[fd][bts] = 0;
		}
		line = ft_join(line, buffer[fd]);
		ft_buffer_organize(buffer[fd]);
		if (line && line[ft_strlen(line) - 1] == '\n')
			return (line);
	}
	if (bts < 0)
		return (free(line), buffer[fd][0] = '\0', NULL);
	return (line);
}
