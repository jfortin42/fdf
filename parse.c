/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 16:03:19 by jfortin           #+#    #+#             */
/*   Updated: 2016/02/14 14:07:18 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_split_line(t_env *e)
{
	char	*line;
	int		ret;

	ret = 0;
	if (get_next_line(e->fd, &line) == 1)
	{
		e->line = ft_strsplit(line, ' ');
		free(line);
		++ret;
	}
	return (ret);
}


void	ft_int2d(t_env *e, char *file)
{
	char	*line;

	e->cnt_col = 0;
	e->cnt_line = 0;
	while (get_next_line(e->fd, &line) == 1)
	{
		++e->cnt_line;
		free(line);
	}
	if (e->cnt_line == 0)
		ft_error("read as failed");
	e->tab = (int **)ft_memalloc(sizeof(int *) * e->cnt_line);
	close(e->fd);
	e->fd = open(file, O_RDONLY);
	ft_split_line(e);
	while (e->line[e->cnt_col])
		++e->cnt_col;
	while (e->cnt_line-- > 0)
		e->tab[e->cnt_line] = (int *)ft_memalloc(sizeof(int *) * e->cnt_col);
}

void	ft_freestr2d(t_env *e)
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

void	ft_parse(t_env *e, char *file)
{
	size_t	nbr_col;

	nbr_col = 0;
	if ((e->fd = open(file, O_RDONLY)) <= 0)
		ft_error("open has failed");
	ft_int2d(e, file);
	while (nbr_col < e->cnt_col)
	{
		e->tab[0][nbr_col] = ft_atoi(e->line[nbr_col]);
		++nbr_col;
	}
	ft_freestr2d(e);
	while (ft_split_line(e) == 1)
	{
		++e->cnt_line;
		nbr_col = 0;
		while (e->line[nbr_col])
		{
			e->tab[e->cnt_line][nbr_col] = ft_atoi(e->line[nbr_col]);
			++nbr_col;
		}
		if (nbr_col != e->cnt_col)
			ft_error("invalid map");
	}
	// checking
	int		x;
	int		y;
	y = 0;
	while (y < e->cnt_line)
	{
		x = 0;
		while (x < e->cnt_col)
		{
			ft_putnbr(e->tab[y][x]);
			ft_putchar(' ');
			++x;
		}
		ft_putchar('\n');
		++y;
	}
}
