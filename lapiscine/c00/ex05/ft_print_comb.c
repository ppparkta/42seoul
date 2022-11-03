/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:23:18 by sooyang           #+#    #+#             */
/*   Updated: 2022/04/18 23:19:13 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

void	ft_print_comb(void);

/*int	main(void)
{
	ft_print_comb();
}*/
void	ft_print_comb(void)
{
	char	s[3];

	s[0] = '0';
	while (s[0] <= '7')
	{
		s[1] = s[0] + 1;
		while (s[1] <= '8')
		{
			s[2] = s[1] + 1;
			while (s[2] <= '9')
			{
				write(1, &s, 3);
				if (!(s[0] == '7' && s[1] == '8' && s[2] == '9'))
				{
					write(1, ", ", 2);
				}
				s[2]++;
			}
			s[1]++;
		}
		s[0]++;
	}
}	
