/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putfloat.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 16:25:00 by efrank         #+#    #+#                */
/*   Updated: 2019/03/28 17:02:50 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putfloat(float num, size_t len)
{
	float temp;

	ft_putnbr(num);
	if (!len)
		return ;
	ft_putchar('.');
	temp = num - (int)num;
	while (len)
	{
		temp *= 10;
		len--;
	}
	ft_putnbr(temp);
}
