/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 16:47:32 by sanghpar          #+#    #+#             */
/*   Updated: 2020/10/10 08:06:09 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

size_t			ft_strlen(const char *s);
size_t			ft_strlcat(char *dst, const char *str, size_t size);
size_t			ft_strlcpy(char *dst, const char *str, size_t size);
char			*ft_strdup(const char *s1);
int				ft_atoi(const char *str);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcat(char *s1, const char *s2);
void			ft_putnbr(int number);
void			ft_putstr(char *str);
char			*ft_strncat(char *s1, const char *s2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strstr(const char *s1, const char *s2);
int				ft_tolower(int n);
int				ft_toupper(int n);
char			*ft_strchr(const char *s, int n);
char			*ft_strrchr(const char *s, int n);
char			*ft_strnstr(const char *s1, const char *s2, size_t len);
int				ft_isalpha(int n);
int				ft_isdigit(int n);
int				ft_isalnum(int n);
int				ft_isprint(int n);
int				ft_isascii(int n);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *b, size_t len);
void			*ft_memcpy(void *dest, const void *src, size_t len);
void			*ft_memchr(const void *mem, int c, size_t len);
int				ft_memcmp(const void *s1, const void *s2, size_t len);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memmove(void *dest, const void *src, size_t count);
void			*ft_memccpy(void *dest, const void *src, int c, size_t len);
void			ft_putendl_fd(const char *s, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(const char *s, int fd);
char			**ft_split(char *s, char s2);
char			*ft_strjoin(const char *s, const char *s2);
char			*ft_itoa(int n);
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char			*ft_substr(const char *s, unsigned int start, size_t len);
char			*ft_strtrim(const char *s, const char *delset);
char			*ft_strsub2(char const *s, unsigned int start, size_t len);
char			*ft_trim(char *str, char c);
void			free_buffer(char **sbuffer);
int				get_next_line(int fd, char **line);
void			ft_replace(char **str, char *src, char *dest);
char			**ft_split2(char *str, char charset, int index, char *r_arr);
bool			split2_is_sep(char c, char sep);
void			split2_jumpaa(char *start, char c, int *i);
int				split2_count_array(char *str, char sep);
char			*split2_create_arr(char *str, char sep, int *ip);
char			*split2_2(char **str, char charset);
void			haha(char *str, int *i, char sep);
void			jumpaa2(char **start, char c, int i);
void			jumpaa3(char *start, char c, int *i, char **arr);

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void	*content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *a, void *(*f)(void *), void (*del)(void *));
#endif
