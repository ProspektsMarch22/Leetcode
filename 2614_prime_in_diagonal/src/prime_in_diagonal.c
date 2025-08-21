int	is_prime(int nb)
{
	long long	guess;

	if (nb == 2 || nb == 3)
		return (1);
	if (nb < 2 || nb % 2 == 0 || nb % 3 == 0)
		return (0);
	guess = 5;
	while ((guess * guess) <= nb)
	{
		if (nb % guess == 0 || nb % (guess + 2) == 0)
			return (0);
		guess += 6;
	}
	return (1);
}

int	diagonalPrime(int **nums, int numsSize, int *numsColSize)
{
	int	max_prime;
	int	num;
	int	i;
	int	praque;

	int praque = *numsColSize; //Matrix is squared, information about columns being treated separetely is unnecessary, but the arg is mandatory to the challenge in C.
	
	max_prime = 0;
	i = -1;
	while (++i < numsSize)
	{
		num = nums[i][i];
		if (is_prime(num))
			if (num > max_prime)
				max_prime = num;
		num = nums[i][numsSize - i - 1];
		if (is_prime(num))
			if (num > max_prime)
				max_prime = num;
	}
	return (max_prime);
}
