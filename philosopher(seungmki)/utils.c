/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phillo.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:13:07 by seungmki          #+#    #+#             */
/*   Updated: 2021/04/16 20:16:24 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phillo.h"

int		free_info(t_info *info)
{
	if (info->philos == 0)
		return (0);
	free(info->philos);
	if (info->thread == 0)
		return (0);
	free(info->thread);
	return (0);
}

void	daed_or_avlie(void *ptr)
{
	t_info *info;

	info = (t_info)ptr;
	while (TRUE)
	{
		//
	}
}

void	do_routine(void *ptr)
{
	t_info *info;
	pthread_t monitor;//죽은 철학자가 있는지 검사하는 애

	info = (t_info*)ptr;//여기서 전달된 스레드를 알아보려면 역시 t_info를 t_philo가 포함해야 함
	pthread_create(&monitor, NULL, dead_or_alive, info);
	while (TRUE)
	{
		//
	}
	pthread_join(monitor, NULL);
	return (NULL);
}

void	philos_thread_init(t_info *info)
{
	int i;

	i = 0;
	while (i < info->philo_nums)
	{
		info->philos[i].name = i + 1;
		info->philos[i].r_fork = i;//오른쪽 포크는 색인대로
		if (i == 0)//왼쪽 포크는 현재 철학자 전 순서의 철학자 색인 대입
			info->philos[i].l_fork = info->philo_nums - 1;
		else//그럼 0번 철학자는 n-1번 색인이 왼쪽 포크가 된다
			info->philos[i].l_fork = i - 1;
		info->philos[i].eat_nums = 0;
		info->philos[i].alive = TRUE;
		info->philos[i].last_eat = get_ms_time();//처음에는 스레드 생성 시간을 대입
		pthread_mutex_init(&info->fork[i], NULL);//뮤텍스 초기화
		pthread_create(&info->thread[i], NULL, do_routine, info);//스레드 생성
		pthread_detach(info->thread[i]);//생성된 스레드가 종료되면 자동으로 자원 해제되게 한다. detach 옵션 붙기 전에 스레드가 죽어도 아래 join()이 해제 담당
		pthread_join(info->thread[i], NULL);//스레드가 종료되면 자원 해제. do_routine() 반환값이 없으면 null
		usleep(20);
		i++;
	}
}