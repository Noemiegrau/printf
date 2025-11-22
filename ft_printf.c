/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nograu <nograu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:52:03 by nograu            #+#    #+#             */
/*   Updated: 2025/11/22 17:12:13 by nograu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

#include <stdio.h> // A RETIRER

int	ft_intlen(int n) // a mettre en static ou pas ?
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n) // a mettre en static ou pas ?
{
	int		len;
	char	*str;
	long	nb;

	len = ft_intlen(n);
	nb = n;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[--len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (str);
}

int	char_management(va_list arg_ptr, int count) // a mettre en static ou pas ?
{
	char	c;

	c = va_arg(arg_ptr, int);
	write(1, &c, 1);
	return (count++);
}

int	str_management(va_list arg_ptr, int count) // a mettre en static ou pas ?
{
	char	*sentence;
	int		i;

	i = 0;
	sentence = va_arg(arg_ptr, char *);
	if (!sentence) // utile ou pas ? a tester
		sentence = "(null)";
	while (sentence[i])
	{
		write(1, &sentence[i], 1);
		i++;
		count++;
	}
	return (count);
}

// int	pointer_argument_management(va_list arg_ptr, int count)
// {
	
// }

int	integer_management(va_list arg_ptr, int count) // a mettre en static ou pas ?
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

int	unsigned_management(va_list arg_ptr, int count)
{
	char				*result;
	unsigned int		i;
	unsigned int		c;

	i = 0;
	c = va_arg(arg_ptr, unsigned int);
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

// int	lower_hexa_management(va_list arg_ptr, int count)
// {
	
// }

// int	upper_hexa_management(va_list arg_ptr, int count)
// {
	
// }

int	percent_management(int count) // a mettre en static ou pas ?
{
	write(1, "%", 1); // a verifier
	return (count++);
}


int	choose_type(char character, va_list arg_ptr, int count) // a mettre en static ou pas ?
{
	if (character == 'c')
		count = char_management(arg_ptr, count);
	else if (character == 's')
	 	count = str_management(arg_ptr, count);
	// else if (character == 'p')
	// 	pointer_argument_management();
	else if (character == 'd' || character == 'i')
		count = integer_management(arg_ptr, count);
	else if (character == 'u')
		unsigned_management(arg_ptr, count);
	// else if (character == 'x')
	// 	lower_hexa_management();
	// else if (character == 'X')
	// 	upper_hexa_management();
	else if (character == '%')
		count = percent_management(count);
	return (count);
}

int	ft_printf(const char *sentence, ...)
{
	va_list	arg_ptr;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(arg_ptr, sentence);
	while (sentence[i])
	{
		if (sentence[i] == '%')
		{
			i++;
			count = choose_type(sentence[i], arg_ptr, count);
		}
		else
		{
			write(1, &sentence[i], 1);
			count++;
		}
		i++;
	}
	va_end(arg_ptr);
	return (count);
}

int	main(void)
{
	int	age = 29;
	//int	neg_age = -29;
	unsigned int	unsi = 20;
	//char	letter = 'N';
	//char	g = 'G';
	//char	*name = "Noemie";

	printf("%d", ft_printf("printf 100%% perfect - Age: %i, Unsi: %u \n", age, unsi));
	//ft_printf("printf %%- Letter: %c and Name: %c\n", letter, name);
	//ft_printf("printf - Nom: %s, char: %c, age: %d, adresse: %p\n", name, c, age, &age);
	//printf("printf - Name: %c\n", c);
	//ft_printf("printf - Nom: %s, char: %c, age: %d, adresse: %p\n", name, c, age, &age);
	//printf("printf - Nom: %s, char: %c, age: %d, adresse: %p\n", name, c, age, &age);
	// ft_printf("%s, a %d et son age est stocker a l'adresse: %p! Je suis sur a 100%%\n", name, age, &age);
	// printf("%s, a %d et son age est stocker a l'adresse: %p! Je suis sur a 100%%\n", name, age, &age);
}

// pdiuxX
// --cspdiuxX%--


/////// A SUPPRIMER A LA FIN ///////

// int	percent_management(va_list arg_ptr, int count) // a mettre en static ou pas ?
// {
// 	if (sentence[i] == '%' && sentence[i + 1] != 'c'
// 		&& sentence[i + 1] != 's' && sentence[i + 1] != 'd'
// 		&& sentence[i + 1] != 'i' && sentence[i + 1] != 'u'
// 		&& sentence[i + 1] != 'x' && sentence[i + 1] != 'X')
// 		{
// 			write(1, "%%", 1);
// 			count++;
// 			write(1, &sentence[i + 1], 1);
// 			count++;
// 		}
// 		return (count);
// }

// count = count + choose_type(sentence[i], arg_ptr, count);