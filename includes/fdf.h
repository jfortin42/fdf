/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <jfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:06:23 by jfortin           #+#    #+#             */
/*   Updated: 2019/11/12 02:01:56 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"

# define WIN_X 1900
# define WIN_Y 1080

# define FALSE 0
# define TRUE 1
# define END_FILE 2

# define WELCOME "Welcome to FDF by jfortin"
# define PRESS "Press any key to start"

# define CONTROLS    "            CONTROLS"
# define H_UP        "     move up    |    up"
# define H_DOWN      "    move down   |   down"
# define H_LEFT      "    move left   |   left"
# define H_RIGHT     "   move right   |   right"
# define H_PLUS      "    zoom in     |     +"
# define H_MINUS     "    zoom out    |     ="
# define H_STAR      "increase height |     >"
# define H_SLASH     "decrease height |     <"
# define H_PAGE_UP   "   next colors  |     ]"
# define H_PAGE_DOWN "previous colors |     ["
# define H_ZERO      "     reset      |   space"
# define H_PROJ      "  choose proj   |  1  -  2"
# define H_ESC       "  exit program  |    esc"

typedef enum		e_projection
{
	ISOMETRIC,
	OBLIQUE,
	NBR_PROJ
}					t_projection;

typedef struct		s_coord_f
{
	float			x;
	float			y;
}					t_coord_f;

typedef struct		s_coord_i
{
	int				x;
	int				y;
}					t_coord_i;

typedef struct		s_point_f
{
	t_coord_f		pnt;
	int				color;
}					t_point_f;

typedef struct		s_point_i
{
	t_coord_i		pnt;
	int				color;
}					t_point_i;

typedef struct		s_bresenham
{
	t_coord_i		delta;
	t_coord_i		sign;
	int				error;
}					t_bresenham;

typedef struct		s_map
{
	int				cnt_line;
	int				cnt_col;
	int				max_height;
	int				**data;
}					t_map;

typedef struct		s_env
{
	t_map			map;

	t_projection	projection;
	int				zoom;
	int				lr;
	int				ud;
	float			height;
	int				contrast;

	void			*mlx;
	void			*win;
	void			*im;
	char			*imc;
	int				imlen;
	int				bpp;
	int				endi;
}					t_env;

int					ft_parser(t_map *map, char *path_map);
void				ft_compute_image(t_env *e);
void				ft_put_pixel(t_env *e, int x, int y, int color);
void				ft_draw_line(t_point_i start, t_point_i end, t_env *e);
void				ft_put_help(t_env e);
int					ft_ret_error(char *message, int ret_value);
void				ft_free_arr(void **arr);
int					ft_free_ret(void *to_free, int ret_value);
void				ft_clean(t_env *e);

#endif
