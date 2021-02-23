#include "libft.h"

char *ft_strstr(char *s1, char *s2)
{
	char *p1;
	char *p2;

	if (s1 == 0 || s2 == 0)
		return ((void*)0);
	while (*s1 != 0)
	{
		p1 = s1;
		p2 = s2;
		while (*p1 == *p2 && *p2 != 0)
		{
			p1++;
			p2++;
		}
		if (*p2 == 0)
			return (s1);
		s1++;
	}
	return ((void*)0);
}
