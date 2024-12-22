/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharik <acharik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:18:21 by acharik           #+#    #+#             */
/*   Updated: 2024/12/22 20:08:06 by acharik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

# include "philo.h"

short	all_fat(t_philo_stats *philos);
void	*launcher(void *ptr);
void	philo_actions(t_philo_stats *philo);
void	*update_data(void *ptr);
void    *start_simulation(t_synchronization *engine, int count);

#endif
