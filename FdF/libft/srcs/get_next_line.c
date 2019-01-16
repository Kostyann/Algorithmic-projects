/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 11:56:09 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/11/02 11:56:12 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	custom(char **line, char *buf)
{
	char *tmp;

	if (*line == NULL)
		*line = ft_strdup(buf);
	else
	{
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
	}
}

int		check_stat_buff(char *stat_buf, char **line)
{
	int	i;

	i = 0;
	if (ft_strchr(stat_buf, '\n'))
	{
		i = ft_strchr(stat_buf, '\n') - stat_buf;
		stat_buf[i] = '\0';
		*line = ft_strdup(stat_buf);
		ft_memmove(stat_buf, &stat_buf[i + 1], BUFF_SIZE);
		return (1);
	}
	else
		*line = ft_strdup(stat_buf);
	ft_strclr(stat_buf);
	return (0);
}

int		check_buff(char *stat_buf, char *buf, char **line)
{
	int	i;

	i = 0;
	if (ft_strchr(buf, '\n'))
	{
		i = ft_strchr(buf, '\n') - buf;
		buf[i] = '\0';
		ft_memmove(stat_buf, &buf[i + 1], BUFF_SIZE);
		custom(line, buf);
		free(buf);
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	stat_buf[4864][BUFF_SIZE];
	char		*buf;

	if (fd < 0 || fd > 4863 || !line || read(fd, 0, 0) < 0 ||
		!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (check_stat_buff(stat_buf[fd], line))
	{
		free(buf);
		return (1);
	}
	while ((read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (check_buff(stat_buf[fd], buf, line))
			return (1);
		else
			custom(line, buf);
		ft_strclr(buf);
	}
	free(buf);
	if (**line)
		return (1);
	free(*line);
	*line = NULL;
	return (0);
}
