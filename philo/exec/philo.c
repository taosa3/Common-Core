/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 17:47:52 by tafonso           #+#    #+#             */
/*   Updated: 2026/02/26 01:09:57 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	take_forks(t_philosopher *philo)
{
	if (philo->table->number_of_philosophers == 1)
	{
		pthread_mutex_lock(&philo->table->forks[philo->left_fork]);
		print_action(philo, "has taken a fork");
		return (0);
	}
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->table->forks[philo->left_fork]);
		pthread_mutex_lock(&philo->table->forks[philo->right_fork]);
		print_action(philo, "has taken a fork");
		print_action(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&philo->table->forks[philo->right_fork]);
		pthread_mutex_lock(&philo->table->forks[philo->left_fork]);
		print_action(philo, "has taken a fork");
		print_action(philo, "has taken a fork");
	}
	return (0);
}

void	put_forks(t_philosopher *philo)
{
	pthread_mutex_unlock(&philo->table->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->table->forks[philo->right_fork]);
}

void	philo_eat(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = timestamp_ms();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_mutex);
	if (get_stop(philo->table) == 1)
		return ;
	print_action(philo, "is eating");
	ms_sleep(philo->table, philo->table->time_to_eat);
}

int	verify_eat(t_philosopher *philo)
{
	t_table	*table;

	table = philo->table;
	if (table->number_of_times_each_philo_must_eat > 0)
	{
		pthread_mutex_lock(&philo->meal_mutex);
		if (philo->meals_eaten >= table->number_of_times_each_philo_must_eat)
		{
			pthread_mutex_unlock(&philo->meal_mutex);
			return (1);
		}
		pthread_mutex_unlock(&philo->meal_mutex);
	}
	return (0);
}
