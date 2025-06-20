/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlucena- <mlucena-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:42:25 by mlucena-          #+#    #+#             */
/*   Updated: 2025/06/20 12:41:28 by mlucena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bts;

	bts = 1;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (*buffer || bts)
	{
		if (!*buffer)
		{
			bts = read(fd, buffer, BUFFER_SIZE);
			if (bts <= 0)
				break ;
			buffer[bts] = 0;
		}
		line = ft_join(line, buffer);
		ft_buffer_organize(buffer);
		if (line && line[ft_strlen(line) - 1] == '\n')
			return (line);
	}
	if (bts < 0)
		return (free(line), NULL);
	return (line);
}

// int main(void)
// {
// 	char	*str;
// 	int		fd = open("test.txt", O_RDONLY);

// 	while((str = get_next_line(fd)))
// 	{
// 		printf("%s", str);
// 		free(str);
// 	}
// 	close(fd);
// 	return 0;
// }