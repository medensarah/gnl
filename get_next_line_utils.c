/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:13:36 by smedenec          #+#    #+#             */
/*   Updated: 2025/06/22 21:32:50 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s++ == (char)c)
			return (--s);
	}
	if ((char)c == '\0')
		return (s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		len;
	int		j;
	int		k;

	j = 0;
	k = 0;
	if (!s2)
		return (NULL);
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
	printf("join = %s\n", (char *)str);
	return (str);
}

int	ft_len(char *s1, char *s2)
{
	int		len_s1;
	int		len_s2;

	if (s1)
		len_s1 = ft_strlen(s1);
	else
		len_s1 = 0;
	len_s2 = ft_strlen(s2);
	return (len_s1 + len_s2);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		j;
	int		len;

	j = 0;
	len = ft_strlen(s);
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	while (j < len)
	{
		ptr[j] = s[j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
