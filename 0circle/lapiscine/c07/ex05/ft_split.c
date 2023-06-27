/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 04:23:46 by sooyang           #+#    #+#             */
/*   Updated: 2022/05/03 19:49:07 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

int	is_charset(char a, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (a == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ac_maker(char *str, char *charset)
{
	int	i;
	int	answer;

	answer = 0;
	i = 0;
	if (!(*charset))
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		while (is_charset(str[i], charset) && str[i] != '\0')
			i++;
		if (!is_charset(str[i], charset) && str[i] != '\0')
		{
			answer++;
			while (!is_charset(str[i], charset) && str[i] != '\0')
				i++;
		}
	}
	return (answer);
}

char	*av_maker(char *str, char *charset)
{
	char	*answer2;
	int		i;

	i = 0;
	while (is_charset(str[i], charset) == 0 && str[i] != '\0')
		i++;
	answer2 = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (is_charset(str[i], charset) == 0 && str[i] != '\0')
	{
		answer2[i] = str[i];
		i++;
	}
	answer2[i] = '\0';
	return (answer2);
}

char	**ft_split(char *str, char *charset)
{
	char	**answer;
	int		i;
	int		ac;

	ac = ac_maker(str, charset);
	answer = (char **)malloc(sizeof(char *) * (ac + 1));
	if (!(answer))
		return (0);
	i = 0;
	while (*str)
	{
		while (is_charset(*str, charset) == 1 && *str)
			str++;
		if (is_charset(*str, charset) == 0 && *str)
		{
			answer[i] = av_maker(str, charset);
			while (is_charset(*str, charset) == 0 && *str)
				str++;
			i++;
		}
	}
	answer[i] = 0;
	return (answer);
}

/*
#include	<stdio.h>

int	main(void)
{
	printf("-------ex05-------\n\n");
    char **ex05_split1;
    char **ex05_split2;
    char **ex05_split3;
	char *ex05_str1 = "hello my name is hunpark!";
	char *ex05_str2 = "good@day!cat#dog!vim12!";
	char *ex05_str3 = "i1my2me3mine4you5your6you7yours";
	ex05_split1 = ft_split(ex05_str1, "");
    ex05_split2 = ft_split(ex05_str2, "!@#");
    ex05_split3 = ft_split(ex05_str3, "1234567");
    printf("---test1---\n");
	for (int j = 0; j < 1; j++)
	{
		printf("%s\n", ex05_split1[j]);
	}
    printf("\n\n");
    printf("---test2---\n");
    for (int j = 0; j < 5; j++)
	{
		printf("%s\n", ex05_split2[j]);
	}
    printf("\n\n");
    printf("---test3---\n");
    for (int j = 0; j < 8; j++)
	{
		printf("%s\n", ex05_split3[j]);
	}
    printf("\n\n");
	free(ex05_split1);
    free(ex05_split3);
    free(ex05_split2);
}*/
