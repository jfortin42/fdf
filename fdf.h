/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <jfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:06:23 by jfortin           #+#    #+#             */
/*   Updated: 2019/10/31 12:09:46 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define FALSE 0
# define TRUE 1
# define END_FILE 2

# define WIN_X 1900
# define WIN_Y 1080

# define KEYPRESS 2
# define KEYRELEASE 3
# define KEYPRESSMASK (1L<<0)
# define KEYRELEASEMASK (1L<<1)

# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125
# define PLUS 69
# define MINUS 78
# define STAR 67
# define SLASH 75
# define PAGE_UP 116
# define PAGE_DOWN 121
# define ZERO 82
# define ESC 53

# define WELCOME "Welcome to FDF by jfortin"
# define PRESS "Press any key to start"

# define CONTROLS "            CONTROLS"
# define H_UP "     move up    |    up"
# define H_DOWN "    move down   |   down"
# define H_LEFT "    move left   |   left"
# define H_RIGHT "   move right   |   right"
# define H_PLUS "    zoom in     |     +"
# define H_MINUS "    zoom out    |     -"
# define H_STAR "increase height |     *"
# define H_SLASH "decrease height |     /"
# define H_PAGE_UP "   next colors  | page up"
# define H_PAGE_DOWN "previous colors | page down"
# define H_ZERO "     reset      |     0"
# define H_ESC "  exit program  |    esc"

# include "mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <sys/errno.h>
# include "libft/includes/libft.h"

typedef struct		s_map
{
	int				cnt_line;
	int				cnt_col;
	int				**data;
}					t_map;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_map			map;
	int				x;
	int				y;
	int				x_prim;
	int				y_prim;
	int				color;

	int				max_height;

	int				zoom;
	int				lr;
	int				ud;
	int				height;
	int				contrast;

	int				tmpx;
	int				tmpy;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				tmp_error;
	int				error;

	void			*im;
	char			*imc;
	int				imlen;
	int				bpp;
	int				endi;
}					t_env;

int					ft_parser(t_map *map, char *path_map);
void				ft_draw(int x2, int y2, t_env *e);
void				ft_put_help(t_env e);
void				ft_put_pixel(t_env *e, int x, int y, int color);
int					ft_ret_error(char *message, int ret_value);
void				ft_free_arr(void **arr);

#endif
