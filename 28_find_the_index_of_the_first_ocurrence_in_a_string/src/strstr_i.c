int	strSr(char *haystack, char *needle)
{
	int	i;
	int	j;

	i = -1;
	while (haystack[++i])
	{
		if (haystack[i] == *needle)
		{
			j = -1;
			while (needle[++j] && haystack[i + j])
				if (needle[j] != haystack[i +j])
					break;
			if (!(needle[j]))
				return (i);
		}
	}
	return (-1);
}
