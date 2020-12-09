/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoukim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 03:20:55 by kyoukim           #+#    #+#             */
/*   Updated: 2020/12/09 18:29:05 by kyoukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dst, char *src);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *src);
ssize_t	ft_read(int fd, void *buf, size_t count);
ssize_t	ft_write(int fd, void *buf, size_t count);

#endif
