#include "libft.h"

size_t	ft_ustrlen(const t_uchar *s)
{
	size_t len;

	len = 0;
	while (*s != 0)
	{
		s++;
		len++;
	}
	return (len);
}