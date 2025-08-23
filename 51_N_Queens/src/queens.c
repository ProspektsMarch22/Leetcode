#include <stdlib.h>
#include <string.h>

int	ft_abs(int a)
{
	return ((a < 0) ? -a : a);
}

int	check_queen(int *board, int row, int col)
{
	for(int i = 1; i < row; i++)
		if (board[i] == col || ft_abs(board[i] - col) == ft_abs(i - row))
			return (0);
	return (1);
}

void	save_solution(int *board, int n, char ****solutions, int *count)
{
	*solutions = realloc(*solutions, sizeof(char **) * (*count + 1));
	(*solutions)[*count] = malloc(sizeof(char *) * n);
	for (int i = 1; i <= n; i++)
	{
		(*solutions)[*count][i - 1] = malloc(n + 1);
		memset((*solutions)[*count][i - 1], '.', n);
		(*solutions)[*count][i - 1][board[i] - 1] = 'Q';
		(*solutions)[*count][i - 1][n] = '\0';
	}
	*count += 1;
}

void	solve_queen(int row, int *board, int n, char ****solutions, int *count)
{
	for(int col = 1; col <= n; col++)
	{
		if (check_queen(board, row, col))
		{
			board[row] = col;
			if (row == n)
				save_solution(board, n, solutions, count);
			else
				solve_queen(row + 1, board, n, solutions, count);
		}
	}
}

char	***solveNQueens(int n, int *returnSize, int **returnColumnSizes)
{
	int	board[n + 1];
	char	***solutions;
	int	count;

	count = 0;
	solutions = NULL;
	solve_queen(1, board, n, &solutions, &count);
	*returnSize = count;
	*returnColumnSizes = malloc(sizeof(int) * count);
	for (int i = 0; i < count; i++)
	{
		(*returnColumnSizes)[i] = n;
	}
	return (solutions);
}
