#include <stdlib.h>

int	str_len(char *str)
{
	int i = -1;
	while(str[++i]);
	return (i);
}

char	*mergeAlternately(char *word1, char *word2)
{
	int	word1_len = str_len(word1);
	int	word2_len = str_len(word2);

	char *merged = malloc(word1_len + word2_len + 1);	
	if (!merged)
		return (0);

	int i, j, k;
	i = j = k = 0;
	for(j = 0; word1[i] || word2[k]; j++)
	{
		if (j % 2 == 0)
		{
			if(word1[i])
			{
				merged[j] = word1[i];
				i++;
			}
			else
			{
				merged[j] = word2[k];
				k++;
			}

		}
		else
		{
			if(word2[k])
			{
				merged[j] = word2[k];
				k++;
			}
			else
			{
				merged[j] = word1[i];
				i++;
			}
		}
	}
	merged[j] = '\0';
	return (merged);
}
