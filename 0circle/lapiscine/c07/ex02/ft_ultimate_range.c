/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:02:30 by sooyang           #+#    #+#             */
/*   Updated: 2022/05/03 19:48:34 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int			i;
	long long	size;

	size = max - min;
	if (size <= 0)
	{
		*range = 0;
		return (0);
	}
	*range = malloc(sizeof(int) * size);
	if (!(*range))
		return (-1);
	i = -1;
	while (++i < size)
		(*range)[i] = min + i;
	return (size);
}

/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	 printf("-------ex02-------\n\n");
    int	*ex02_arr1;
    int	*ex02_arr2;
    int	*ex02_arr3;
	int size1 = ft_ultimate_range(&ex02_arr1, 5, 10);
    int size2 = ft_ultimate_range(&ex02_arr2, -4, 10);
    int size3 = ft_ultimate_range(&ex02_arr3, 10, 1);

    printf("min : 5, max : 10, size : %d\n", size1);
	for (int i = 0; i < size1 ; i++)
	{
		printf("%d ", ex02_arr1[i]);
	}
    printf("\n\n");
    printf("min : -4, max : 10, size : %d\n", size2);
	for (int i = 0; i < size2 ; i++)
	{
		printf("%d ", ex02_arr2[i]);
	}
    printf("\n\n");
    printf("min : 10, max : 1, size : %d\n", size3);
	printf("%p ", ex02_arr3);
    printf("\n\n");
    free(ex02_arr1);
    free(ex02_arr2);
    free(ex02_arr3);
}*/
