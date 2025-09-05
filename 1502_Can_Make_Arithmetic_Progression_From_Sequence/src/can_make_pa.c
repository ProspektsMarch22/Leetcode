#include <stdbool.h>

void	sort_array(int *arr, int size)
{
	int	tmp, i, j;

	i = 0;
	while (i < (size - 1))
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[j] < arr[i])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

bool	canMakeArithmeticProgression(int *arr, int arrSize)
{
	int	ratio, i;

	sort_array(arr, arrSize);
	if (arrSize == 2)
		return (1);
	ratio = arr[1] - arr[0];
	i = 1;
	while (i < (arrSize - 1))
	{
		if (arr[i + 1] - arr[i] != ratio)
			return (0);
		i++;
	}
	return (1);
}
