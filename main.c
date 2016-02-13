/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:03:44 by jfortin           #+#    #+#             */
/*   Updated: 2016/02/12 18:54:14 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	ft_print(t_env e)
{
	while (e.y < WIN_Y * 3 / 4)
	{
		e.x = WIN_X / 4;
		while (e.x < WIN_X * 3 / 4)
		{
			mlx_pixel_put(e.mlx, e.win, e.x, e.y, e.color);
			++e.x;
		}
		++e.y;
	}
}

int	ft_key_funct(int keycode, t_env *e)
{
	printf("Key press %d\n", keycode);
	if (keycode == 121 && e->color >= 0x00111111)
		e->color = e->color - 0x00111111;
	if (keycode == 116 && e->color <= 0x00EEEEEE)
		e->color = e->color + 0x00111111;
	if (keycode == 53)
		exit(0);
	mlx_clear_window(e->mlx, e->win);
	ft_print(*e);
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
	ft_print(e);
	mlx_key_hook(e.win, ft_key_funct, &e);
	mlx_loop(e.mlx);
	return (0);
}
