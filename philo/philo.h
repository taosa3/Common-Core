#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>
#include <limits.h>

typedef struct s_philo
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philo_must_eat;
}		t_philo;

/* Forward declaration for table */
struct s_table;

typedef struct s_philosopher
{
	int                 id;
	int                 left_fork;
	int                 right_fork;
	long                last_meal;
	int                 meals_eaten;
	pthread_t           thread;
	pthread_mutex_t     meal_mutex;
	struct s_table      *table;
}   t_philosopher;

typedef struct s_table
{
	int                 number_of_philosophers;
	int                 time_to_die;
	int                 time_to_eat;
	int                 time_to_sleep;
	int                 number_of_times_each_philo_must_eat;
	pthread_mutex_t     *forks;
	pthread_mutex_t     print_mutex;
	pthread_mutex_t     stop_mutex;
	t_philosopher       *philos;
	long                start_time;
	int                 stop;
}   t_table;


int     parse_args(int ac, char **av, t_table *table);
int     init_table(t_table *table);
int     init_forks(t_table *table);
int     init_philos(t_table *table);
int     init_philo_at(t_table *table, int i);
int     allocate_resources(t_table *table);
int     init_mutexes(t_table *table);
int     init_philo_at(t_table *table, int i);
void    destroy_forks(t_table *table);
void    destroy_philos_mutexes(t_table *table);
int     check_philos(t_table *table);
void    destroy_table(t_table *table);
long    timestamp_ms(void);
void    ms_sleep(long ms);
void    print_action(t_philosopher *philo, const char *action);
void    *philo_routine(void *arg);
void    *monitor_routine(void *arg);
int     get_stop(t_table *table);
void    set_stop(t_table *table);
int     take_forks(t_philosopher *philo);
int     take_forks_even(t_philosopher *philo);
int     take_forks_odd(t_philosopher *philo);
void    put_forks(t_philosopher *philo);
void    philo_eat(t_philosopher *philo);
int     check_one(t_table *table, int i, int *all_ate);
int     check_philos(t_table *table);

#endif