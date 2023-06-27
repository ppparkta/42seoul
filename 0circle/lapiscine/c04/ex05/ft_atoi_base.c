/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:30:41 by sooyang           #+#    #+#             */
/*   Updated: 2022/04/26 00:07:53 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
//#include	<stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	base_check(char *str, char *base, int x)
{
	int	baselen;
	int	y;
	int	answer;

	baselen = ft_strlen(base);
	answer = 0;
	while (str[x] != '\0')
	{
		y = 0;
		while (y < baselen)
		{
			if (str[x] == base[y])
			{
				answer = answer * baselen + y;
				break ;
			}
			else
				y++;
		}
		if (y == baselen)
			break ;
		x++;
	}
	return (answer);
}

int	ft_atoi(char *str, char *base)
{
	int	x;
	int	sy;
	int	answer;

	x = 0;
	sy = 1;
	while ((str[x] >= 9 && str[x] <= 13) || str[x] == 32)
		x++;
	while (str[x] == '+' || str[x] == '-')
	{
		if (str[x] == '-')
			sy *= -1;
		x++;
	}
	answer = base_check(str, base, x);
	if (answer == -1)
		return (-1);
	return (answer * sy);
}

int	base_valid(char *base)
{
	int	baselen;
	int	j;
	int	k;
	int	alpha[256];

	j = 0;
	while (j < 256)
		alpha[j++] = 0;
	baselen = ft_strlen(base);
	j = 0;
	if (baselen < 2)
		return (1);
	while (base[j] != '\0')
	{
		k = base[j];
		if (alpha[k] == 1)
			return (1);
		if (base[j] == '+' || base[j] == '-')
			return (1);
		alpha[k] = 1;
		j++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	answer;

	if (base_valid(base) == 1)
		return (0);
	answer = ft_atoi(str, base);
	return (answer);
}

/*int	main(void)
{
	//ex05
	printf("------ ex05 ------\n\n");
	char ex05_str1[] = " \n -+-++-+2147483648";
	char ex05_str2[] = "   ---+AABCDESSEZ";
	char ex05_str3[] = "   ++136667";
	char ex05_str4[] = "   -----+-+!!@@#..<";
	char ex05_str5[] = "  \n \tatoi12-+123base";
	printf("-2147483648\n");
	printf("%d\n\n", ft_atoi_base(ex05_str1, "0123456789"));
	printf("0\n");
	printf("%d\n\n", ft_atoi_base(ex05_str1, ""));
	printf("-67174\n");
	printf("%d\n\n", ft_atoi_base(ex05_str2, "ABCDES"));
	printf("empty\n");
	printf("%d\n\n", ft_atoi_base(ex05_str2, ""));
	printf("0\n");
	printf("%d\n\n", ft_atoi_base(ex05_str3, "A-+"));
	printf("12347\n");
	printf("%d\n\n", ft_atoi_base(ex05_str3, "3405816"));
	printf("1126397\n");
	printf("%d\n\n", ft_atoi_base(ex05_str4, "!@#$%^&*()~?><'."));
	printf("27\n");
	printf("%d\n\n", ft_atoi_base(ex05_str5, "atoi"));
}*/
