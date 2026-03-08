/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:54:39 by tafonso           #+#    #+#             */
/*   Updated: 2026/03/08 15:41:26 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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
	{
		table->number_of_times_each_philo_must_eat = ft_atoi_strict(av[5]);
		if (table->number_of_times_each_philo_must_eat <= 0)
			return (write(2, "Invalid arguments\n", 19), 1);
	}
	else
		table->number_of_times_each_philo_must_eat = -1;
	if (table->number_of_philosophers <= 0 || table->time_to_die <= 0
		|| table->time_to_eat <= 0 || table->time_to_sleep <= 0)
	{
		write(2, "Invalid arguments\n", 19);
		return (1);
	}
	return (0);
}

int	allocate_resources(t_table *table)
{
	table->forks = malloc(sizeof(pthread_mutex_t)
			* table->number_of_philosophers);
	if (!table->forks)
		return (1);
	table->philos = malloc(sizeof(t_philosopher)
			* table->number_of_philosophers);
	if (!table->philos)
	{
		free(table->forks);
		return (1);
	}
	return (0);
}

int	init_forks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->number_of_philosophers)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	init_mutexes(t_table *table)
{
	if (pthread_mutex_init(&table->print_mutex, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&table->stop_mutex, NULL) != 0)
		return (1);
	return (0);
}
