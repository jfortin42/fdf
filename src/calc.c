/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <jfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:02:23 by jfortin           #+#    #+#             */
/*   Updated: 2019/11/12 02:05:12 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

static t_coord_f	ft_isometric_proj(float x, float y, t_env *e)
{
	t_coord_f	coord;
	float		z;

	z = (float)e->map.data[(int)y][(int)x] * e->height;
	coord.x = (sqrt(2) / 2.0) * (x - y);
	coord.y = -((sqrt(2) / 3.0) * z - 1.0 / sqrt(6) * (x + y));
	return (coord);
}

static t_coord_f	ft_oblique_proj(float x, float y, t_env *e)
{
	t_coord_f	coord;
	float		alpha;
	float		z;

	alpha = -45 * M_PI / 180;
	z = (float)e->map.data[(int)y][(int)x] * e->height;
	coord.x = x + 1.0 / 2.0 * z * cos(alpha);
	coord.y = y + 1.0 / 2.0 * z * sin(alpha);
	return (coord);
}

static t_point_f	ft_calc_point(int x, int y, t_env *e)
{
	static t_coord_f	(*proj[NBR_PROJ])(float, float, t_env *) = {
		ft_isometric_proj, ft_oblique_proj
	};
	t_point_f			point;
	t_coord_f			offset;

	offset.x = WIN_X / 2.0 + e->lr;
	offset.y = WIN_Y / 2.0 + e->ud;
	point.pnt.x = offset.x + proj[e->projection](x, y, e).x * e->zoom;
	point.pnt.y = offset.y + proj[e->projection](x, y, e).y * e->zoom;
	e->map.max_height = (e->map.max_height == 0 ? 1 : e->map.max_height);
	point.color = e->map.data[y][x]
		* (0x3356FF / e->map.max_height) + e->contrast;
	return (point);
}

static t_point_i	ft_pointtoi(t_point_f input)
{
	t_point_i	output;

	output.pnt.x = (int)input.pnt.x;
	output.pnt.y = (int)input.pnt.y;
	output.color = input.color;
	return (output);
}

void				ft_compute_image(t_env *e)
{
	t_coord_i	i;
	t_point_f	point;
	t_point_f	prev_line;
	t_point_f	prev_col;

	i.y = 0;
	while (i.y < e->map.cnt_line)
	{
		i.x = 0;
		prev_col = ft_calc_point(0, i.y, e);
		while (i.x < e->map.cnt_col)
		{
			point = ft_calc_point(i.x, i.y, e);
			if (i.y > 0)
			{
				prev_line = ft_calc_point(i.x, i.y - 1, e);
				ft_draw_line(ft_pointtoi(prev_line), ft_pointtoi(point), e);
			}
			ft_draw_line(ft_pointtoi(prev_col), ft_pointtoi(point), e);
			prev_col = point;
			i.x++;
		}
		i.y++;
	}
	ft_put_pixel(e, point.pnt.x, point.pnt.y, point.color);
}
