/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:19:34 by smedenec          #+#    #+#             */
/*   Updated: 2025/06/22 21:26:41 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stddef.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
# endif

char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
int	ft_len(char *s1, char *s2);
char	*ft_strchr(char *s, int c);

#endif
