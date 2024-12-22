/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharik <acharik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:18:07 by acharik           #+#    #+#             */
/*   Updated: 2024/12/22 21:23:31 by acharik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_utils.h"

void	init_philos(t_synchronization *synchro, t_philo_stats *philos, t_mutex *forks, char **argv)
{
	int	i;

	i = -1;
	while (++i < ft_atoi(argv[1]))
	{
		philos[i].id = i + 1;
		philos[i].times.die = ft_atoi(argv[2]);
		philos[i].times.eat = ft_atoi(argv[3]);
		philos[i].times.sleep = ft_atoi(argv[4]);
		philos[i].times.last_meal = get_current_time();
		philos[i].times.born_time = get_current_time();
		philos[i].must_eat = -1;
		if (argv[5])
			philos[i].must_eat = ft_atoi(argv[5]);
		philos[i].meals_eaten = 0;
		philos[i].philo_count = ft_atoi(argv[1]);
		philos[i].mutexes.left_fork = &forks[i];
		if (i == 0)
			philos[i].mutexes.right_fork = &forks[philos[i].philo_count - 1];
		else
			philos[i].mutexes.right_fork = &forks[i - 1];
		philos[i].mutexes.write_lock = &synchro->write_lock;
		philos[i].mutexes.meal_lock = &synchro->meal_lock;
	}
}

void	init_forks(t_synchronization *synchro, t_mutex *forks, int number)
{
	int	i;

	i = -1;
	while (++i < number)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			destroy_all(synchro, i);
	}
}

void	init_synchro(t_synchronization *synchro, t_philo_stats *philos, t_mutex *forks)
{
	synchro->forks = forks;
	synchro->philos = philos;
	if (pthread_mutex_init(&synchro->write_lock, NULL) != 0
		|| pthread_mutex_init(&synchro->meal_lock, NULL) != 0)
		destroy_all(synchro, -1);
}
