#include <stdbool.h>

bool	isMonotonic(int *nums, int numsSize)
{
	int	i, j;
	int	mono;

	i = 0; j = i + 1;
	mono = 1;
	while(j < numsSize)
	{
		if(nums[i] != nums[j])
			break ;
		i++; j = i + 1;
	}
	if(j == numsSize) return (true);
	if(nums[i] > nums[j]) mono = 0;
	while(j < numsSize)
	{
		if(mono)
		{
			if(nums[i] > nums[j])
				return (false);
		}
		else
		{
			if(nums[i] < nums[j])
				return (false);
		}
		i++; j = i + 1;
	}
	return (true);
}
