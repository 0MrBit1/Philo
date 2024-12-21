/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharik <acharik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:18:21 by acharik           #+#    #+#             */
/*   Updated: 2024/12/22 00:18:23 by acharik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

# include "philo.h"

bool	is_all_eat(t_philo *philos);
void	*obsorver(void *ptr);
void	philo_routine(t_philo *philo);
void	*start_simulation(void *ptr);
void	launcher(t_engine *engine, int count);

#endif   /* SIMULATION_H */
