/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:04:55 by smedenec          #+#    #+#             */
/*   Updated: 2025/06/21 15:36:07 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t	bytes;
	size_t	lenbuff;
	static char	*buff;
	static	int file;
	static	int fileopen;

	lenbuff = 20;
	buff = malloc(sizeof(char) * (lenbuff + 1));
	if (!buff)
		return (NULL);

	return (buff);
}
int	main(void)
{
	int		file;
	char	*line;

	file = open("file.txt", O_RDONLY);
	if (file == -1)
		return (1);
	line = get_next_line(file);
	printf("call gnl = %s\n", (char *)line);
	return (0);
}
