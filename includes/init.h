/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharik <acharik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:18:38 by acharik           #+#    #+#             */
/*   Updated: 2024/12/22 00:18:41 by acharik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "philo.h"

void	init_philos(t_engine *en, t_philo *philos, t_mutex *forks, char **argv);
void	init_forks(t_engine *engine, t_mutex *forks, int count);
void	init_engine(t_engine *engine, t_philo *philos, t_mutex *forks);

#endif   
