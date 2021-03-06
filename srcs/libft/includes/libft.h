/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 14:29:07 by snelk             #+#    #+#             */
/*   Updated: 2020/06/20 15:27:59 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 5

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t num, size_t size);
int				ft_isalnum(int ch);
int				ft_isalpha(int ch);
int				ft_isascii(int ch);
int				ft_isdigit(int ch);
int				ft_isprint(int ch);
char			*ft_itoa(int n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memchr(const void *arr, int c, size_t n);
int				ft_memcmp(const void *arr1, const void *arr2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *dest, int c, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			*ft_strchr(const char *str, int ch);
char			*ft_strdup(char *src);
char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_split(char const *s, char c);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *str);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *str1, const char *str2, size_t len);
char			*ft_strnstr(const char *str1, const char *str2, size_t len);
char			*ft_strrchr(const char *str, int ch);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(const char *s, unsigned int start, size_t len);
int				ft_toupper(int ch);
int				ft_tolower(int ch);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
							void (*del)(void *));
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			*ft_memjoin(void *arr1, void *arr2, size_t len1, size_t len2);
char			*ft_uitoa_base(int nbr, int base);
char			*ft_ultoa_base(long long int nbr, int base);
void			*ft_memsub(void	*arr, size_t start, size_t end);
int				get_next_line(int fd, char **line);
void			ft_putstr(char *s);
void			ft_putchar(char c);
int				ft_skip_nbr(char *str);

#endif
