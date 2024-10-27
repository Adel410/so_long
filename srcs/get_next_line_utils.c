/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:07:13 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/06/21 15:05:26 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_strncpy(char *dest, const char *src, int n)
{
	int	i;

	i = 0;
	if (dest && src && n > 0)
	{
		while (i < n && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		while (i < n)
		{
			dest[i] = '\0';
			i++;
		}
	}
	else
	{
		while (dest[i])
		{
			dest[i] = 0;
			i++;
		}
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	ptr = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	while (s1[j])
	{
		ptr[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	free(s1);
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*str;

	len = 0;
	while (src[len])
		len++;
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *str, int searched)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == searched)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}

int	get_line_length(char *str, int i)
{
	int	len;

	len = 0;
	while (str[i + len] && str[i + len] != '\n')
		len++;
	return (len);
}
