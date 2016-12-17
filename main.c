/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:03:44 by jfortin           #+#    #+#             */
/*   Updated: 2016/02/27 17:19:45 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_init(t_env *e)
{
	e->color = 0x3356FF;
	e->lr = 0;
	e->ud = 0;
	e->zoom = 1;
	e->height = 1;
	e->contrast = 0;
}

static void	ft_calc(size_t x, size_t y, t_env *e)
{
	e->x = (WIN_X / 5 * 2) + y * e->zoom + x * e->zoom + e->lr;
	e->y = (WIN_Y / 5 * 2) + y * e->zoom - x * e->zoom - e->tab[y][x]
		* e->height + e->ud;
	if (e->max_height == 0)
		e->max_height = 1;
	e->color = e->tab[y][x] * (0x3356FF / e->max_height) + e->contrast;
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
		e->color = e->tab[y][x] * (0x3356FF / e->max_height) + e->contrast;
		ft_draw(e->x, e->y, e);
	}
	e->y_prim = e->y;
	e->x_prim = e->x;
}

static int	ft_print(t_env *e)
{
	int	y;
	int	x;

	y = -1;
	mlx_destroy_image(e->mlx, e->im);
	mlx_clear_window(e->mlx, e->win);
	e->im = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	while (++y < e->cnt_line)
	{
		x = -1;
		while (++x < e->cnt_col)
			ft_calc(x, y, e);
	}
	ft_put_pixel(e, e->tmpx, e->tmpy, e->color);
	mlx_put_image_to_window(e->mlx, e->win, e->im, 0, 0);
	return (0);
}

static int	ft_key_hit(int keycode, t_env *e)
{
	if (keycode == PAGE_DOWN && e->color >= 0x111111)
		e->contrast -= 0x123456;
	if (keycode == PAGE_UP && e->color != 0xFFFFFF)
		e->contrast += 0x123456;
	if (keycode == LEFT || keycode == RIGHT)
		e->lr += (keycode == LEFT ? 2 * e->zoom : -2 * e->zoom);
	if (keycode == UP || keycode == DOWN)
		e->ud += (keycode == UP ? 2 * e->zoom : -2 * e->zoom);
	if ((keycode == MINUS && e->zoom > 1) || keycode == PLUS)
		e->zoom += (keycode == MINUS ? -1 : 1);
	if ((keycode == SLASH && e->height > -5)
			|| (keycode == STAR && e->height < 5))
		e->height += (keycode == SLASH ? -1 : 1);
	if (keycode == ZERO)
		ft_init(e);
	if (keycode == ESC)
		exit(0);
	ft_print(e);
	ft_put_help(*e);
	return (0);
}

int			main(int argc, char **argv)
{
	t_env	e;
	int		m_x;
	int		m_y;

	m_x = WIN_X * 2 / 5;
	m_y = WIN_Y * 2 / 5;
	if (argc != 2)
		ft_error("number of argument incorrect");
	ft_parse(&e, argv[1]);
	ft_init(&e);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_X, WIN_Y, "fdf");
	e.im = mlx_new_image(e.mlx, WIN_X, WIN_Y);
	e.imc = mlx_get_data_addr(e.im, &e.bpp, &e.imlen, &e.endi);
	mlx_string_put(e.mlx, e.win, m_x, m_y, 0xFF9933, WELCOME);
	mlx_string_put(e.mlx, e.win, m_x + 16, m_y + 20, 0xFF9933, PRESS);
	mlx_hook(e.win, KEYPRESS, KEYPRESSMASK, ft_key_hit, &e);
	mlx_loop(e.mlx);
	return (0);
}
