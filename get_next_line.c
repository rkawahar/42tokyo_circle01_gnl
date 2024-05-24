/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:24:10 by rkawahar          #+#    #+#             */
/*   Updated: 2024/05/09 20:54:14 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str);
char	*ft_strdup(char *str);
int		checker(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*free_str(char *str);

char	*re_create1(char *ans, int fd)
{
	int		read_byte;
	char	*tmp;

	read_byte = 1;
	while (read_byte != 0 && checker(ans) == -1)
	{
		tmp = (char *)malloc(BUFFER_SIZE + 1);
		if (tmp == NULL)
			return (free_str(ans));
		read_byte = read(fd, tmp, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(tmp);
			free(ans);
			return (NULL);
		}
		tmp[read_byte] = '\0';
		ans = ft_strjoin(ans, tmp);
		if (ans == NULL)
			return (free_str(tmp));
		free(tmp);
	}
	return (ans);
}

void	ft_strcpy(char *next, int index, char *str)
{
	int	i;

	index++;
	i = 0;
	while (str[index])
		next[i++] = str[index++];
	next[i] = '\0';
}

char	*ft_trim(char *str, int index)
{
	char	*ans;
	int		i;

	ans = (char *)malloc(index + 2);
	if (ans == NULL)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (i <= index)
	{
		ans[i] = str[i];
		i++;
	}
	ans[i] = '\0';
	free(str);
	return (ans);
}

char	*ft_ans(char *next, int index, char *ans)
{
	if (index == -1)
	{
		if (ft_strlen(ans) == 0)
		{
			free(ans);
			return (NULL);
		}
		next[0] = '\0';
		return (ans);
	}
	else
	{
		ft_strcpy(next, index, ans);
		ans = ft_trim(ans, index);
		if (ans == NULL)
			return (NULL);
		return (ans);
	}
}

char	*get_next_line(int fd)
{
	static char	next[BUFFER_SIZE + 1] = "\0";
	char		*ans;
	int			index;

	if (fd > OPEN_MAX || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ans = ft_strdup(next);
	if (ans == NULL)
		return (NULL);
	ans = re_create1(ans, fd);
	if (ans == NULL)
		return (NULL);
	index = checker(ans);
	ans = ft_ans(next, index, ans);
	if (ans == NULL)
		return (NULL);
	return (ans);
}
