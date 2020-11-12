#include "ft_printf.h"

int	hex_to_str(t_ullint x, t_format *list)
{
	t_ullint	temp;
	char		*hex;
	int		len;
	int		ret;

	temp = x;
	while (x != 0)
	{
		x /= 16;
		len++;
	}
	ret = len;
	hex = list->spec == 'X' ? g_hex_b : g_hex_s;
	while (temp != 0)
	{
		list->if_num[--len] = hex[temp % 16];
		temp /= 16;
	}
	list->if_num[0] = ret == 0 ? '0' : list->if_num[0];
	return (ret != 0 ? ret : 1);
}

void	output_sharp_x(char *out, t_format *list, int len)
{
	int i;
	int longer;

	i = 0;
	longer = len > list->prec ? len : list->prec;
	if (llist->flag[1] != 1 && list->width > longer + 2)/* | 0xc8| 0x0c8| */
		fill_space_or_zero(&i, list->size - longer - 2, ' ');
	out[i++] = '0';
	out[i++] = list->spec == 'x' ? 'x' : 'X';
	if (list->prec > len)
		fill_space_or_zero(&i, list->prec - len, '0');
	len = 0;
	while (list->if_num[len] != 0)
		out[i++] = list->if_num[len++];
	if (list->width > longer + 2)
		fill_space_or_zero(&i, list->size, ' ');
	write(1, out, i);
	free(out);
}

void	output_x(char *out, t_format *list, int len)
{
	int i;
	int longer;

	i = 0;
	if (list->flag[1] == 0 && list->width > len && list->width > list->prec)
	{/* |..123|..00123| */
		longer = len > list->prec ? len : list->prec;
		fill_space_or_zero(&i, list->size - longer, out, ' ');
	}
	if (list->prec > len)/* |..00123|00123| */
		fill_space_or_zero(&i, list->size - len, out, '0');
	len = 0;
	while (list->if_num[len] != 0)
		out[i++] = list->if_num[len++];
	if (list->flag[1] == 1 && list->width > len && list->width > list->prec)
		fill_space_or_zero(&i, list->size, out, ' ');
	write(1, out, i);
	free(out);
	list->nums += i;
}

int	print_x(t_format *list)
{
	t_ullint	x;
	int		len;
	int		longer;

	if (list->flag[0] == 1 || list->flag[3] == 1)/* +' ' */
		return (-1);
	x = check_ullint(list);
	len = hex_to_str(x, list);
	list->size = len > list->prec ? len : list->prec;
	longer = len > list->prec ? len : list->prec;
	list->size = len > list->width ? len : list->width;
	if (list->width < longer + 2)/* |0x00aa|0xaaa|0x000aa| */
		list->size = list->size + (longer + 2 - list->width);
	if ((out = (char*)malloc(sizeof(char) * (list->size + 1))) == 0)
		return (-1);
	out[list->size] = 0;
	if (list->flag[5] == 1)
		output_sharp_x(out, list, len);
	else
		output_x(out, list, len);
	return (1);
}