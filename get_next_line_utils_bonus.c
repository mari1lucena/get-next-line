/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlucena- <mlucena-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 04:36:57 by mlucena-          #+#    #+#             */
/*   Updated: 2025/06/05 05:49:31 by mlucena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int x;

	if (!str)
		return (0);
	x = 0;
	while (str[x] && str[x] != '\n')
		x++;
	if (str[x] == '\n')
		x++;
	return (x);
}

char *ft_join(char *line, char *buffer)
{
	int		x;
	int		j;
	char	*new;

	x = 0;
	j = 0;
	new = malloc((ft_strlen(line) + ft_strlen(buffer) + 1) * (sizeof(char)));
	if (!new)
		return (free(line), NULL); //new??
	while(line && line[x] != '\0')
	{
		new[x] = line[x];
		x++;
	}
	while(buffer[j] && buffer[j] != '\n')
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

// int main(void)
// {
//     int fd = open("test.txt", O_RDONLY);
//     char *line;
// 	int		i = 0;

//     while (i < 35)
//     {
// 		line = get_next_line(fd);
//     	printf("s:%s", line);
// 		fd = -1;
// 		if (line != NULL)
// 		{
//     		free(line);
// 		}
// 		i++;
//     }
//     close(fd);
//     return 0;
// }