/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <jfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:09:18 by jfortin           #+#    #+#             */
/*   Updated: 2019/11/11 23:45:19 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_ret_error(char *message, int ret_value)
{
	ft_putstr_fd(message, 2);
	ft_putchar_fd('\n', 2);
	return (ret_value);
}

void	ft_free_arr(void **arr)
{
	int		line;

	line = 0;
	while (arr && arr[line])
	{
		free(arr[line]);
		line++;
	}
	free(arr);
}

int		ft_free_ret(void *to_free, int ret_value)
{
	free(to_free);
	return (ret_value);
}

void	ft_clean(t_env *e)
{
	ft_free_arr((void **)e->map.data);
	if (e->mlx)
	{
		if (e->im)
			mlx_destroy_image(e->mlx, e->im);
		if (e->win)
			mlx_destroy_window(e->mlx, e->win);
	}
}
