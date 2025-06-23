/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:04:55 by smedenec          #+#    #+#             */
/*   Updated: 2025/06/23 15:40:59 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t		lenbuff;
	char		*buff;
	char		*ligne;
	static char	*past = NULL;//le reste a rajouter apres

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	lenbuff = -1;
	ligne = NULL;
	while ((!strchr(past, '\n')) && (lenbuff > 0))//si pas fin de ligne
	{
		lenbuff = read(fd, buff, BUFFER_SIZE);// lenbuff = taille du buffer
		if (lenbuff == -1)//read echoue
		{
			printf("Read fail\n");
			free(buff);
			free(past);
			past = NULL;
			return (NULL);
		}
		if (lenbuff != 0)
			past = ft_strjoin(past, buff);//reste est ajoutee
	}
	ligne = take_line(past);//extraire la ligne jusq \n
	past = save_rest(past);//Ajouter le reste a past
	if (!past)
	{
		free(past);
		past = NULL;
	}
	return (ligne);
}

char	*take_line(char *s)
{

}

// char	*save_rest(char *s)
// {

// }

int	main(void)
{
	int		file;
	char	*line;

	file = open("file.txt", O_RDONLY);
	if (file == -1)
		return (1);
	line = get_next_line(file);
	printf("Call a ligne = %s\n", (char *)line);
	close(file);
	return (0);
}
