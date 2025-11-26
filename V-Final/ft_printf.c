/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nograu <nograu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:52:03 by nograu            #+#    #+#             */
/*   Updated: 2025/11/26 16:50:28 by nograu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	choose_type(char character, va_list arg_ptr, int count)
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

// int main(void)
// {
// 	int print;
// 	int ft;

// 	// A noter que les counts seront toujours +1 en raison du \n !
// 	// Pour les char
// 	printf("\n_______Test %%c :__________\n\n");
// 	print = printf("%c\n", 'T');
// 	ft = ft_printf("%c\n", 'T');
// 	printf("\nPRINTF = %d et FT = %d\n", print, ft);
// 	printf("\n........................................\n");
// 	print = printf("%c\n", 0);
// 	ft = ft_printf("%c\n", 0);
// 	printf("\nPRINTF = %d et FT = %d\n", print, ft);
// 	printf("\n\n");

// 	// Pour les char *
// 	printf("\n_______Test %%s :__________\n\n");
// 	print = printf("%s\n", "Macron Demission");
// 	ft = ft_printf("%s\n", "Macron Demission");
// 	printf("\nPRINTF = %d et FT = %d\n", print, ft);
// 	printf("\n........................................\n");
// 	print = printf("%s\n", "");
// 	ft = ft_printf("%s\n", "");
// 	printf("\nPRINTF = %d et FT = %d\n", print, ft);
// 	printf("\n........................................\n");
// 	print = printf("%s\n", (char *)NULL);
// 	ft = ft_printf("%s\n", (char *)NULL);
// 	printf("\nPRINTF = %d et FT = %d\n", print, ft);
// 	printf("\n\n");

// 	// Pour les &p
// 	int a = 21345;
// 	printf("\n_______Test %%p :__________\n\n");
// 	print = printf("%p\n", &a);
// 	ft = ft_printf("%p\n", &a);
// 	printf("\nPRINTF = %d et FT = %d\n", print, ft);
// 	printf("\n........................................\n");
// 	print = printf("%p\n", NULL);
// 	ft = ft_printf("%p\n", NULL);
// 	printf("\nPRINTF = %d et FT = %d\n", print, ft);
// 	printf("\n........................................\n");
// 	printf("\n\n");

// 	void *p = NULL;
// 	printf("\nInput: p = NULL\n");
// 	printf("OR printf output: ");
// 	printf("					Size: %d", printf("%p", p));
// 	printf("\n");

// 	ft_printf("FT printf output: ");
// 	ft_printf("					Size: %d", ft_printf("%p", p));
// 	ft_printf("\n");

// 	// Pour decimal et entiers
// 	printf("\n_______Test %%d et %%i :__________\n\n");
// 	print = printf("%d et %i\n", 42, 42);
// 	ft = ft_printf("%d et %i\n", 42, 42);
// 	printf("\nPRINTF = %d et FT = %d\n", print, ft);
// 	printf("\n........................................\n");
// 	print = printf("%d et %i\n", 0, 0);
// 	ft = ft_printf("%d et %i\n", 0, 0);
// 	printf("\nPRINTF = %d et FT = %d\n", print, ft);
// 	printf("\n........................................\n");
// 	print = printf("%d et %i\n", 2147483647, 2147483647);
// 	ft = ft_printf("%d et %i\n", 2147483647, 2147483647);
// 	printf("\nPRINTF = %d et FT = %d\n", print, ft);
// 	printf("\n........................................\n");
// 	print = printf("%d et %i\n", -2147483647, -2147483647);
// 	ft = ft_printf("%d et %i\n", -2147483647, -2147483647);
// 	printf("\nPRINTF = %d et FT = %d\n", print, ft);
// 	printf("\n\n");

// 	// Pour unsigned int
// 	printf("\n_______Test %%u :__________\n\n");
// 	print = printf("%u\n", -1);
// 	ft = ft_printf("%u\n", -1);
// 	printf("\nPRINTF = %d et FT = %d\n", print, ft);
// 	printf("\n\n");

// 	// Pour hexa en min et maj
// 	printf("\n_______Test %%x et %%X :__________\n\n");
// 	print = printf("%x et %X\n", 4567, 4567);
// 	ft = ft_printf("%x et %X\n", 4567, 4567);
// 	printf("\nPRINTF = %d et FT = %d\n", print, ft);
// 	printf("\n........................................\n");
// 	print = printf("%x et %X\n", -1, -1);
// 	ft = ft_printf("%x et %X\n", -1, -1);
// 	printf("\nPRINTF = %d et FT = %d\n", print, ft);
// 	printf("\n\n");

// 	// Pour %
// 	printf("\n_______Test %% :__________\n\n");
// 	print = printf("%% Macron %% Demission %%\n");
// 	ft = ft_printf("%% Macron %% Demission %%\n");
// 	printf("\nPRINTF = %d et FT = %d\n", print, ft);
// 	printf("\n........................................\n");
// 	print = printf("%%%%%%\n");
// 	ft = ft_printf("%%%%%%\n");
// 	printf("\nPRINTF = %d et FT = %d\n", print, ft);

// 	return 0;
// }

// #include <limits.h>
// int	main(void)
// {
// 	int	age = 29;
// 	unsigned int age2 = 45;
// 	unsigned int	unsi = 246320;
// 	char	letter = 'N';
// 	char	*name = "";
// 	char	*test = "Hello";
// 	int		len = 0;

// 	len = ft_printf("Lettre: %c, Nom: %s, Age: %d et %i, Unsi: %u, Adresse: %p, 
//Integer/hexa/lower: %x, Integer/hexa/upper: %X. C'est 100%% perfect.\n", 
//letter, 
//name, age, age, unsi, test, age2, age2);
// 	printf("len: %d\n", len);
// 	len = printf("Lettre: %c, Nom: %s, Age: %d et %i, Unsi: %u, Adresse: %p, 
//Integer/hexa/lower: %x, Integer/hexa/upper: %X. C'est 100%% perfect.\n", 
//letter, 
//name, age, age, unsi, test, age2, age2);
// 	printf("len: %d\n", len);

// 	// len = ft_printf("%p\n", LONG_MIN);
// 	// printf("len : %d\n", len );
// 	// len = printf("%p\n", LONG_MIN);
// 	// printf("len : %d\n", len );
// }

//ft_printf - Lettre: N, Nom: Noemie, Age: 29 et 29, 
//Unsi: 246320, Adresse: 0x7ffdd436fc0c, Integer/hexa/lower: 2d, 
//Integer/hexa/upper: 2D. C'est 100% perfect.

//ft_printf - Lettre: N, Nom: Noemie, Age: 29 et 29, 
//Unsi: 246320, Adresse: 0x7ffdd436fc0c, Integer/hexa/lower: 2d, 
//Integer/hexa/upper: 2D. C'est 100% perfect.