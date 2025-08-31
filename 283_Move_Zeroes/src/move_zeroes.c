void	moveZeroes(int *nums, int numsSize)
{
	int	buf[numsSize];
	int	i;
	int	j;

	i = -1;
	while (++i < numsSize)
		buf[i] = 0;
	i = j = -1;
	while (++i < numsSize)
		if(nums[i] != 0)
			buf[++j] = nums[i];
	i = -1;
	while (++i < numsSize)
		nums[i] = buf[i];
}
