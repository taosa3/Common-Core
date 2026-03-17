/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 17:45:10 by tafonso           #+#    #+#             */
/*   Updated: 2026/03/17 15:52:46 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_start_time(t_table *table)
{
	int	i;

	i = 0;
	table->start_time = timestamp_ms();
	while (i < table->number_of_philosophers)
	{
		table->philos[i].last_meal = table->start_time;
		i++;
	}
	return ;
}

static int	start_philos(t_table *table)
{
	int		i;

	i = 0;
	pthread_mutex_lock(&table->start_mutex);
	while (i < table->number_of_philosophers)
	{
		if (pthread_create(&table->philos[i].thread, NULL, philo_routine,
				&table->philos[i]) != 0)
		{
			perror("pthread_create");
			set_stop(table);
			return (1);
		}
		i++;
	}
	init_start_time(table);
	pthread_mutex_unlock(&table->start_mutex);
	if (pthread_create(&table->monitor_thread, NULL, monitor_routine,
			table) != 0)
	{
		perror("pthread_create");
		set_stop(table);
		return (1);
	}
	return (0);
}

static void	join_philos(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->number_of_philosophers)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
	pthread_join(table->monitor_thread, NULL);
}

int	main(int ac, char **av)
{
	t_table	table;

	if (parse_args(ac, av, &table) != 0)
		return (1);
	if (init_table(&table) != 0)
		return (1);
	if (start_philos(&table) != 0)
	{
		destroy_table(&table);
		return (1);
	}
	join_philos(&table);
	destroy_table(&table);
	return (0);
}
