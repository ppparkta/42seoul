/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:06:41 by sooyang           #+#    #+#             */
/*   Updated: 2022/04/14 16:26:25 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

void	ft_print_alphabet(void);

void	ft_print_alphabet(void)
{
	char	a;

	a = 'a';
	while (a < 123)
	{
		write(1, &a, 1);
		a++;
	}
}
