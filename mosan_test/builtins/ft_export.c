/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 18:41:12 by ehakam            #+#    #+#             */
/*   Updated: 2021/07/04 20:33:13 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_builtin.h"
#include "../include/ft_variables.h"
#include "../include/minishell.h"

extern t_minishell	g_config;

static int	print_var(t_var *var)
{
	int	i;

	i = -1;
	write(1, "declare -x ", 11);
	write(1, var->key, strlen(var->key));
	if (var->value)
	{
		write(1, "=\"", 2);
		while (var->value[++i])
		{
			if (var->value[i] == '$')
				write(1, "\\", 1);
			write(1, &var->value[i], 1);
		}
		write(1, "\"", 1);
	}
	write(1, "\n", 1);
	return (0);
}

static int	export_vars(int ac, char **av)
{
	int	i;
	int	code;

	i = 0;
	code = 0;
	while (++i < ac)
	{
		if (set_var(g_config.envp, av[i]) != 0)
			code = 1;
	}
	return (code);
}

int	ft_export(int ac, char **av)
{
	if (ac == 1)
		list_vars(g_config.envp, false, print_var);
	else if (ac > 1)
	{
		return (export_vars(ac, av));
	}
	return (0);
}
