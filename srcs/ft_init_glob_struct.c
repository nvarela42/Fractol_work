/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_glob_struct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 18:04:38 by nvarela           #+#    #+#             */
/*   Updated: 2017/09/28 16:46:47 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			ft_fill_struct(t_fract *fract)
{
	fract->x_sizewin = 400;
	fract->y_sizewin = 400;
	fract->mlx = NULL;
	fract->win = NULL;
	fract->image = NULL;
	fract->imgchar = NULL;
	fract->is_burn = 0;
	fract->is_jul = 0;
	fract->is_mand = 0;
	fract->color_type = 0;
}

t_fract				*ft_init_glob_struct(void)
{
	static t_fract	*fract = NULL;
	static int		check = 0;

	if (fract == NULL && check == 0)
	{
		if (!(fract = (t_fract *)malloc(sizeof(t_fract))))
			return (NULL);
		check = 1;
		ft_fill_struct(fract);
	}
	return (fract);
}
