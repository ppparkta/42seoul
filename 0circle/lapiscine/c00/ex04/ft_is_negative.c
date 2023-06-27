/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:50:47 by sooyang           #+#    #+#             */
/*   Updated: 2022/04/18 22:08:53 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

/*int main(void)
{
	int 	i;

	i = -1;
	ft_is_negative(i);
	return 0;
}*/
void	ft_is_negative(int n)
{
	char	a;
	char	b;

	a = 'N';
	b = 'P';
	if (n >= 0)
	{
		write(1, &b, 1);
	}
	else
	{
		write(1, &a, 1);
	}
}
