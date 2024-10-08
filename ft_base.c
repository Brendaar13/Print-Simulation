#include "ft_printf.h"

size_t	type_base(size_t num, char *ptr, size_t len_base)
{
	char	array[20];
	size_t	c_printed;
	size_t	res;
	size_t	i;

	i = 0;
	c_printed = 0;
	if (num == 0)
		c_printed += ft_putchar(ptr[0]);
	if (num != 0)
	{
		res = num % len_base;
		array[i] = ptr[res];
		num = num / len_base;
		++i;
	}
	while (i--)
		c_printed += ft_putchar(array[i]);
	return (c_printed);
}

size_t	ft_base(size_t num, char *ptr, size_t base, char c_exit)
{
	size_t	c_printed;

	c_printed = 0;
	if (num < 0 && (c_exit == 'd' || c_exit == 'u' || c_exit == 'i'))
	{
		c_printed += ft_putchar('-');
		num = -num;
	}
	else if (num == 0 && (c_exit == 'p'))
	{
		c_printed += ft_putstr("0x0");
		return (c_printed);
	}
	else if (c_exit == 'p')
	{
		c_printed += ft_putstr("0x");
		c_printed += type_base(num, ptr, base);
	}
	return (c_printed);
}
