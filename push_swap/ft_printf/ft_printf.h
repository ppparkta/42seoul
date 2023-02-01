/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:47:36 by sooyang           #+#    #+#             */
/*   Updated: 2022/07/23 18:47:36 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_print(char c, va_list *ap);
int	ft_print_c(int c);
int	ft_print_d(int n);
int	ft_print_u(unsigned int n);
int	ft_print_x(unsigned int n, int s);
int	ft_print_p(unsigned long long int n);
int	ft_print_s(char *s);
#endif
