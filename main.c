/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:03:44 by jfortin           #+#    #+#             */
/*   Updated: 2016/02/22 23:50:54 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	ft_init(t_env *e)
{
	e->color = 0x00FFFFFF;
	e->lr = 0;
	e->ud = 0;
	e->zoom = 1;
	e->height = 1;
	e->contrast = 0;
}

void	ft_calc(size_t x, size_t y, t_env *e)
{
	e->x = (WIN_X * 2 / 5) + y * e->zoom + x * e->zoom + e->lr;
	e->y = (WIN_Y / 5 * 2) + y * e->zoom - x * e->zoom - e->tab[y][x]
		* e->height + e->ud;
	e->color = e->tab[y][x] * 0xFFFFFF / e->max_height + e->contrast;
	if (x == 0)
	{
		e->y_prim = e->y;
		e->x_prim = e->x;
	}
	ft_draw(e->x, e->y, e);
	if (y > 0)
	{
		e->x_prim = (WIN_X / 5 * 2) + (y - 1) * e->zoom + x * e->zoom + e->lr;
		e->y_prim = (WIN_Y / 5 * 2) + (y - 1) * e->zoom - x * e->zoom
			- e->tab[y - 1][x] * e->height + e->ud;
		e->color = e->tab[y][x] * 0xFFFFFF / e->max_height + e->contrast;
		ft_draw(e->x, e->y, e);
	}
	e->y_prim = e->y;
	e->x_prim = e->x;
}

void	ft_print(t_env *e)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < e->cnt_line)
	{
		x = 0;
		while (x < e->cnt_col)
		{
			ft_calc(x, y, e);
			++x;
		}
		++y;
	}
}

int	ft_key_funct(int keycode, t_env *e)
{
	printf("Key press %d\n", keycode);
	if (keycode == PAGE_DOWN && e->color >= 0x111111)
		e->contrast -= 0x111111;
	if (keycode == PAGE_UP && e->color <= 0xEEEEEE)
		e->contrast += 0x111111;
	if (keycode == LEFT)
		e->lr -= 10;
	if (keycode == RIGHT)
		e->lr += 10;
	if (keycode == UP)
		e->ud -= 10;
	if (keycode == DOWN)
		e->ud += 10;
	if (keycode == PLUS)
		e->zoom += 1;
	if (keycode == MINUS)
		e->zoom -= 1;
	if (keycode == STAR)
		e->height += 1;
	if (keycode == SLASH)
		e->height -= 1;
	if (keycode == ZERO)
		ft_init(e);
	if (keycode == ESC)
		exit(0);
	mlx_clear_window(e->mlx, e->win);
	ft_print(e);
	printf("color %x\n", e->color);
	return (0);
}

int	main(int argc, char **argv)
{
	t_env	e;

	if (argc != 2)
		ft_error("number of argument incorrect");
	ft_parse(&e, argv[1]);
	ft_init(&e);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_X, WIN_Y, "mlx42");
	ft_print(&e);
	mlx_key_hook(e.win, ft_key_funct, &e);
	mlx_loop(e.mlx);
	return (0);
}
