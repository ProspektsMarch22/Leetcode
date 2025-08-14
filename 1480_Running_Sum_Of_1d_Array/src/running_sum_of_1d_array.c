#include <stdlib.h>

int	*runningSum(int *nums, int numsSize, int *returnSize)
{
	int	i;
	int	j;
	int	sum;
	int	*returnArr;

	*returnSize = numsSize;
	returnArr = malloc(numsSize * sizeof(int));
	if (!returnArr)
		return NULL;
	i = 0;
	while (i < numsSize)
	{
		j = 0;
		sum = 0;
		while (j <= i)
		{
			sum += nums[j];
			j++;
		}
		returnArr[i] = sum;
		i++;
	}
	return returnArr;
}
