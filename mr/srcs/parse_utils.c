/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:48:05 by suntlee           #+#    #+#             */
/*   Updated: 2020/11/20 18:33:40 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char		*readfile(char *str, int fd)
{
	char	buf[BUFSIZE + 1];
	char	*ptr;
	int		ret;

	while ((ret = read(fd, buf, BUFSIZE)) > 0)
	{
		buf[ret] = '\0';
		ptr = str;
		if (!(str = ft_strjoin(str, buf)))
		{
			free(ptr);
			return (NULL);
		}
		free(ptr);
	}
	return (str);
}

void		check_range(double n, double min, double max, char *function)
{
	char	error_message[100];

	if (n < min || n > max)
	{
		ft_strncpy(error_message, function, 87);
		ft_strcat(error_message, " out of range");
		scene_error(error_message);
	}
}

void		skip_space(char **str)
{
	while (**str == ' ' || **str == '\t')
		(*str)++;
}

int			ft_stoi(char **str)
{
	int sign;
	int result;

	sign = 1;
	if (**str == '-' && *((*str)++))
		sign = -1;
	if (!ft_isdigit(**str))
		scene_error("formatted in correctly");
	result = 0;
	while (ft_isdigit(**str))
		result = 10 * result + (*((*str)++) - '0');
	skip_space(str);
	return (result * sign);
}

double		ft_stof(char **str)
{
	int		ip;
	double	dp;
	int		sign;

	ip = 0;
	sign = 1;
	if (**str == '-' && *((*str)++))
		sign = -1;
	if (!ft_isdigit(**str))
		scene_error("formatted in correctly");
	while (ft_isdigit(**str))
		ip = 10 * ip + (*((*str)++) - '0');
	if (**str == '.')
		(*str)++;
	dp = 0.0;
	while (ft_isdigit(**str))
		dp = 10 * dp + (*((*str)++) - '0');
	while (dp >= 1)
		dp /= 10;
	dp += ip;
	skip_space(str);
	return (dp * sign);
}
