/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 16:03:19 by jfortin           #+#    #+#             */
/*   Updated: 2016/03/09 13:52:03 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_split_line(t_env *e)
{
	char	*line;
	int		ret;

	ret = 0;
	if (get_next_line(e->fd, &line) == 1)
	{
		e->line = ft_strsplit(line, ' ');
		if (!e->line)
			ft_error("invalid map");
		free(line);
		++ret;
	}
	return (ret);
}

static void	ft_int2d(t_env *e, char *file)
{
	char	*line;
	int		len;

	e->cnt_col = 0;
	e->cnt_line = 0;
	while (get_next_line(e->fd, &line) == 1)
	{
		++e->cnt_line;
		len = ft_strlen(line);
		free(line);
		if (!len)
			ft_error("invalid map");
	}
	if (e->cnt_line == 0)
		ft_error("read has failed");
	e->tab = (int **)ft_memalloc(sizeof(int *) * e->cnt_line);
	close(e->fd);
	e->fd = open(file, O_RDONLY);
	ft_split_line(e);
	while (e->line[e->cnt_col])
		++e->cnt_col;
	e->max_height = ft_atoi(e->line[0]);
	while (e->cnt_line > 0)
		e->tab[--e->cnt_line] = (int*)ft_memalloc(sizeof(int*) * e->cnt_col);
}

static void	ft_freestr2d(t_env *e)
{
	int		i;

	i = 0;
	while (e->line[i])
	{
		ft_strdel(&e->line[i]);
		++i;
	}
	free(e->line);
}

void		ft_parse(t_env *e, char *file)
{
	int	nbr_col;

	nbr_col = -1;
	if ((e->fd = open(file, O_RDONLY)) <= 0)
		ft_error("open has failed");
	ft_int2d(e, file);
	while (++nbr_col < e->cnt_col)
		e->tab[0][nbr_col] = ft_atoi(e->line[nbr_col]);
	ft_freestr2d(e);
	while (ft_split_line(e) == 1)
	{
		++e->cnt_line;
		nbr_col = -1;
		while (e->line[++nbr_col])
		{
			e->tab[e->cnt_line][nbr_col] = ft_atoi(e->line[nbr_col]);
			if (e->tab[e->cnt_line][nbr_col] > e->max_height)
				e->max_height = e->tab[e->cnt_line][nbr_col];
		}
		if (nbr_col != e->cnt_col)
			ft_error("invalid map");
	}
	++e->cnt_line;
}
