/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 16:08:47 by tafonso           #+#    #+#             */
/*   Updated: 2026/03/08 19:04:22 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	single_philo(t_philosopher *philo)
{
	take_forks(philo);
	while (get_stop(philo->table) == 0)
		usleep(500);
	pthread_mutex_unlock(&philo->table->forks[philo->left_fork]);
}

void	*philo_routine(void *arg)
{
	t_philosopher	*philo;
	t_table			*table;

	philo = (t_philosopher *)arg;
	table = philo->table;
	if (philo->id % 2 == 0)
		usleep(table->time_to_eat * 200);
	if (table->number_of_philosophers == 1)
		return (single_philo(philo), NULL);
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
		if (table->time_to_eat > table->time_to_sleep)
			ms_sleep(table, (table->time_to_eat - table->time_to_sleep) / 2);
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
		usleep(500);
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
	long	death_time;

	death_time = 0;
	pthread_mutex_lock(&table->philos[i].meal_mutex);
	if ((timestamp_ms() - table->philos[i].last_meal) > table->time_to_die)
	{
		death_time = timestamp_ms() - table->start_time;
		pthread_mutex_unlock(&table->philos[i].meal_mutex);
		set_stop(table);
		pthread_mutex_lock(&table->print_mutex);
		printf("%ld %d died\n", death_time, table->philos[i].id);
		pthread_mutex_unlock(&table->print_mutex);
		return (1);
	}
	if (table->number_of_times_each_philo_must_eat > 0
		&& table->philos[i].meals_eaten
		< table->number_of_times_each_philo_must_eat)
		*all_ate = 0;
	pthread_mutex_unlock(&table->philos[i].meal_mutex);
	return (0);
}
