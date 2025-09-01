#include <stddef.h>

int	arraySign(int *nums, int numsSize)
{
	int	product = 1;
	for (size_t i = 0; i < numsSize; i++)
	{
		if (nums[i] == 0) return (0);
		product *= (nums[i] > 0) ? 1 : -1;
	}
	return (product);
}
