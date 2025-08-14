int	maximumWealth(int **accounts, int accountsSize, int *accountsColSize)
{
	int	max;
	int	sum;
	int	i;
	int	j;

	i = -1;
	max = 0;
	while (++i < accountsSize)
	{
		sum = 0;
		j = -1;
		while (++j < *accountsColSize)
			sum += accounts[i][j];
		if(sum > max)
			max = sum;
	}
	return max;
}
