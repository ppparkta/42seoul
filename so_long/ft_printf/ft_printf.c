/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:50:22 by sooyang           #+#    #+#             */
/*   Updated: 2022/07/28 16:09:12 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_print(char c, va_list *ap)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_print_c(va_arg(*ap, int));
	if (c == 'd' || c == 'i')
		len += ft_print_d(va_arg(*ap, int));
	if (c == 'u')
		len += ft_print_u(va_arg(*ap, unsigned int));
	if (c == 'x')
		len += ft_print_x(va_arg(*ap, unsigned int), 2);
	if (c == 'X')
		len += ft_print_x(va_arg(*ap, unsigned int), 1);
	if (c == 'p')
	{
		len += write(1, "0x", 2);
		len += ft_print_p(va_arg(*ap, unsigned long int));
	}
	if (c == 's')
		len += ft_print_s(va_arg(*ap, char *));
	if (c == '%')
		len += write(1, "%", 1);
	return (len);
}

int	ft_print_c(int c)
{
	int	len;

	len = write(1, &c, 1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		len;

	len = 0;
	i = 0;
	va_start(ap, format);
	while (format[i] != 0)
	{
		if (format[i] != '%')
			len += write(1, &format[i], 1);
		else
		{
			len += ft_print(format[i + 1], &ap);
			i++;
		}
		i++;
	}
	va_end(ap);
	return (len);
}

/*#include	<stdio.h>

int main()
{
	int a=ft_printf("abcd%dg\n", 32);
	int b=printf("abcd%dg\n", 32);

	printf("%d\n",a);
	printf("%d\n",b);	
}*/
