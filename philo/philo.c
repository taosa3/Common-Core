#include "philo.h"

int init_forks(t_table *table)
{
    int i;

    i = 0;
    while (i < table->number_of_philosophers)
    {
        if (pthread_mutex_init(&table->forks[i], NULL) != 0)
        {
            /* destroy previously initialized forks */
            while (i > 0)
            {
                i--;
                pthread_mutex_destroy(&table->forks[i]);
            }
            return (1);
        }
        i++;
    }
    return (0);
}

int init_philos(t_table *table)
{
    int i;

    i = 0;
    while (i < table->number_of_philosophers)
    {
        if (init_philo_at(table, i) != 0)
            return (1);
        i++;
    }
    return (0);
}

int init_philo_at(t_table *table, int i)
{
    table->philos[i].id = i + 1;
    table->philos[i].left_fork = i;
    table->philos[i].right_fork = (i + 1) % table->number_of_philosophers;
    table->philos[i].last_meal = table->start_time;
    table->philos[i].meals_eaten = 0;
    if (pthread_mutex_init(&table->philos[i].meal_mutex, NULL) != 0)
    {
        /* destroy previously initialized meal mutexes */
        while (i > 0)
        {
            i--;
            pthread_mutex_destroy(&table->philos[i].meal_mutex);
        }
        return (1);
    }
    table->philos[i].table = table;
    return (0);
}

int allocate_resources(t_table *table)
{
    table->forks = malloc(sizeof(pthread_mutex_t) * table->number_of_philosophers);
    if (!table->forks)
        return (1);
    table->philos = malloc(sizeof(t_philosopher) * table->number_of_philosophers);
    if (!table->philos)
    {
        free(table->forks);
        return (1);
    }
    return (0);
}

int init_table(t_table *table)
{
    if (allocate_resources(table) != 0)
        return (1);
    if (init_forks(table) != 0)
    {
        free(table->forks);
        free(table->philos);
        return (1);
    }
    if (init_mutexes(table) != 0)
    {
        destroy_table(table);
        return (1);
    }
    table->stop = 0;
    table->start_time = timestamp_ms();
    if (init_philos(table) != 0)
    {
        destroy_table(table);
        return (1);
    }
    return (0);
}

void destroy_table(t_table *table)
{
    if (!table)
        return;
    destroy_forks(table);
    destroy_philos_mutexes(table);
    pthread_mutex_destroy(&table->print_mutex);
    pthread_mutex_destroy(&table->stop_mutex);
    free(table->forks);
    free(table->philos);
}

void destroy_forks(t_table *table)
{
    int i;

    if (!table || !table->forks)
        return;
    i = 0;
    while (i < table->number_of_philosophers)
    {
        pthread_mutex_destroy(&table->forks[i]);
        i++;
    }
}

void destroy_philos_mutexes(t_table *table)
{
    int i;

    if (!table || !table->philos)
        return;
    i = 0;
    while (i < table->number_of_philosophers)
    {
        pthread_mutex_destroy(&table->philos[i].meal_mutex);
        i++;
    }
}

int init_mutexes(t_table *table)
{
    if (pthread_mutex_init(&table->print_mutex, NULL) != 0)
        return (1);
    if (pthread_mutex_init(&table->stop_mutex, NULL) != 0)
    {
        pthread_mutex_destroy(&table->print_mutex);
        return (1);
    }
    return (0);
}

int get_stop(t_table *table)
{
    int val;

    pthread_mutex_lock(&table->stop_mutex);
    val = table->stop;
    pthread_mutex_unlock(&table->stop_mutex);
    return (val);
}

void set_stop(t_table *table)
{
    pthread_mutex_lock(&table->stop_mutex);
    table->stop = 1;
    pthread_mutex_unlock(&table->stop_mutex);
}

int take_forks(t_philosopher *philo)
{
    if (philo->table->number_of_philosophers == 1)
    {
        pthread_mutex_lock(&philo->table->forks[philo->left_fork]);
        print_action(philo, "has taken a fork");
        return (0);
    }
    if ((philo->id % 2) == 0)
        return (take_forks_even(philo));
    return (take_forks_odd(philo));
}

int take_forks_even(t_philosopher *philo)
{
    t_table *table;

    table = philo->table;
    pthread_mutex_lock(&table->forks[philo->left_fork]);
    print_action(philo, "has taken a fork");
    pthread_mutex_lock(&table->forks[philo->right_fork]);
    print_action(philo, "has taken a fork");
    return (0);
}

int take_forks_odd(t_philosopher *philo)
{
    t_table *table;

    table = philo->table;
    pthread_mutex_lock(&table->forks[philo->right_fork]);
    print_action(philo, "has taken a fork");
    pthread_mutex_lock(&table->forks[philo->left_fork]);
    print_action(philo, "has taken a fork");
    return (0);
}
void put_forks(t_philosopher *philo)
{
    t_table *table;

    table = philo->table;
    pthread_mutex_unlock(&table->forks[philo->left_fork]);
    pthread_mutex_unlock(&table->forks[philo->right_fork]);
}

void philo_eat(t_philosopher *philo)
{
    t_table *table;

    table = philo->table;
    pthread_mutex_lock(&philo->meal_mutex);
    philo->last_meal = timestamp_ms();
    pthread_mutex_unlock(&philo->meal_mutex);
    print_action(philo, "is eating");
    ms_sleep(table->time_to_eat);
    pthread_mutex_lock(&philo->meal_mutex);
    philo->meals_eaten = philo->meals_eaten + 1;
    pthread_mutex_unlock(&philo->meal_mutex);
}

void *philo_routine(void *arg)
{
    t_philosopher *philo;
    t_table *table;

    philo = (t_philosopher *)arg;
    table = philo->table;
    if (table->number_of_philosophers == 1)
    {
        take_forks(philo);
        ms_sleep(table->time_to_die);
        pthread_mutex_unlock(&table->forks[philo->left_fork]);
        return (NULL);
    }
    while (get_stop(table) == 0)
    {
        take_forks(philo);
        philo_eat(philo);
        put_forks(philo);
        print_action(philo, "is sleeping");
        ms_sleep(table->time_to_sleep);
        print_action(philo, "is thinking");
        usleep(100);
    }
    return (NULL);
}

void *monitor_routine(void *arg)
{
    t_table *table;
    int check;

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

int check_philos(t_table *table)
{
    int i;
    int all_ate;

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

int check_one(t_table *table, int i, int *all_ate)
{
    pthread_mutex_lock(&table->philos[i].meal_mutex);
    if ((timestamp_ms() - table->philos[i].last_meal) > table->time_to_die)
    {
        print_action(&table->philos[i], "died");
        pthread_mutex_unlock(&table->philos[i].meal_mutex);
        set_stop(table);
        return (1);
    }
    if (table->number_of_times_each_philo_must_eat > 0 && table->philos[i].meals_eaten < table->number_of_times_each_philo_must_eat)
        *all_ate = 0;
    pthread_mutex_unlock(&table->philos[i].meal_mutex);
    return (0);
}
