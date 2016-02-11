/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 16:03:19 by jfortin           #+#    #+#             */
/*   Updated: 2016/02/11 19:12:42 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_str2d(t_env *e, char *file)
{
	char	*line;
	size_t	i;

	i = 0;
	while ((get_next_line(e->fd, &line) == 1))
	{
		++i;
		free(line);
	}
	close(e->fd);
	e->fd = open(file, O_RDONLY);
	if (!(e->line = (char **)ft_memalloc(sizeof(char *) * (i + 1))))
		ft_error("malloc has failed");
	free(line);
}

void	ft_parse(t_env *e, char *file)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = -1;
	if ((e->fd = open(file, O_RDONLY)) <= 0)
		ft_error("open has failed");
	ft_str2d(e, file);
	while ((get_next_line(e->fd, &(e->line[i])) == 1))
		++i;
	while (++j < i)
		{
			ft_putendl(e->line[j]);
			free(e->line[j]);
		}
	free(e->line);
}
