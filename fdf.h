/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <jfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:06:23 by jfortin           #+#    #+#             */
/*   Updated: 2016/12/17 17:36:13 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_X 1900
# define WIN_Y 1080

# define KEYPRESS 2
# define KEYRELEASE 3
# define KEYPRESSMASK (1L<<0)
# define KEYRELEASEMASK (1L<<1)


# define WELCOME "Welcome to FDF by jfortin"
# define PRESS "Press any key to start"

# define CONTROLS		"            CONTROLS"
# define H_UP			"     move up    |    W"
# define H_DOWN			"    move down   |    S"
# define H_LEFT			"    move left   |    A"
# define H_RIGHT		"   move right   |    D"
# define H_ZOOM_IN		"    zoom in     |    E"
# define H_ZOOM_OUT		"    zoom out    |    Q"
# define H_INC_H		"increase height |    2"
# define H_DEC_H		"decrease height |    1"
# define H_COLOR_N		"   next colors  |    4"
# define H_COLOR_P		"previous colors |    3"
# define H_RESET		"     reset      | spacebar"
# define H_EXIT			"  exit program  |    esc"

# include "minilibx_macos/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include "keycode_mac.h"
# include "libft/includes/libft.h"

typedef struct		s_env
{
	int				fd;
	void			*mlx;
	void			*win;
	char			**line;
	int				cnt_line;
	int				cnt_col;
	int				**tab;
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

void				ft_parse(t_env *e, char *line);
void				ft_draw(int x2, int y2, t_env *e);
void				ft_put_help(t_env e);
void				ft_put_pixel(t_env *e, int x, int y, int color);

#endif
