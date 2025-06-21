/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:04:55 by smedenec          #+#    #+#             */
/*   Updated: 2025/06/21 19:21:31 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t		lenbuff;
	char		*buff;
	char		*ligne;
	static char	*past;//static pour garder les anciens characters

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	lenbuff = read(fd, buff, BUFFER_SIZE);// taille du buffer
	if (lenbuff == -1)//read echoue
	{
		free(buff);
		free(past);
		past = NULL;
		return(NULL);
	}
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
	close(file);
	return (0);
}
