/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 16:08:58 by sooyang           #+#    #+#             */
/*   Updated: 2022/05/03 19:48:42 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

int	leng(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	all_leng(int size, char **strs, char *sep)
{
	int	i;
	int	result;
	int	sep_leng;

	result = 0;
	sep_leng = leng(sep);
	i = 0;
	if (size == 1)
		return (leng(strs[i]) + 1);
	while (i < size - 1)
	{
		result += leng(strs[i]);
		result += sep_leng;
		i++;
	}
	result += leng(strs[i]);
	return (result + 1);
}

char	*ft_strcat(char *dest, const char *src)
{
	char	*temp;
	int		i;
	int		j;

	temp = dest;
	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = 0;
	return (temp);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		all_lengs;
	int		i;

	if (size == 0)
	{
		str = (char *)malloc(1);
		str[0] = 0;
		return (str);
	}
	all_lengs = all_leng(size, strs, sep);
	str = (char *)malloc(sizeof(char) * all_lengs);
	i = 0;
	str[i] = 0;
	while (i < (size - 1))
	{
		str = ft_strcat(str, strs[i]);
		str = ft_strcat(str, sep);
		i++;
	}
	str = ft_strcat(str, strs[i]);
	return (str);
}

/*
#include	<stdio.h>
int main(void)
{
	  printf("-------ex03-------\n\n");
    char *ex03_arr1;
    char *ex03_arr2;
    char *ex03_arr3;
	char *ex03_str[5];
	ex03_str[0] = "hello";
	ex03_str[1] = "my";
	ex03_str[2] = "name";
	ex03_str[3] = "is";
	ex03_str[4] = "hunpark!";
	ex03_arr1 = ft_strjoin(5, ex03_str, "");
    ex03_arr2 = ft_strjoin(5, ex03_str, ".");
    ex03_arr3 = ft_strjoin(5, ex03_str, "-");
	printf("%s\n", ex03_arr1);
    printf("%s\n", ex03_arr2);
    printf("%s\n\n", ex03_arr3);
    free(ex03_arr1);
    free(ex03_arr2);
    free(ex03_arr3);
}*/
