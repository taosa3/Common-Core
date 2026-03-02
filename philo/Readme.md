*This project has been created as part of the 42 curriculum by tafonso

# Philosophers Project

## Description
The **Philosophers** project is a concurrency exercise inspired by the classic [Dining Philosophers problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem). Its goal is to simulate philosophers sitting around a table, alternating between thinking, eating, and sleeping, while sharing a limited number of forks (resources) without causing deadlocks or starvation.  

This project allows you to gain hands-on experience with:
- Multithreading using POSIX threads (`pthread` library).
- Synchronization mechanisms such as mutexes.
- Managing shared resources safely in a concurrent environment.
- Writing precise and robust C programs following the Norminette style guide.

## Instructions

### Compilation
To compile the project, run the following command in the root directory:

```bash
make
```

This will produce an executable named philo.

## Execution

The program takes the following arguments:

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

number_of_philosophers – total philosophers sitting at the table.

time_to_die – time in milliseconds a philosopher can stay without eating before dying.

time_to_eat – time in milliseconds a philosopher spends eating.

time_to_sleep – time in milliseconds a philosopher spends sleeping.

[number_of_times_each_philosopher_must_eat] – optional; if all philosophers eat at least this many times, the simulation stops.

Example:
```bash
./philo 5 800 200 200
```
### Clean Up

To remove compiled files:
```bash
make fclean
```
## Resources

Classic references related to the Dining Philosophers problem:

Wikipedia: Dining Philosophers Problem

POSIX Threads documentation: [pthread(7)](https://man7.org/linux/man-pages/man7/pthreads.7.html)

## AI Usage

AI was used to:

Generate initial README structure and wording.

Clarify explanations of concurrency concepts.
No AI was used to implement the core logic of the project; all code and algorithms were written and tested manually.

## Additional Notes

The program is written in C and follows the 42 Norminette coding style.

Proper handling of edge cases, such as a single philosopher or philosophers dying simultaneously, has been implemented.

The project encourages careful planning of thread synchronization to avoid deadlocks and race conditions.