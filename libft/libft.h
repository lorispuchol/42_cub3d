/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:07:21 by kmammeri          #+#    #+#             */
/*   Updated: 2022/01/15 15:32:08 by kmammeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nb;
	int				order_in_stack;
	int				index;
	struct s_stack	*next;
	struct s_stack	*previous;
}				t_stack;

int				ft_atoi(const char *str);
void			ft_bzero(void *pointer, size_t count);
void			*ft_calloc(size_t elementCount, size_t elementSize);
int				ft_isalnum(int a);
int				ft_isalpha(int a);
int				ft_isascii(int a);
int				ft_isdigit(int a);
int				ft_isprint(int a);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *pointer1, const void *pointer2, \
				size_t size);
void			*ft_memcpy(void *dest, const void *source, size_t size);
void			*ft_memmove(void *dest, const void *source, size_t size);
void			*ft_memset(void *pointer, int value, size_t count);
char			*ft_strchr(const char *str, int chr);
char			*ft_strdup(const char *src);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
unsigned int	ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *first, const char *second, size_t len);
char			*ft_strnstr(const char *str, const char *to_find, size_t len);
char			*ft_strrchr(const char *str, int chr);
int				ft_tolower(int character);
int				ft_toupper(int chara);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n);
t_stack			*ft_lstnew(int i, int index);
void			ft_lstadd_front(t_stack *alst, t_stack *new);
int				ft_lstsize(t_stack *lst);
t_stack			*ft_lstlast(t_stack *lst);
void			ft_lstadd_back(t_stack **alst, t_stack *new);
void			ft_lstdelone(t_stack *lst, void (*del)(int));
void			ft_lstclear(t_stack **lst, void (*del)(int));
void			ft_lstiter(t_stack *lst, void (*f)(int));

#endif
