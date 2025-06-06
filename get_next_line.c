/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlucena- <mlucena-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:42:25 by mlucena-          #+#    #+#             */
/*   Updated: 2025/06/05 05:29:55 by mlucena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			len;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (*buffer || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = ft_join(line, buffer);
		if (!line)
			return (free(line), NULL);
		ft_buffer_organize(buffer);
		len = ft_strlen(line);
		if (line[len - 1] == '\n')
			return (line);
	}
	return (line);
}

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;
	int		i = 0;

    while (i < 35)
    {
		line = get_next_line(fd);
    	printf("s:%s", line);
		if (line != NULL)
		{
    		free(line);
		}
		i++;
    }
    close(fd);
    return 0;
}
