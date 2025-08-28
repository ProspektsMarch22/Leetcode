#include <string.h>

size_t	get_sub(char *s)
{
	for (size_t i = 0; s[i]; i++)
		for (size_t j = i + 1; s[j]; j++)
			if (s[i] == s[j])
				return (j - 1);
	return (0);
}

int	recursive_check(char *s, size_t sub_end)
{
	if (sub_end + 1 > (strlen(s) / 2))
		return (0);
	if (strlen(s) % (sub_end + 1) != 0)
		return (recursive_check(s, sub_end + 1));
	size_t i = 0;
	while (1)
	{
		size_t j = 0;
		while (j < (sub_end + 1))
		{
			if (s[i + j] != s[(sub_end + 1) + i + j])
				if ((sub_end + 1) < strlen(s))
					return (recursive_check(s, sub_end + 1));
			j++;
		}
		i += (sub_end + 1);
		if (strlen(s) - i == (sub_end + 1))
			break;
	}
	return (1);
}

int	repeatedSubstringPattern(char *s)
{
	size_t	sub_end = get_sub(s);
	if (strlen(s) < 2)
		return (0);
	return (recursive_check(s, sub_end));
}
