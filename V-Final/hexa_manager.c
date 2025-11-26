/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nograu <nograu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:38:50 by nograu            #+#    #+#             */
/*   Updated: 2025/11/26 16:30:25 by nograu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnb_hexa(unsigned long long int nb, int isup)
{
	char	*base;
	int		count;

	count = 1;
	base = "0123456789abcdef";
	if (isup)
		base = "0123456789ABCDEF";
	if (nb < 16)
	{
		write(1, &base[nb], 1);
		return (count);
	}
	else
	{
		count += putnb_hexa(nb / 16, isup);
		write(1, &base[nb % 16], 1);
	}
	return (count);
}

int	pointer_argument_manager(va_list arg_ptr, int count)
{
	unsigned long	ptr;

	ptr = (unsigned long)(va_arg(arg_ptr, void *));
	if (!ptr)
		return (write(1, "(nil)", 5), count += 5);
	write(1, "0x", 2);
	count += putnb_hexa(ptr, 0);
	return (count += 2);
}

int	lower_hexa_manager(va_list arg_ptr, int count)
{
	unsigned int	value;

	value = va_arg(arg_ptr, unsigned int);
	count += putnb_hexa(value, 0);
	return (count);
}

int	upper_hexa_manager(va_list arg_ptr, int count)
{
	unsigned int	value;

	value = va_arg(arg_ptr, unsigned int);
	count += putnb_hexa(value, 1);
	return (count);
}

// int	pointer_argument_manager(va_list arg_ptr, int count)
// {
// 	unsigned long	adresse;
// 	const char		*base;
// 	int				i;
// 	char			result[9];

// 	adresse = (unsigned long)(va_arg(arg_ptr, void *));
// 	if (!adresse)
// 		return (ft_putstr("(nil)"), count += 5);
// 	base = "0123456789abcdef";
// 	i = 8;
// 	while ((adresse / 16) > 0 || i >= 8)
// 	{
// 		result[i--] = base[(adresse % 16)];
// 		adresse = adresse / 16;
// 	}
// 	result[i] = base[(adresse % 16)];
// 	write(1, "0x", 2);
// 	count += 2;
// 	while (i < 9)
// 	{
// 		write(1, &result[i++], 1);
// 		count++;
// 	}
// 	return (count);
// }
