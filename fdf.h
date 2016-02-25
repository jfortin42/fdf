/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:06:23 by jfortin           #+#    #+#             */
/*   Updated: 2016/02/25 19:24:33 by jfortin          ###   ########.fr       */
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
# include "libft/includes/libft.h"

typedef struct		s_env
{
	int				fd;
	int				**tab;
	char			**line;
	size_t			cnt_line;
	size_t			cnt_col;
	int				x;
	int				y;
	int				x_prim;
	int				y_prim;
	int				color;
	void			*mlx;
	void			*win;

	int				zoom;
	int				lr;
	int				ud;
	int				height;
	int				contrast;

	int				max_height;

	int				tmpx;
	int				tmpy;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				tmp_error;
	int				error;
}					t_env;

void				ft_parse(t_env *e, char *line);
void				ft_draw(int x2, int y2, t_env *e);
void					ft_put_help(t_env e);

#endif
