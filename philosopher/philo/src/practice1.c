/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 01:40:27 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/08 16:28:33 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pthread.h"
#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"

pthread_mutex_t mtx;
int item = 0;

// 함수 만들 때 꼭 함수포인터로 만들 수 있게 포인터로 명시하기
void *repeat(void *data)
{
	int i = -1;
	while (++i < 100000000)
	{
		pthread_mutex_lock(&mtx);
		item++;
		pthread_mutex_unlock(&mtx);
	}
	return (void *)NULL;
}

int main()
{
	int i;
	pthread_t p1, p2;

	pthread_mutex_init(&mtx, NULL);
	if (pthread_create(&p1, NULL, repeat, NULL) != 0)
		return 1;
	if (pthread_create(&p1, NULL, repeat, NULL) != 0)
		return 2;
	printf("item num: %d\n", item);
	if (pthread_join(p1, NULL) != 0)
		return 3;
	printf("item num: %d\n", item);
	if (pthread_join(p2, NULL) != 0)
		return 4;
	printf("item num: %d\n", item);
	pthread_mutex_destroy(&mtx);
	return 0;
}
