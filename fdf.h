/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:06:23 by jfortin           #+#    #+#             */
/*   Updated: 2016/02/18 19:25:37 by jfortin          ###   ########.fr       */
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
	int				color;
	void			*mlx;
	void			*win;
}					t_env;

typedef struct		s_line
{
	int				x;
	int				y;
	int				dx0;
	int				dy0;
	int				dx1;
	int				dy1;
	int				numerator;
	int				shortest;
	int				longest;
}					t_line;

void	ft_parse(t_env *e, char *line);
void	ft_line(int x0, int y0, int x1, int y1, t_env mlx);

#endif
