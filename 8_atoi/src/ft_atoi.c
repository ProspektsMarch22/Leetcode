#include <limits.h>

int	ft_atoi(char *str)
{
	int	sign;
	int	i;
	long int	num;

	sign = 1;
	i = 0;
	while (s[i] == ' ')
		i++;
	if (s[i] == '-')
	{
		sign = -sign;
		i++;
	}
	else if (s[i] == '+')
		i++;
	num = 0;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (sign * num);
		num = (s[i] - '0') + (num * 10);
		if ((num) >= INT_MAX)
		{
			if (sign > 0)
				return (INT_MAX);
			else if (sign < 0)
				if (num > INT_MAX)
					return (INT_MIN);
				else
					return (sign * num);
		}
		i++;
	}
	return (num * sign);
}
