/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nograu <nograu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:52:10 by nograu            #+#    #+#             */
/*   Updated: 2025/11/23 21:49:10 by nograu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *sentence, ...);
char	*ft_itoa_unsigned(unsigned int n);
char	*ft_itoa(int n);
int		char_manager(va_list arg_ptr, int count);
int		str_manager(va_list arg_ptr, int count);
int		integer_manager(va_list arg_ptr, int count);
int		unsigned_manager(va_list arg_ptr, int count);
int		percent_manager(int count);
int		pointer_argument_manager(va_list arg_ptr, int count);
int		lower_hexa_manager(va_list arg_ptr, int count);
int		upper_hexa_manager(va_list arg_ptr, int count);

#endif