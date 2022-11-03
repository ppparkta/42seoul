/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base_re2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 23:47:49 by sooyang           #+#    #+#             */
/*   Updated: 2022/05/03 19:48:58 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	base_check(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = -1;
	while (base[++i])
	{
		j = i + 1;
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == 32)
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
	}
	return (1);
}

int	is_base(char c, char *base)
{
	int	i;

	i = -1;
	while (base[++i])
	{
		if (base[i] == c)
			return (1);
	}
	return (0);
}

int	ci(char c, char *base)
{
	int	i;

	i = -1;
	while (base[++i])
	{
		if (base[i] == c)
			return (i);
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	nb;
	int	sy;

	i = 0;
	nb = 0;
	sy = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sy *= -1;
		i++;
	}
	if (!is_base(str[i], base))
		return (0);
	i = i - 1;
	while (is_base(str[++i], base))
	{
		nb = nb * ft_strlen(base) + (ci(str[i], base) / ft_strlen(base))
			+ (ci(str[i], base) % ft_strlen(base));
	}
	return (nb * sy);
}
