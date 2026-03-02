/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 16:08:47 by tafonso           #+#    #+#             */
/*   Updated: 2026/02/28 00:43:29 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*philo_routine(void *arg)
{
	t_philosopher	*philo;
	t_table			*table;

	philo = (t_philosopher *)arg;
	table = philo->table;
	if (table->number_of_philosophers == 1)
	{
		take_forks(philo);
		ms_sleep(table, table->time_to_die);
		pthread_mutex_unlock(&table->forks[philo->left_fork]);
		return (NULL);
	}
	while (get_stop(table) == 0)
	{
		if (verify_eat(philo))
			break ;
		take_forks(philo);
		philo_eat(philo);
		put_forks(philo);
		print_action(philo, "is sleeping");
		ms_sleep(table, table->time_to_sleep);
		print_action(philo, "is thinking");
	}
	return (NULL);
}

void	*monitor_routine(void *arg)
{
	t_table	*table;
	int		check;

	table = (t_table *)arg;
	while (get_stop(table) == 0)
	{
		check = check_philos(table);
		if (check != 0)
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}

int	check_philos(t_table *table)
{
	int	i;
	int	all_ate;

	i = 0;
	all_ate = 1;
	while (i < table->number_of_philosophers)
	{
		if (check_one(table, i, &all_ate) != 0)
			return (1);
		i++;
	}
	if (table->number_of_times_each_philo_must_eat > 0 && all_ate == 1)
	{
		set_stop(table);
		return (2);
	}
	return (0);
}

int	check_one(t_table *table, int i, int *all_ate)
{
	pthread_mutex_lock(&table->philos[i].meal_mutex);
	if ((timestamp_ms() - table->philos[i].last_meal) > table->time_to_die)
	{
		set_stop(table);
		print_action(&table->philos[i], "died");
		pthread_mutex_unlock(&table->philos[i].meal_mutex);
		return (1);
	}
	if (table->number_of_times_each_philo_must_eat > 0 && table->philos[i].meals_eaten < table->number_of_times_each_philo_must_eat)
		*all_ate = 0;
	pthread_mutex_unlock(&table->philos[i].meal_mutex);
	return (0);
}
