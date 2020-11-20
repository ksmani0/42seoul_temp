/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 17:08:55 by suntlee           #+#    #+#             */
/*   Updated: 2020/11/08 12:11:58 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	usage(char *prog_name)
{
	ft_printf("Usage: %s <scene.rt>\n", prog_name);
	exit(EXIT_FAILURE);
}

void	scene_error(char *message)
{
	char error_message[100];

	ft_strcpy(error_message, "Scene Error: ");
	ft_strncat(error_message, message, 87);
	ft_putstr_fd(error_message, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	fatal_error(char *message)
{
	char error_message[100];

	ft_strcpy(error_message, "Fatal Error: ");
	ft_strncat(error_message, message, 87);
	ft_putstr_fd(error_message, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
