/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nograu <nograu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:38:50 by nograu            #+#    #+#             */
/*   Updated: 2025/11/23 21:48:59 by nograu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	pointer_argument_manager(va_list arg_ptr, int count)
{
	unsigned long	adresse;
	const char		*base;
	int				i;
	char			result[9];

	adresse = (unsigned long)(va_arg(arg_ptr, void *));
	base = "0123456789abcdef";
	i = 8;
	while ((adresse / 16) > 0 || i >= 8)
	{
		result[i] = base[(adresse % 16)];
		adresse = adresse / 16;
		i--;
	}
	result[i] = base[(adresse % 16)];
	write(1, "0x", 2);
	count += 2;
	while (i < 9)
	{
		write(1, &result[i], 1);
		count++;
		i++;
	}
	return (count);
}

int	lower_hexa_manager(va_list arg_ptr, int count)
{
	unsigned int	c;
	const char		*base;
	unsigned int	i;
	char			result[9];

	i = 8;
	c = va_arg(arg_ptr, unsigned int);
	base = "0123456789abcdef";
	while ((c / 16) > 0 || i >= 8)
	{
		result[i] = base[(c % 16)];
		c = c / 16;
		i--;
	}
	result[i] = base[(c % 16)];
	while (i < 9)
	{
		write(1, &result[i], 1);
		count++;
		i++;
	}
	return (count);
}

int	upper_hexa_manager(va_list arg_ptr, int count)
{
	unsigned int	c;
	const char		*base;
	unsigned int	i;
	char			result[9];

	i = 8;
	c = va_arg(arg_ptr, unsigned int);
	base = "0123456789ABCDEF";
	while ((c / 16) > 0 || i >= 8)
	{
		result[i] = base[(c % 16)];
		c = c / 16;
		i--;
	}
	result[i] = base[(c % 16)];
	while (i < 9)
	{
		write(1, &result[i], 1);
		count++;
		i++;
	}
	return (count);
}
