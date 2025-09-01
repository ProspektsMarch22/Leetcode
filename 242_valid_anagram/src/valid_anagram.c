#include <string.h>
#include <stdbool.h>

bool	isAnagram(char *s, char *t)
{
	int	check_alpha_s[26];
	int	check_alpha_t[26];

	if (strlen(s) != strlen(t))
		return (false);
	memset(check_alpha_s, 0, 26 * sizeof(int));
	memset(check_alpha_t, 0, 26 * sizeof(int));
	for (int i = 0; s[i]; i++)
	{
		check_alpha_s[s[i] - 'a'] += 1;
		check_alpha_t[t[i] - 'a'] += 1;
	}
	for (int i = 0; i < 26; i++)
		if(check_alpha_s[i] != check_alpha_t[i])
			return (false);
	return (true);
}
