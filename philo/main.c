#include "philo.h"

static int	start_philos(t_table *table)
{
	int		i;
	pthread_t	monitor;

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
	if (pthread_create(&monitor, NULL, monitor_routine, table) != 0)
	{
		perror("pthread_create");
		set_stop(table);
		return (1);
	}
	pthread_detach(monitor);
	return (0);
}

static void	join_philos(t_table *table)
{
	int i;

	i = 0;
	while (i < table->number_of_philosophers)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
}

int main(int ac, char **av)
{
	t_table table;

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