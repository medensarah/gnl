/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:13:36 by smedenec          #+#    #+#             */
/*   Updated: 2025/06/26 16:37:25 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	len;
	size_t	j;
	size_t	k;

	j = 0;
	k = 0;
	len = ft_len(s1, s2);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (s1 && s1[j])
	{
		str[j] = s1[j];
		j++;
	}
	while (s2[k])
	{
		str[j + k] = s2[k];
		k++;
	}
	str[j + k] = '\0';
	free(s1);
	s1 = NULL;
	return (str);
}

size_t	ft_len(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;

	if (s1)
		len_s1 = ft_strlen(s1);
	else
		len_s1 = 0;
	if (s2)
		len_s2 = ft_strlen(s2);
	else
		len_s2 = 0;
	return (len_s1 + len_s2);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
