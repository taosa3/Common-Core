/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 17:45:10 by tafonso           #+#    #+#             */
/*   Updated: 2025/12/27 21:06:31 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

static int	start_philos(t_table *table)
{
	int		i;

	i = 0;
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
	if (pthread_create(&table->monitor_thread, NULL, monitor_routine, table) != 0)
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
