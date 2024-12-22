/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharik <acharik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:17:14 by acharik           #+#    #+#             */
/*   Updated: 2024/12/22 21:42:19 by acharik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "../include/philo.h"
#include "../include/philo_utils.h"
#include "../include/init.h"
#include "../include/simulation.h"

short	check_args(int argc, char **argv)
{
	int		i;
	long	num;

	i = 0;
	if (argc < 5 || argc > 6)
		return 1 ;
	while (++i < argc)
	{
		num = ft_atoi(argv[i]);
		if (i == 1 && (num < 1 || num > PHILO_MAX_COUNT))
			return (1);
		else if (i == 5 && (num < 0 || num > INT_MAX))
			return (1);
		else if (i != 1 && i != 5 && (num < 1 || num > INT_MAX))
			return (1);
	}
	return 0 ;
}

int	main(int argc, char **argv)
{
	t_philo_stats		philos[PHILO_MAX_COUNT];
	t_mutex		forks[PHILO_MAX_COUNT];
	t_synchronization	synchro;

	if(check_args(argc, argv))
	{
		printf("args error\n");
		return 1;
	}
	init_synchro(&synchro, philos, forks);
	init_forks(&synchro, forks, ft_atoi(argv[1]));
	init_philos(&synchro, philos, forks, argv);
	start_simulation(&synchro, philos[0].philo_count);
	return (0);
}
