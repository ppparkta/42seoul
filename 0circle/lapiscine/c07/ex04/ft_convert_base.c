/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base_re.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 23:37:34 by sooyang           #+#    #+#             */
/*   Updated: 2022/05/03 19:48:50 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

unsigned int	ft_strlen(char *str);
int				base_check(char *base);
int				is_base(char c, char *base);
int				ci(char c, char *base);
int				ft_atoi_base(char *str, char *base);

int	countn(unsigned int i, char *base)
{
	int	j;

	j = 0;
	while (i >= ft_strlen(base))
	{
		i = i / ft_strlen(base);
		j++;
	}
	j++;
	return (j);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	unsigned int	n;
	int				atoinbr;
	int				i;
	char			*answer;

	if (!base_check(base_from) || !base_check(base_to))
		return (0);
	atoinbr = ft_atoi_base(nbr, base_from);
	if (atoinbr < 0)
		n = -atoinbr;
	else
		n = atoinbr;
	i = countn(n, base_to) + ((atoinbr < 0));
	answer = (char *)malloc(sizeof(char) * (i + 1));
	answer[i] = 0;
	while (i--)
	{
		answer[i] = base_to[n % ft_strlen(base_to)];
		n = n / ft_strlen(base_to);
	}
	if (atoinbr < 0)
		answer[0] = '-';
	return (answer);
}
