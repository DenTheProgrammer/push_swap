/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: den <den@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:25:48 by mdebbi            #+#    #+#             */
/*   Updated: 2019/04/15 19:47:52 by den              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		has_eol(char *str)
{
	while (*str)
		if (*str++ == '\n')
			return (1);
	return (0);
}

char *ft_strjoinfree(const char *s1, const char *s2)
{
	char *ret;

	ret = ft_strjoin(s1, s2);
	free((void*)s1);
	return (ret);
}

void	shift(char **storage, size_t len)
{
	char *shifted;

	shifted = ft_strnew(ft_strlen(*storage) - len - 1);
	ft_strcpy(shifted, *storage + len + 1);
	free(*storage);
	*storage = shifted;
}

int		check_storage(char **storage, int fd)
{
	char	buf[BUFF_SIZE + 1];
	int		symb;

	if (!*storage)
		*storage = ft_strnew(0);
	if (has_eol(*storage) == 0)
		while (1)
		{
			symb = read(fd, buf, BUFF_SIZE);
			buf[symb] = '\0';
			if (symb < BUFF_SIZE)
			{
				if (symb < 0 || (symb == 0 && *storage[0] == '\0'))
				{
					free(*storage);
					return (symb < 0 ? -1 : 0);
				}
				if (buf[symb - 1] != '\n')
					ft_strncpy(buf + symb, "\n\0", 2);
			}
			*storage = ft_strjoinfree(*storage, buf);
			if (has_eol(buf) || symb == 0)
				break ;
		}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*storage[MAX_FD];
	size_t		len;
	int			check;

	if (fd < 0 || fd > MAX_FD || BUFF_SIZE < 1)
		return (-1);
	check = check_storage(&storage[fd], fd);
	if (check < 1)
		return (check);
	len = ft_strchr(storage[fd], '\n') - storage[fd];
	free(*line);
	*line = ft_strnew(len);
	ft_strncpy(*line, storage[fd], len);
	shift(&storage[fd], len);
	return (1);
}