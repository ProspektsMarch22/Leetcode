#include <string.h>

char	findTheDifference(char *s, char *t)
{
	if (!(*s))
		return (*t);
	int check_alphabet_s[26];
	int check_alphabet_t[26];
	memset(check_alphabet_s, 0, 26*sizeof(int));
	memset(check_alphabet_t, 0, 26*sizeof(int));
	for (int i = 0; s[i]; i++)
		check_alphabet_s[s[i] - 'a'] += 1;
	for (int i = 0; t[i]; i++)
		check_alphabet_t[t[i] - 'a'] += 1;
	for (int i = 0; i < 26; i++)
		if (check_alphabet_s[i] != check_alphabet_t[i])
			return ('a' + i);
	return (0);
}
