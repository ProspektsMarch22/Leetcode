#include <stdlib.h>

int numLen(int num)
{
	if (num > 9)
		return (1 + numLen(num / 10));
	return 1;
}

int  power(int base, int exp)
{
	if (exp == 0)
		return 1;
	else if (exp == 1)
		return base;
	return (base * power(base, exp - 1));
}

char *itoa(int num)
{
	int size = numLen(num);
	char *str = malloc(size + 1);
	if (!str)
		return NULL;
	int i = 0;
	int div = power(10, (numLen(num) - 1));
	for (; i < size; i++)
	{
		int digit = num / div;
		str[i] = digit + '0';
		num = num % div;
		div /= 10;
	}
	str[i] = '\0';
	return str;
}

char **fizzBuzz(int n)
{
	char **output = malloc((n) * sizeof(char *));
	if (!output)
		return NULL;
	for (int i = 1, j = 0; i <= n; i++, j++)
	{
		if (i % 3 == 0 && i % 5 == 0)
		{
			output[j] = "FizzBuzz";
			continue ;
		}
		if (i % 3 == 0)
		{
			output[j] = "Fizz";
			continue ;
		}
		if (i % 5 == 0)
		{
			output[j] = "Buzz";
			continue ;
		}
		output[j] = itoa(i);
		if(!output[j])
		{
			for (int k = 0; k < j; k++)
				free(output[k]);
			free(output);
			return NULL;
		}
	}
	return output;
}
