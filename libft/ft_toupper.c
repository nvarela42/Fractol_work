/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:44:07 by nvarela           #+#    #+#             */
/*   Updated: 2016/11/22 17:44:55 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c == 0)
		return (0);
	if (c >= 'a' && c <= 'z')
		return (c = c - 32);
	else
		return (c);
}
