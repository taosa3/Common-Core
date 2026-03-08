<div align="center">

# 42 Common Core — tafonso

*A collection of projects completed as part of the 42 Lisboa curriculum.*

[![Profile](https://img.shields.io/badge/42%20Lisboa-tafonso-000000?style=for-the-badge&logo=42&logoColor=white)](https://github.com/taosa3)

</div>

---

## Projects

| # | Project | Description | Grade |
|---|---------|-------------|-------|
| 01 | [**Libft**](#-libft) | C standard library reimplementation | ![100](https://img.shields.io/badge/100%2F100-brightgreen?style=flat-square) |
| 02 | [**ft_printf**](#-ft_printf) | Variadic printf reimplementation | ![100](https://img.shields.io/badge/100%2F100-brightgreen?style=flat-square) |
| 03 | [**get_next_line**](#-get_next_line) | Line-by-line file reading | ![100](https://img.shields.io/badge/100%2F100-brightgreen?style=flat-square) |
| 04 | [**Born2beroot**](#-Born2beroot) |  Linux server setup and system administration | ![100](https://img.shields.io/badge/100%2F100-brightgreen?style=flat-square) |
| 05 | [**so_long**](#-so_long) | 2D game with MiniLibX | ![100](https://img.shields.io/badge/100%2F100-brightgreen?style=flat-square) |
| 06 | [**pipex**](#-pipex) | Unix pipe and process simulation | ![100](https://img.shields.io/badge/100%2F100-brightgreen?style=flat-square) |
| 07 | [**push_swap**](#-push_swap) | Sorting algorithm with limited operations | ![84](https://img.shields.io/badge/84%2F100-yellow?style=flat-square) |
| 08 | [**minishell**](#-minishell) | Bash-like shell interpreter | ![97](https://img.shields.io/badge/97%2F100-brightgreen?style=flat-square) |
| 09 | [**philosophers**](#-philosophers) | Concurrency and thread synchronization | ![In Progress](https://img.shields.io/badge/In%20Progress-blue?style=flat-square) |

---

## 📖 Libft
![100](https://img.shields.io/badge/Grade-100%2F100-brightgreen?style=flat-square)

The foundation of the 42 curriculum. Libft involves reimplementing a large subset of the C standard library from scratch — functions like `memcpy`, `strlen`, `strjoin`, `split`, and many more — without using any of the originals. It teaches deep understanding of memory management, pointers, and how standard functions actually work under the hood. This library is carried forward and extended throughout the entire Common Core.

---

## 📖 ft_printf
![100](https://img.shields.io/badge/Grade-100%2F100-brightgreen?style=flat-square)

A faithful reimplementation of the C `printf` function using variadic arguments. This project requires handling format specifiers (`%s`, `%d`, `%x`, `%p`, etc.), proper type conversions, and edge cases around number formatting. It is one of the most used utilities across all subsequent projects and solidifies understanding of variadic functions and formatted output in C.

---

## 📖 get_next_line
![100](https://img.shields.io/badge/Grade-100%2F100-brightgreen?style=flat-square)

Implementation of a function that reads a file descriptor line by line across multiple successive calls. The challenge lies in correctly managing a static buffer across calls, handling arbitrary buffer sizes defined at compile time, and dealing cleanly with EOF, multiple file descriptors, and partial reads. A deceptively simple concept that demands precise memory handling.

---

## 📖 Born2beroot
![100](https://img.shields.io/badge/Grade-100%2F100-brightgreen?style=flat-square)

A system administration project centered around setting up and securing a Linux virtual 
machine from scratch. The project requires configuring a Debian or Rocky Linux server with 
strict rules: encrypted partitions using LVM, a hardened SSH configuration, a firewall with 
UFW, strong password policies enforced via PAM, and sudo rules with detailed logging. A 
custom monitoring script is written in Bash to display key system metrics at regular 
intervals via cron. Born2beRoot is a deep introduction to how Linux systems are structured, 
secured, and administered in practice.

---

## 📖 so_long
![100](https://img.shields.io/badge/Grade-100%2F100-brightgreen?style=flat-square)

A small 2D top-down game built with the MiniLibX graphics library. The project involves parsing a `.ber` map file, rendering textures, handling keyboard input, and implementing game logic — collectibles, exits, movement counting, and map validation. It is an introduction to event-driven programming and working with a low-level graphics API in C.

---

## 📖 pipex
![100](https://img.shields.io/badge/Grade-100%2F100-brightgreen?style=flat-square)

A simulation of the Unix shell pipe mechanism. `pipex` replicates the behaviour of `cmd1 | cmd2` by using `fork`, `pipe`, `execve`, and file redirection with `dup2`. It covers inter-process communication, process lifecycle management, and correctly handling input/output redirection — core concepts behind how every Unix shell operates.

---

## 📖 push_swap
![84](https://img.shields.io/badge/Grade-84%2F100-yellow?style=flat-square)

A sorting algorithm project with a twist: integers must be sorted using only two stacks and a restricted set of operations (`sa`, `sb`, `pa`, `pb`, `ra`, `rra`, etc.). The goal is to sort the data in the minimum number of operations possible. This project is an exploration of algorithm design, complexity, and optimisation under tight constraints.

---

## 📖 minishell
![97](https://img.shields.io/badge/Grade-97%2F100-brightgreen?style=flat-square)

A fully functional Bash-like shell interpreter written in C. Minishell handles command parsing, quote management, environment variables, redirections (`<`, `>`, `>>`), heredocs (`<<`), pipes, built-in commands (`cd`, `echo`, `export`, `unset`, `env`, `exit`), and signal handling (`SIGINT`, `SIGQUIT`). One of the most complex projects in the Common Core, requiring careful coordination between a lexer, parser, expander, and executor.

---

## 📖 philosophers
![In Progress](https://img.shields.io/badge/Status-In%20Progress-blue?style=flat-square)

A concurrency project based on the classic Dining Philosophers problem. The challenge is to prevent deadlocks and race conditions while allowing philosophers to eat, sleep, and think using POSIX threads (`pthread`) and mutexes. Precise timing, careful mutex ordering, and a monitor thread are required to ensure no philosopher starves and that death is detected and reported within a strict time window.

---

<div align="center">

*42 Lisboa — Common Core*

</div>
