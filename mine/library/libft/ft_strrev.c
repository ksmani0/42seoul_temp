#include "libft.h"

char *ft_strrev(char *str)
{
	int		size = 0;
	int		i = 0;
	char	temp;

	while (str[size] != 0)
		size++;
	while (i < --size)
	{
		temp = str[i];
		str[i] = str[size];
		str[size] = temp;
		i++;
	}
	return (str);
}
