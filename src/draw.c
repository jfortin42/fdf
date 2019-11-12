/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <jfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 17:33:10 by jfortin           #+#    #+#             */
/*   Updated: 2019/11/12 02:05:31 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_put_pixel(t_env *e, int x, int y, int color)
{
	int	(*pix_table)[WIN_X][1];

	if (y >= WIN_Y || x >= WIN_X || x < 0 || y < 0)
		return ;
	pix_table = (void *)e->imc;
	*pix_table[y][x] = color;
	// *(int *)&e->imc[y * e->imlen + x * e->bpp / 8] = color;
}

void		ft_draw_line(t_point_i s, t_point_i end, t_env *e)
{
	t_bresenham	b;
	int			tmp_error;

	b.delta.x = abs(end.pnt.x - s.pnt.x);
	b.delta.y = abs(end.pnt.y - s.pnt.y);
	b.sign.x = s.pnt.x < end.pnt.x ? 1 : -1;
	b.sign.y = s.pnt.y < end.pnt.y ? 1 : -1;
	b.error = (b.delta.x > b.delta.y ? b.delta.x : -(b.delta.y)) / 2;
	while (((b.sign.x > 0 && s.pnt.x < WIN_X) || (b.sign.x < 0 && s.pnt.x >= 0))
		&& ((b.sign.y > 0 && s.pnt.y < WIN_Y) || (b.sign.y < 0 && s.pnt.y >= 0))
		&& !(s.pnt.y == end.pnt.y && s.pnt.x == end.pnt.x))
	{
		ft_put_pixel(e, s.pnt.x, s.pnt.y, end.color);
		tmp_error = b.error;
		if (tmp_error > -(b.delta.x))
		{
			b.error -= (b.delta.y);
			s.pnt.x += b.sign.x;
		}
		if (tmp_error < (b.delta.y))
		{
			b.error += (b.delta.x);
			s.pnt.y += b.sign.y;
		}
	}
}

void		ft_put_help(t_env e)
{
	int	y;
	int	spacing;

	y = 0;
	spacing = 16;
	mlx_string_put(e.mlx, e.win, 0, y, 0xDDDDDD, CONTROLS);
	mlx_string_put(e.mlx, e.win, 0, y += spacing, 0xDDDDDD, H_UP);
	mlx_string_put(e.mlx, e.win, 0, y += spacing, 0xDDDDDD, H_DOWN);
	mlx_string_put(e.mlx, e.win, 0, y += spacing, 0xDDDDDD, H_LEFT);
	mlx_string_put(e.mlx, e.win, 0, y += spacing, 0xDDDDDD, H_RIGHT);
	mlx_string_put(e.mlx, e.win, 0, y += spacing, 0xDDDDDD, H_PLUS);
	mlx_string_put(e.mlx, e.win, 0, y += spacing, 0xDDDDDD, H_MINUS);
	mlx_string_put(e.mlx, e.win, 0, y += spacing, 0xDDDDDD, H_STAR);
	mlx_string_put(e.mlx, e.win, 0, y += spacing, 0xDDDDDD, H_SLASH);
	mlx_string_put(e.mlx, e.win, 0, y += spacing, 0xDDDDDD, H_PAGE_UP);
	mlx_string_put(e.mlx, e.win, 0, y += spacing, 0xDDDDDD, H_PAGE_DOWN);
	mlx_string_put(e.mlx, e.win, 0, y += spacing, 0xDDDDDD, H_ZERO);
	mlx_string_put(e.mlx, e.win, 0, y += spacing, 0xDDDDDD, H_PROJ);
	mlx_string_put(e.mlx, e.win, 0, y += spacing, 0xDDDDDD, H_ESC);
}
