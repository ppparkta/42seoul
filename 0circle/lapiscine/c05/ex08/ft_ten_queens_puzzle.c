/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:44:46 by sooyang           #+#    #+#             */
/*   Updated: 2022/05/01 15:43:50 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	print_chess(int *arr)
{
	int		i;
	char	an;

	i = 0;
	while (i < 10)
	{
		an = arr[i] + '0';
		write(1, &an, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	check(int col, int *arr)
{
	int	j;

	j = 0;
	while (j < col)
	{
		if (arr[j] == arr[col])
			return (1);
		if ((ft_abs(j - col) == ft_abs(arr[j] - arr[col])))
			return (1);
		j++;
	}
	return (0);
}

void	dfs(int col, int *arr, int *answer)
{
	int	i;

	i = 0;
	if (col == 10)
	{
		print_chess(arr);
		*answer = *answer + 1;
		return ;
	}
	else
	{
		while (i < 10)
		{
			arr[col] = i;
			if (check(col, arr) == 0)
				dfs(col + 1, arr, answer);
			i++;
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	arr[10];
	int	i;
	int	count;
	int	*answer;

	i = 0;
	answer = &count;
	count = 0;
	dfs(0, arr, answer);
	return (*answer);
}

/*
#include <stdio.h>
int main(void)
{
	printf("%d", ft_ten_queens_puzzle());
}*/
