/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:56:21 by tafonso           #+#    #+#             */
/*   Updated: 2026/03/08 01:08:21 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_philos(t_table *table)
{
	int	i;

	i = 0;
	table->start_time = timestamp_ms();
	while (i < table->number_of_philosophers)
	{
		if (init_philo_at(table, i) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	init_philo_at(t_table *table, int i)
{
	table->philos[i].id = i + 1;
	table->philos[i].left_fork = i;
	table->philos[i].right_fork = (i + 1) % table->number_of_philosophers;
	table->philos[i].last_meal = table->start_time;
	table->philos[i].meals_eaten = 0;
	if (pthread_mutex_init(&table->philos[i].meal_mutex, NULL) != 0)
		return (1);
	table->philos[i].table = table;
	return (0);
}

int	init_table(t_table *table)
{
	if (allocate_resources(table) != 0)
		return (1);
	if (init_forks(table) != 0)
	{
		destroy_table(table);
		return (1);
	}
	if (init_mutexes(table) != 0)
	{
		destroy_table(table);
		return (1);
	}
	table->stop = 0;
	if (init_philos(table) != 0)
	{
		destroy_table(table);
		return (1);
	}
	return (0);
}
