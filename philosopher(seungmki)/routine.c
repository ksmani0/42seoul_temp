/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:13:07 by seungmki          #+#    #+#             */
/*   Updated: 2021/04/16 20:16:24 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dead_or_alive(void *ptr)
{//여기서 현재 철학자 스레드의 생존 여부 검사
	t_info			*info;
	t_philo 		*philo;

	philo = (t_philo*)ptr;
	info = philo->info;
	while (TRUE)
	{
		if (philo->eat_nums == philo->info->minimul_eat)
			break ;//최소 식사에 도달하면 상태 검사 필요 없음
		if (get_ms_time() - philo->last_eat > info->time_to_die)
		{
			if (info->all_alive == TRUE)
				info->all_alive = FALSE;//여기서 철학자 죽음 표시. 다른 모니터 스레드도 감지 가능
			pthread_mutex_unlock(&info->fork[philo->r_fork]);//철학자가 1명뿐이면 pickup_forks_to_eat()에서 r_fork 잡고 lock으로
			print_state(philo, DIE);//l_fork 못 잡음. 두 포크 색인이 같고 이미 r_fork에서 lock 걸었으니까. 그래서 죽이기 전 여기서 푼다
			return (NULL);//철학자 죽음 기록하고 탈출. 한 스레드라도 죽어 탈출하면 다른 스레드 다 죽어서 끝
		}
		usleep(20);//잠깐씩 쉬며 검사
	}
	return (NULL);
}

int    print_state(t_philo *philo, int state)
{//이 함수에서 잡아야 dead_or_alive()에서 죽음을 기록해도 먹기, 자기, 생각하기가 출력되는 걸 막을 수 있다
	unsigned long ms;

	pthread_mutex_lock(&(philo->info->print_state));//출력에도 뮤텍스를 걸어 동시 출력 방지
	ms = get_ms_time();
	if (state != DIE && ms - philo->last_eat > philo->info->time_to_die)
	{
		pthread_mutex_unlock(&(philo->info->print_state));
		return (0);//죽은 철학자가 있거나 현재 스레드 철학자가 기아면 탈출
	}
	ms -= philo->info->start_time;
	printf("\e[33m%lums \e[96m%d \e[39m", ms, philo->name);
	if (state == 2)
		printf("\e[32mhas taken a fork\e[39m\n");
	else if (state == 3)
		printf("\e[33mis eating\e[39m\n");
	else if (state == 4)
		printf("\e[96mis sleeping\e[39m\n");
	else if (state == 5)
		printf("\e[0;35mis thinking\e[39m\n");
	else if (state == 6)
		printf("\033[0;31mdied\e[39m\n");
	pthread_mutex_unlock(&(philo->info->print_state));
	return (1);
}

void	philo_eat_or_sleep(unsigned long time)
{
	unsigned long end;

	end = get_ms_time() + time;
	while (end > get_ms_time())
		usleep(100);
}

void	pickup_forks_to_eat(t_philo *philo)
{
	t_info *info;

	info = philo->info;//들어온 철학자의 색인과 전 색인의 포크를 든다. 즉 해당 뮤텍스를 건다
	pthread_mutex_lock(&info->fork[philo->r_fork]);//데드락 맞는 방법2
	print_state(philo, FORK);
	pthread_mutex_lock(&info->fork[philo->l_fork]);//연속으로 포크 잡아 다른 철학자가 l_fork를 못잡게 함
	print_state(philo, FORK);
	print_state(philo, EAT);
	philo_eat_or_sleep(info->time_to_eat);//먹는 시간동안 usleep
	if (philo->info->all_alive == FALSE)
		philo->last_eat = get_ms_time();//다 먹은 시간 기록
	philo->eat_nums++;//먹은 횟수 기록
	pthread_mutex_unlock(&info->fork[philo->r_fork]);
	pthread_mutex_unlock(&info->fork[philo->l_fork]);
}

void	*do_routine(void *ptr)
{//각 철학자 스레드가 여기로 들어옴
	t_info		*info;
	t_philo		*philo;
	pthread_t	monitor;//죽은 철학자가 있는지 검사하는 애

	philo = (t_philo*)ptr;//여기서 전달된 스레드를 알아보려면 역시 t_info를 t_philo가 포함해야 함
	info = philo->info;
	pthread_create(&monitor, NULL, dead_or_alive, philo);//감시 스레드 생성. 얘가 죽음이나 기아 감시
	while (TRUE)
	{
		pickup_forks_to_eat(philo);
		if (info->minimul_eat != -1 && info->minimul_eat == philo->eat_nums)
			break;//최소 식사수에 도달하면 모니터링 끝내고 모니터링 스레드는 해제된다
		if (print_state(philo, SLEEP) == 0)//먹고 나면 잘 시간
			break ;
		philo_eat_or_sleep(info->time_to_sleep);//자는 시간 동안 usleep
		if (print_state(philo, THINK) == 0)//일정 시간 자고 일어나 생각. state는 항상 현 시간도 같이 출력
			break ;
	}
	pthread_join(monitor, NULL);//모니터 스레드 종료되면 리소스 해제
	return (NULL);
}