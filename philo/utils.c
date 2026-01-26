/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:49:33 by tafonso           #+#    #+#             */
/*   Updated: 2026/01/26 21:18:03 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	timestamp_ms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (0);
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000L);
}

void	ms_sleep(t_table *table, long ms)
{
	long	start;

	start = timestamp_ms();
	while (!get_stop(table))
	{
		if ((timestamp_ms() - start) < ms)
			break ;
		usleep(500);
	}
}

static int	ft_atoi_strict(const char *s)
{
	long	val;
	int		i;

	val = 0;
	i = 0;
	if (!s)
		return (-1);
	while (s[i] >= '0' && s[i] <= '9')
	{
		val = val * 10 + (s[i] - '0');
		if (val > INT_MAX)
			return (-1);
		i++;
	}
	if (s[i] != '\0')
		return (-1);
	return ((int)val);
}

int	parse_args(int ac, char **av, t_table *table)
{
	if (ac != 5 && ac != 6)
	{
		write(2, "Usage: ./philo n_philosophers time_to_die time_to_eat ", 55);
		write(2, "time_to_sleep [n_times_each_philo_must_eat]\n", 45);
		return (1);
	}
	table->number_of_philosophers = ft_atoi_strict(av[1]);
	table->time_to_die = ft_atoi_strict(av[2]);
	table->time_to_eat = ft_atoi_strict(av[3]);
	table->time_to_sleep = ft_atoi_strict(av[4]);
	if (ac == 6)
		table->number_of_times_each_philo_must_eat = ft_atoi_strict(av[5]);
	else
		table->number_of_times_each_philo_must_eat = -1;
	if (table->number_of_philosophers <= 0 || table->time_to_die < 0
		|| table->time_to_eat < 0 || table->time_to_sleep < 0)
	{
		write(2, "Invalid arguments\n", 19);
		return (1);
	}
	return (0);
}

void	print_action(t_philosopher *philo, const char *action)
{
	long	ts;
	t_table	*table;

	table = philo->table;
	pthread_mutex_lock(&table->print_mutex);
	ts = timestamp_ms() - table->start_time;
	if (get_stop(table) == 0 || ft_strcmp(action, "died") == 0)
		printf("%ld %d %s\n", ts, philo->id, action);
	pthread_mutex_unlock(&table->print_mutex);
}
