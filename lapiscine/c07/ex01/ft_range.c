/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:09:07 by sooyang           #+#    #+#             */
/*   Updated: 2022/05/03 19:48:07 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

int	*ft_range(int min, int max)
{
	int			i;
	int			*range;
	long long	size;

	size = max - min;
	if (size <= 0)
		return (0);
	range = (int *)malloc(sizeof(int) * size);
	if (!(range))
		return (0);
	i = -1;
	while (++i < size)
		range[i] = min + i;
	return (range);
}

/*
#include	<stdio.h>
int	main(void)
{
	printf("-------ex01-------\n\n");
    int *ex01_arr1;
    int *ex01_arr2;
    int *ex01_arr3;
    printf("min : 1, max : 10\n");
    ex01_arr1 = ft_range(1, 10);
    for(int i = 0; i < 9; i++)
    {
        printf("%d ", ex01_arr1[i]);
    }
    printf("\n\n");
    printf("min : 10, max : 1\n");
    ex01_arr2 = ft_range(1, 0);
    printf("%p ", ex01_arr2);
    printf("\n\n");
    printf("min : -25, max : -10\n");
    ex01_arr3 = ft_range(-25, -10);
    for(int i = 0; i < 15; i++)
    {
        printf("%d ", ex01_arr3[i]);
    }
    printf("\n\n");
    free(ex01_arr1);
    free(ex01_arr2);
    free(ex01_arr3);
}*/
