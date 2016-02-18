/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:03:44 by jfortin           #+#    #+#             */
/*   Updated: 2016/02/18 18:44:26 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include <stdio.h>

void	ft_calc(size_t x, size_t y, t_env *e)
{
	int		pre_y;
	int		pre_x;

	e->x = y * 20 + x * 20 + (WIN_X / 5 * 2);
	e->y = y * 20 - x * 20 + (WIN_Y / 5 * 2);

	if (y == 0)
		pre_y = e->y;
	if (x == 0)
		pre_x = e->x;
	//ft_trace(e, pre_x, pre_y);
	if (y > 0 && x > 0)
	{
		pre_x = (y - 1) * 20 + x * 20 + (WIN_X / 5 * 2);
		pre_y = (y - 1) * 20 - x * 20 + (WIN_Y / 5 * 2);
	}
	// ft_trace(e, pre_x, pre_y);
	pre_y = e->y;
	pre_x = e->x;
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
			mlx_pixel_put(e->mlx, e->win, e->x, e->y, e->color);
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
	e.y = WIN_Y / 4;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_X, WIN_Y, "mlx42");
	ft_print(&e);
	mlx_key_hook(e.win, ft_key_funct, &e);
	mlx_loop(e.mlx);
	return (0);
}
