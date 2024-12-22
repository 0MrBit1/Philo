/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharik <acharik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:18:38 by acharik           #+#    #+#             */
/*   Updated: 2024/12/22 20:20:44 by acharik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "philo_utils.h"

void	init_philos(t_synchronization *synchro, t_philo_stats *philos, t_mutex *forks, char **argv);
void	init_forks(t_synchronization *synchro, t_mutex *forks, int count);
void	init_synchro(t_synchronization *sychro, t_philo_stats *philos, t_mutex *forks);

#endif   
