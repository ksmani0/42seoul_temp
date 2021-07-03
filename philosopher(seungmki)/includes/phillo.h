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

#ifndef PHILLO_H
# define PHILLO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>

# define TRUE		1
# define FALSE		0

typedef struct		s_philo
{
	int				name;
	int				r_fork;
	int				l_fork;
	int				eat_nums;
	int				alive;//살아있으면 TURE, 죽으면 FALSE
	unsigned long	last_eat;//식사 끝난 시간
}					t_philo;

typedef struct		s_info
{
	int				philo_nums;
	long	        time_to_die;
	long        	time_to_eat;
	long        	time_to_sleep;
	int				minimul_eat;
	unsigned long	start_time;//프로그램 시작 시간. 화면에 계속 출력
	t_philo			*philos;
	pthread_t		*thread;
	pthread_mutex_t	*fork;
}					t_info;

int					ft_atoi(const char *s);
int					ft_isdigit(int c);

#endif
