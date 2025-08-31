#include <stdlib.h>

int	*plusOne(int *digits, int digitsSize, int *returnSize)
{
	int	*carry_ret_arr;
	int	*ret_arr;
	int	sum;
	int	carry;
	int	i;

	carry_ret_arr = malloc((digitsSize + 1) * sizeof(int));
	if (!carry_ret_arr)
		return (NULL);
	i = digitsSize - 1;
	while (i >= 0)
	{
		sum = digits[i] + carry;
		carry_ret_arr[i + 1] = sum % 10;
		carry = sum / 10;
		i--;
	}
	if (carry)
	{
		carry_ret_arr[0] = 1;
		*returnSize = digitsSize + 1;
		return (carry_ret_arr);
	}
	else
	{
		ret_arr = malloc(digitsSize * sizeof(int));
		if (!ret_arr)
		{
			free(carry_ret_arr);
			return (NULL);
		}
		while (++i < digitsSize)
			ret_arr[i] = carry_ret_arr[i + 1];
		free(carry_ret_arr);
		*returnSize = digitsSize;
		return (ret_arr);
	}
}
