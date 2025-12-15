#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int board_size;
int *board;

void print_solution(void)
{
	for(int i = 0; i < board_size; i++)
	{
		fprintf(stdout, "%d", board[i]);
		if (i < board_size - 1)
			fprintf(stdout, " ");
	}
	fprintf(stdout, "\n");
}
int ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return n;
}

int is_safe(int col, int row)
{
	for (int i = 0; i < col; i++)
	{
		if (board[i] == row)
			return 0;
		if (ft_abs(board[i] - row) == ft_abs(i - col)) //diferenca de rows for igual a diferenca de cols estao diagonais
			return 0;
	}
	return 1;
}
void solve(int col)
{
	if (col == board_size)
	{
		print_solution();
		return ;
	}
	for (int row = 0; row < board_size; row++)
	{
		if (is_safe(col, row))
		{
			board[col] = row;
			solve(col + 1);
		}
	}
}

int main(int ac, char **av)
{
	if (ac != 2 || !av[1][0])
	{
		write(1, "\n", 1);
		return 1;
	}
	int n = atoi(av[1]);
	if (n <= 3)
	{
		write(1, "\n", 1);
		return 1;
	}
	board_size = n;
	board = malloc(sizeof(int) * board_size);
	if (!board)
		return 1;
	solve(0);
	free(board);
	return 0;
}