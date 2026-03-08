/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 16:04:37 by tafonso           #+#    #+#             */
/*   Updated: 2026/03/08 01:30:50 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	destroy_table(t_table *table)
{
	if (!table)
		return ;
	destroy_forks(table);
	destroy_philos_mutexes(table);
	pthread_mutex_destroy(&table->print_mutex);
	pthread_mutex_destroy(&table->stop_mutex);
	free(table->forks);
	free(table->philos);
}

void	destroy_forks(t_table *table)
{
	int	i;

	if (!table || !table->forks)
		return ;
	i = 0;
	while (i < table->number_of_philosophers)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
}

void	destroy_philos_mutexes(t_table *table)
{
	int	i;

	if (!table || !table->philos)
		return ;
	i = 0;
	while (i < table->number_of_philosophers)
	{
		pthread_mutex_destroy(&table->philos[i].meal_mutex);
		i++;
	}
}

int	get_stop(t_table *table)
{
	int	val;

	pthread_mutex_lock(&table->stop_mutex);
	val = table->stop;
	pthread_mutex_unlock(&table->stop_mutex);
	return (val);
}

void	set_stop(t_table *table)
{
	pthread_mutex_lock(&table->stop_mutex);
	table->stop = 1;
	pthread_mutex_unlock(&table->stop_mutex);
}
