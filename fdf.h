/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:06:23 by jfortin           #+#    #+#             */
/*   Updated: 2016/02/20 19:09:47 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_X 1920
# define WIN_Y 1080

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

	int				tmpx;
	int				tmpy;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				tmp_error;
	int				error;
}					t_env;

void	ft_parse(t_env *e, char *line);
void	ft_draw(int x2, int y2, t_env *e);

#endif
