/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharik <acharik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:17:57 by acharik           #+#    #+#             */
/*   Updated: 2024/12/22 21:40:37 by acharik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_utils.h"

short	all_fat(t_philo_stats *philos)
{
	int		finished;
	int		i;

	i = -1;
	finished = 0;
	if (philos[0].must_eat == -1)
		return (0);
	while (++i < philos[0].philo_count)
	{
		pthread_mutex_lock(philos->mutexes.meal_lock);
		if (philos[i].meals_eaten >= philos[i].must_eat)
			++finished;
		pthread_mutex_unlock(philos->mutexes.meal_lock);
	}
	if (finished == philos[0].philo_count)
	{
		pthread_mutex_lock(philos->mutexes.write_lock);
		return (1);
	}
	return (0);
}

void	*monitor_thread(void *ptr)
{
	t_philo_stats	*philos;
	int		i;

	philos = (t_philo_stats *)ptr;
	while (1)
	{
		i = -1;
		while (++i < philos[0].philo_count)
		{
			pthread_mutex_lock(philos->mutexes.meal_lock);
			if (get_current_time() - philos[i].times.last_meal
				> philos[i].times.die)
			{
				pthread_mutex_unlock(philos->mutexes.meal_lock);
				print_action(&philos[i], "state=died");
				pthread_mutex_lock(philos->mutexes.write_lock);
				return (NULL);
			}
			pthread_mutex_unlock(philos->mutexes.meal_lock);
		}
		if (all_fat(philos))
			return (NULL);
	}
	return (NULL);
}

void	philo_actions(t_philo_stats *philo)
{
	pthread_mutex_lock(philo->mutexes.left_fork);
	print_action(philo, " state=has taken a fork");
	pthread_mutex_lock(philo->mutexes.right_fork);
	print_action(philo, " state=has taken a fork");
	pthread_mutex_lock(philo->mutexes.meal_lock);
	print_action(philo, " state=is eating");
	philo->times.last_meal = get_current_time();
	philo->meals_eaten += 1;
	pthread_mutex_unlock(philo->mutexes.meal_lock);
	ft_usleep(philo->times.eat);
	pthread_mutex_unlock(philo->mutexes.left_fork);
	pthread_mutex_unlock(philo->mutexes.right_fork);
	print_action(philo, " state=is sleeping");
	ft_usleep(philo->times.sleep);
	print_action(philo, " state=is thinking");
}

void	*start_threads(void *ptr)
{
	t_philo_stats	*philo;

	philo = (t_philo_stats *)ptr;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	pthread_mutex_lock(philo->mutexes.meal_lock);
	philo->times.born_time = get_current_time();
	philo->times.last_meal = get_current_time();
	pthread_mutex_unlock(philo->mutexes.meal_lock);
	while (1)
		philo_actions(philo);
	return (NULL);
}

void	start_simulation(t_synchronization *synchro, int count)
{
	t_id	monitor_id;
	int		i;

	i = -1;
	pthread_create(&monitor_id, NULL, &monitor_thread, synchro->philos);
	
	while (++i < count)
	{
		pthread_create(&synchro->philos[i].thread_id, NULL,
				start_threads, &synchro->philos[i]);
			
	}
	i = -1;
 	pthread_join(monitor_id, NULL);
	while (++i < count)
		pthread_detach(synchro->philos[i].thread_id) ;
}
