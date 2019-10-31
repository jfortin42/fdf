/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 16:03:19 by jfortin           #+#    #+#             */
/*   Updated: 2016/02/29 18:53:30 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_cnt_map_columns(int *columns, int fd)
{
	char	*buf_line;
	char	**split;
	int		ret;

	if ((ret = get_next_line(fd, &buf_line)) == -1)
		return (ft_ret_error(strerror(errno), FALSE));
	else if (ret == 0)
	{
		free(buf_line);
		return (END_FILE);
	}
	if ((split = ft_strsplit(buf_line, ' ')) == NULL)
	{
		free(buf_line);
		return (ft_ret_error(strerror(errno), FALSE));
	}
	*columns = 0;
	while (split[*columns])
		(*columns)++;
	ft_free_arr((void **)split);
	free(buf_line);
	return (TRUE);
}

static int	ft_get_map_size(t_map *map, int fd)
{
	int		first_line_columns;
	int		other_line_columns;
	int		ret;

	map->cnt_line = 0;
	if ((ret = ft_cnt_map_columns(&first_line_columns, fd)) == END_FILE)
		return (ft_ret_error("empty file", FALSE));
	else if (ret == FALSE)
		return (FALSE);
	map->cnt_line++;
	while ((ret = ft_cnt_map_columns(&other_line_columns, fd)) == TRUE)
	{
		if (other_line_columns != first_line_columns)
		{
			return (ft_ret_error("each "\
			"line must have the same number of columns", FALSE));
		}
		map->cnt_line++;
	}
	if (ret == FALSE)
		return (FALSE);
	if (first_line_columns == 0)
		return (ft_ret_error("first line can't be empty", FALSE));
	map->cnt_col = other_line_columns;
	return (TRUE);
}

static int	ft_alloc_arr(t_map *map)
{
	int		line;

	if ((map->data = ft_memalloc(map->cnt_line * sizeof(int *))) == NULL)
		return (ft_ret_error(strerror(errno), FALSE));
	line = 0;
	while (line < map->cnt_line)
	{
		if ((map->data[line] = ft_memalloc(map->cnt_col * sizeof(int))) == NULL)
		{
			ft_free_arr((void **)map->data);
			return (ft_ret_error(strerror(errno), FALSE));
		}
		line++;
	}
	return (TRUE);
}

static int	ft_fill_arr(t_map *map, int fd)
{
	char	*buff_line;
	char	**split;
	int		line;
	int		column;

	line = 0;
	while (get_next_line(fd, &buff_line) == 1)
	{
		if ((split = ft_strsplit(buff_line, ' ')) == NULL)
		{
			free(buff_line);
			return (ft_ret_error(strerror(errno), FALSE));
		}
		column = 0;
		while (split[column])
		{
			map->data[line][column] = ft_atoi(split[column]);
			column++;
		}
		ft_free_arr((void **)split);
		line++;
		free(buff_line);
	}
	free(buff_line);
	return (TRUE);
}

int			ft_parser(t_map *map, char *path_map)
{
	int		fd;

	if ((fd = open(path_map, O_RDONLY)) <= 0)
		return (ft_ret_error(strerror(errno), FALSE));
	if (ft_get_map_size(map, fd) == FALSE
			|| ft_alloc_arr(map) == FALSE)
	{
		close(fd);
		return (FALSE);
	}
	close(fd);
	if ((fd = open(path_map, O_RDONLY)) <= 0)
		return (ft_ret_error(strerror(errno), FALSE));
	if (ft_fill_arr(map, fd) == FALSE)
	{
		close(fd);
		return (FALSE);
	}
	close(fd);
	return (TRUE);
}
