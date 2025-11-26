/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nograu <nograu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:29:32 by nograu            #+#    #+#             */
/*   Updated: 2025/11/26 16:28:11 by nograu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	char_manager(va_list arg_ptr, int count)
{
	char	c;

	c = va_arg(arg_ptr, int);
	write(1, &c, 1);
	return (++count);
}

int	str_manager(va_list arg_ptr, int count)
{
	char	*sentence;
	int		i;

	i = 0;
	sentence = va_arg(arg_ptr, char *);
	if (!sentence)
		return (write(1, "(null)", 6), count += 6);
	while (sentence[i])
	{
		write(1, &sentence[i], 1);
		i++;
		count++;
	}
	return (count);
}

int	integer_manager(va_list arg_ptr, int count)
{
	char	*result;
	int		i;
	int		c;

	i = 0;
	c = va_arg(arg_ptr, int);
	result = ft_itoa(c);
	while (result[i])
	{
		write(1, &result[i], 1);
		i++;
		count++;
	}
	free(result);
	return (count);
}

int	unsigned_manager(va_list arg_ptr, int count)
{
	char				*result;
	unsigned int		i;
	unsigned int		c;

	i = 0;
	c = va_arg(arg_ptr, unsigned int);
	result = ft_itoa_unsigned(c);
	while (result[i])
	{
		write(1, &result[i], 1);
		i++;
		count++;
	}
	free(result);
	return (count);
}

int	percent_manager(int count)
{
	write(1, "%", 1);
	return (count += 1);
}
