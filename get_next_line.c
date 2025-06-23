/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:04:55 by smedenec          #+#    #+#             */
/*   Updated: 2025/06/23 19:18:54 by smedenec         ###   ########.fr       */
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
	lenbuff = 1;
	while (!ft_strchr(past, '\n') && lenbuff > 0)//si pas fin de ligne
	{
		lenbuff = read(fd, buff, BUFFER_SIZE);// lenbuff = taille du buffer
		buff[lenbuff] = '\0';
		if (read_fail(past, buff, lenbuff))//read echoue
			return (NULL);
		past = ft_strjoin(past, buff);//reste est ajoutee

	}
	free(buff);
	ligne = take_line(past);//extraire la ligne jusq \n
	past = save_rest(past);//Ajouter le reste a past
	return (ligne);
}

char	*take_line(char *past)
{
	int		i;
	char	*ligne;

	i = 0;
	ligne = ft_strdup(past);
	if (!ligne || ligne[i] == '\0')
		return (NULL);
	while (ligne && ligne[i] && (ligne[i] != '\n'))
		i++;
	ligne[i] = '\0';
	return (ligne);
}

char	*save_rest(char *past)
{
	int		i;
	int		j;
	int		len;
	char	*rest;

	i = 0;
	j = 0;
	while (past && past[i] && past[i] != '\n')
		i++;
	if (!past || !past[i] || (past[i] == '\n' && !past[i + 1]))
		return (free_past(past));
	i++;
	len = ft_strlen(past);
	rest = malloc(sizeof(char) * (len + 1 - i));
	if (!rest)
		return (free_past(past));
	while (past[i + j])
	{
		rest[j] = past[i + j];
		j++;
	}
	rest[j] = '\0';
	free(past);
	past = NULL;
	return (rest);
}

void	*free_past(char *past)
{
	free(past);
	past = NULL;
	return (NULL);
}

int	read_fail(char	*past, char *buff, ssize_t lenbuff)
{
	if(lenbuff == -1)
	{
		free(buff);
		free(past);
		past = NULL;
		return (1);
	}
	return (0);
}

int	main(void)
{
	int		i;
	int		file;
	char	*line;

	i = 4;
	file = open("file.txt", O_RDONLY);
	if (file == -1)
		return (1);
	while (i--)
	{
		line = get_next_line(file);
		printf("Call a ligne = %s\n", (char *)line);
		free(line);
		line = NULL;
	}
	close(file);
	return (0);
}
