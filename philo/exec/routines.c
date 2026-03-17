/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 16:08:47 by tafonso           #+#    #+#             */
/*   Updated: 2026/03/17 16:07:07 by tafonso          ###   ########.fr       */
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
	start_routine(table, philo);
	if (table->number_of_philosophers == 1)
		return (single_philo(philo), NULL);
	while (get_stop(table) == 0)
	{
		if (verify_eat(philo))
			break ;
		take_forks(philo);
		if (get_stop(table))
			return (put_forks(philo), NULL);
		philo_eat(philo);
		put_forks(philo);
		print_action(philo, "is sleeping");
		ms_sleep(table, table->time_to_sleep);
		print_action(philo, "is thinking");
		if (table->number_of_philosophers % 2 == 1)
			usleep(1000);
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
		usleep(200);
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
		pthread_mutex_unlock(&table->philos[i].meal_mutex);
		set_stop(table);
		print_action(&(table->philos[i]), "died");
		return (1);
	}
	if (table->number_of_times_each_philo_must_eat > 0
		&& table->philos[i].meals_eaten
		< table->number_of_times_each_philo_must_eat)
		*all_ate = 0;
	pthread_mutex_unlock(&table->philos[i].meal_mutex);
	return (0);
}
