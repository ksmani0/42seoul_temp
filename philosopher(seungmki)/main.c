/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phillo.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 20:13:07 by seungmki          #+#    #+#             */
/*   Updated: 2021/07/01 20:16:24 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phillo.h"

int				error_exit(char *str)
{
	printf("%s", str);
	return (0);
}

unsigned long	get_ms_time(void)
{
	struct timeval	tmp;
	unsigned long	milisecond;

	getimeofday(&tmp, NULL);
	milisecond = tmp.tv_sec * 1000 + tmp.tv_usec / 1000;
	return (milisecond);
}

int				fill_info(int ac, char **av, t_info *info)
{
	if ((!ft_isdigit(av[1]) || !ft_isdigit(av[2]) || !ft_isdigit(av[3])
	|| !ft_isdigit(av[4]) == 0) || (ac == 6 && !ft_isdigit(av[5])))
		return (0);
	info->philo_nums = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	info->minimul_eat = -1;
	if (ac == 6)
		info->minimul_eat = ft_atoi(av[5]);
	if ((info->philo_nums < 0 || info->time_to_die < 0 ||
	info->time_to_eat < 0 || info->time_to_sleep < 0) ||
	(ac == 6 && info->minimul_eat < 0))
		return (0);
	info->start_time = get_ms_time();
	info->philos = 0;
	info->thread = 0;
	info->fork = 0;
	return (1);
}

int				mutex_n_thread_malloc(t_info *info)
{
	info->philos = (t_philo*)malloc(sizeof(t_philo) * info->philo_nums);
	if (info->philos == 0)
		return (free_info(info));
	info->thread = (pthread_t*)malloc(sizeof(pthread_t)
				* info->philo_nums);
	if (info->thread == 0)
		return (free_info(info));
	info->fork = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t)
				* info->philo_nums);
	if (info->thread == 0)
		return (free_info(info));
	return (1);
}

int				main(int ac, char *av[])
{
	t_info info;

	if (ac < 4 || ac > 6)
		return (error_exit("\e[31mError: wrong number of \
				arguments!\e[0m\n"));
	if (fill_info(ac, av, &info) == 0)
		return (error_exit("\e[31mError: invalid arguments!\e[0m\n"));
	if (mutex_n_thread_malloc(&info) != 0)
		return (error_exit("\e[31mError: out of memory \
			allocation!\e[0m\n"));
	philos_thread_init(&info);
	free_info();
	return (0);
}