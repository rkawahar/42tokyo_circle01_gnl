/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:24:13 by rkawahar          #+#    #+#             */
/*   Updated: 2024/05/07 14:46:44 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	ans;

	ans = 0;
	while (str[ans])
		ans++;
	return (ans);
}

char	*ft_strdup(char *str)
{
	char	*ans;
	size_t	len;
	int		i;

	len = ft_strlen(str);
	ans = (char *)malloc(len + 1);
	if (ans == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		ans[i] = str[i];
		i++;
	}
	ans[i] = '\0';
	return (ans);
}

int	checker(char *str)
{
	int	ans;

	ans = 0;
	while (str[ans])
	{
		if (str[ans] == '\n')
			return (ans);
		ans++;
	}
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ans;
	int		i;
	int		j;

	ans = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ans == NULL)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (s1[i])
	{
		ans[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		ans[i++] = s2[j++];
	ans[i] = '\0';
	free(s1);
	return (ans);
}

char	*free_str(char *str)
{
	free(str);
	return (NULL);
}
