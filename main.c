/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:03:44 by jfortin           #+#    #+#             */
/*   Updated: 2016/02/22 17:26:24 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	ft_calc(size_t x, size_t y, t_env *e)
{
	e->x = (y * 20 + x * 20) + e->lr;
	e->y = y * 20 - x * 20 - e->tab[y][x] + (WIN_Y / 5 * 2);

	if (x == 0)
	{
		e->y_prim = e->y;
		e->x_prim = e->x;
	}
	ft_draw(e->x, e->y, e);
	if (y > 0)
	{
		e->x_prim = ((y - 1) * 20 + x * 20) + e->lr;
		e->y_prim = (y - 1) * 20 - x * 20 - e->tab[y - 1][x]
			+ (WIN_Y / 5 * 2);
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
	if (keycode == 121 && e->color >= 0x111111)
		e->color = e->color - 0x111111;
	if (keycode == 116 && e->color <= 0xEEEEEE)
		e->color = e->color + 0x111111;
	if (keycode == 123)
		e->lr += 10;
	if (keycode == 124)
		e->lr -= 10;
	if (keycode == 53)
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
	e.color = 0x00FFFFFF;
	e.lr = 0;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_X, WIN_Y, "mlx42");
	ft_print(&e);
	mlx_key_hook(e.win, ft_key_funct, &e);
	mlx_loop(e.mlx);
	return (0);
}
