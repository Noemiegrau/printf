/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nograu <nograu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:52:03 by nograu            #+#    #+#             */
/*   Updated: 2025/11/23 22:23:25 by nograu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

#include <stdio.h> // A RETIRER

static int	choose_type(char character, va_list arg_ptr, int count)  // a mettre en static ou pas ?
{
	if (character == 'c')
		count = char_manager(arg_ptr, count);
	else if (character == 's')
		count = str_manager(arg_ptr, count);
	else if (character == 'p')
		count = pointer_argument_manager(arg_ptr, count);
	else if (character == 'd' || character == 'i')
		count = integer_manager(arg_ptr, count);
	else if (character == 'u')
		count = unsigned_manager(arg_ptr, count);
	else if (character == 'x')
		count = lower_hexa_manager(arg_ptr, count);
	else if (character == 'X')
		count = upper_hexa_manager(arg_ptr, count);
	else if (character == '%')
		count = percent_manager(count);
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
	unsigned int age2 = 45;
	unsigned int	unsi = 246320;
	char	letter = 'N';
	char	*name = "Noemie";

	printf("%d", ft_printf("ft_printf - Lettre: %c, Nom: %s, Age: %d et %i, Unsi: %u, Adresse: %p, Integer/hexa/lower: %x, Integer/hexa/upper: %X. C'est 100%% perfect.\n", letter, name, age, age, unsi, &age, age2, age2));
	printf("\n");
	printf("printf - Lettre: %c, Nom: %s, Age: %d et %i, Unsi: %u, Adresse: %p, Integer/hexa/lower: %x, Integer/hexa/upper: %X. C'est 100%% perfect.\n", letter, name, age, age, unsi, &age, age2, age2);
	// ft_printf("%s, a %d et son age est stocker a l'adresse: %p! Je suis sur a 100%%\n", name, age, &age);
	// printf("%s, a %d et son age est stocker a l'adresse: %p! Je suis sur a 100%%\n", name, age, &age);
}

// gestion de 1 % passe en parametre de printf() ? ou pas

//ft_printf - Lettre: N, Nom: Noemie, Age: 29 et 29, Unsi: 246320, Adresse: 0x7ffdd436fc0c, Integer/hexa/lower: 2d, Integer/hexa/upper: 2D. C'est 100% perfect.

//ft_printf - Lettre: N, Nom: Noemie, Age: 29 et 29, Unsi: 246320, Adresse: 0x7ffdd436fc0c, Integer/hexa/lower: 2d, Integer/hexa/upper: 2D. C'est 100% perfect.