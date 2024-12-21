

#ifndef UTILS_H
# define UTILS_H

# include "philo.h"

void	error_message(char *text, int signal);
void	destroy_all(t_engine *engine, char *str, int count, int signal);
void	print_action(t_philo *philo, char *action);
size_t	get_current_time(void);
void	ft_usleep(size_t mls);
size_t	ft_strlen(const char *str);
long	ft_atoi(const char *str);

#endif   /* UTILS_H */
