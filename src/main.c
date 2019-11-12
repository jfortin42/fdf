/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <jfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:03:44 by jfortin           #+#    #+#             */
/*   Updated: 2019/11/12 01:58:46 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keycode_mac.h"

static void	ft_init_ctrl(t_env *e)
{
	e->projection = ISOMETRIC;
	e->lr = 0;
	e->ud = 0;
	e->zoom = 1;
	e->height = 1;
	e->contrast = 0;
}

static int	ft_render_image(t_env *e)
{
	ft_bzero(e->imc, WIN_X * WIN_Y * 4);
	mlx_clear_window(e->mlx, e->win);
	ft_compute_image(e);
	mlx_put_image_to_window(e->mlx, e->win, e->im, 0, 0);
	return (0);
}

static int	ft_key_hit(int keycode, t_env *e)
{
	if (keycode == KEY_OPEN_BRACKET && e->contrast >= 0x111111)
		e->contrast -= 0x123456;
	else if (keycode == KEY_CLOSE_BRACKET && e->contrast != 0xFFFFFF)
		e->contrast += 0x123456;
	else if (keycode == KEY_RIGHT || keycode == KEY_LEFT)
		e->lr += (keycode == KEY_RIGHT ? 2 * e->zoom : -2 * e->zoom);
	else if (keycode == KEY_DOWN || keycode == KEY_UP)
		e->ud += (keycode == KEY_DOWN ? 2 * e->zoom : -2 * e->zoom);
	else if ((keycode == KEY_MINUS && e->zoom > 1) || keycode == KEY_EQUAL)
		e->zoom += (keycode == KEY_MINUS ? -1 : 1);
	else if ((keycode == KEY_LESS_THAN && e->height > -5)
			|| (keycode == KEY_GREATER_THAN && e->height < 5))
		e->height += (keycode == KEY_LESS_THAN ? -1 : 1);
	else if (keycode == KEY_SPACEBAR)
		ft_init_ctrl(e);
	else if (keycode == KEY_ESCAPE)
	{
		ft_clean(e);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == KEY_1 || keycode == KEY_2)
		e->projection = (keycode == KEY_1 ? ISOMETRIC : OBLIQUE);
	ft_render_image(e);
	ft_put_help(*e);
	return (0);
}

int			main(int ac, char **av)
{
	t_env	e;
	int		m_x;
	int		m_y;

	if (ac < 2)
		return (ft_ret_error("map file is missing", EXIT_FAILURE));
	ft_bzero(&e, sizeof(e));
	ft_init_ctrl(&e);
	if (ft_parser(&e.map, av[1]) == FALSE)
		return (ft_ret_error("invalid map file", EXIT_FAILURE));
	if ((e.mlx = mlx_init()) == NULL
		|| (e.win = mlx_new_window(e.mlx, WIN_X, WIN_Y, "fdf")) == NULL
		|| (e.im = mlx_new_image(e.mlx, WIN_X, WIN_Y)) == NULL
		|| (e.imc = mlx_get_data_addr(e.im, &e.bpp, &e.imlen, &e.endi)) == NULL)
	{
		ft_clean(&e);
		return (ft_ret_error("mlx error", EXIT_FAILURE));
	}
	m_x = WIN_X * 2 / 5;
	m_y = WIN_Y * 2 / 5;
	mlx_string_put(e.mlx, e.win, m_x, m_y, 0xFF9933, WELCOME);
	mlx_string_put(e.mlx, e.win, m_x + 16, m_y + 20, 0xFF9933, PRESS);
	mlx_hook(e.win, KEYPRESS, KEYPRESSMASK, ft_key_hit, &e);
	mlx_loop(e.mlx);
	return (EXIT_SUCCESS);
}
