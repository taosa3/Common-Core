/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:49:33 by tafonso           #+#    #+#             */
/*   Updated: 2026/03/17 15:38:30 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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
		if ((timestamp_ms() - start) >= ms)
			break ;
		usleep(1000);
	}
}

int	ft_atoi_strict(const char *s)
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

void	print_action(t_philosopher *philo, const char *action)
{
	// long	ts;
	t_table	*table;

	table = philo->table;
	pthread_mutex_lock(&table->print_mutex);
	// ts = timestamp_ms() - table->start_time;
	if (get_stop(table) == 0 || ft_strcmp(action, "died") == 0)
		printf("%ld %d %s\n", timestamp_ms() - table->start_time, philo->id, action);
	pthread_mutex_unlock(&table->print_mutex);
}
