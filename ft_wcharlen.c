#include "libft.h"

size_t	ft_wcharlen(const wchar_t *s)
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