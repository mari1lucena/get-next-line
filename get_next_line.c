/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlucena- <mlucena-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:42:25 by mlucena-          #+#    #+#             */
/*   Updated: 2025/05/13 19:27:21 by mlucena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	char	*line;

	line = NULL;
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = ft_join(line, buffer);
		if (ft_check(buffer) == 1)
		{
			return (line);
		}
	}
	return (line);
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
	char	*str;

	str = get_next_line(fd);
	printf("%s", str);
}
