/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:41:09 by sooyang           #+#    #+#             */
/*   Updated: 2022/04/18 22:03:28 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

/*int	main(void)
{
	ft_print_numbers();
	return 0;
}*/
void	ft_print_numbers(void)
{
	char	a;

	a = '0';
	while (a <= '9')
	{
		write(1, &a, 1);
		a++;
	}
}
