/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 03:50:38 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/30 18:21:16 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

# define TRUE		1
# define FALSE		0

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_putnbr(int n);
void				ft_putchar(char c);
void				ft_strclr(char *str);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_strlower(char *str);
void				ft_strupper(char *str);
void				ft_lstclr(t_list **lst);
void				ft_lstrev(t_list **lst);
void				ft_swap(int *a, int *b);
void				ft_putstr(const char *str);
void				ft_putendl(const char *str);
void				ft_putnbr_fd(int n, int fd);
void				ft_bzero(void *str, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_putstr_fd(const char *str, int fd);
void				ft_lstsort(t_list **lst, int (*cmp)());
void				ft_putendl_fd(const char *str, int fd);
void				ft_striter(char *s, void (*f)(char *));
void				ft_lstmerge(t_list **lst1, t_list *lst2);
void				ft_putnbr_base(long int nb, uint8_t base);
void				ft_arrayrev(int *tab, int left, int right);
void				ft_print_bits(unsigned int nb, uint8_t bits);
void				ft_lstiter(t_list *lst, void(f)(t_list *elem));
void				ft_arrayprint(int *tab, unsigned long n, char sep);
void				ft_lstdel(t_list **alst, void(*del)(void *, size_t));
void				ft_arraysort(int *tab, int first, int last, int dir);
void				ft_striteri(char *str, void (*f)(unsigned int, char *));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelif(t_list **lst, void *content_ref, int (*cmp)());
void				ft_lstpushback(t_list **lst, void *content,
					size_t content_size);
void				ft_lstpushfront(t_list **lst_start, void *content,
					size_t content_size);
void				ft_lstiterif(t_list *lst, void (*f)(t_list *item),
					void *ref, int (*cmp)());

void				*ft_memalloc(size_t size);
void				*ft_memset(void *b, int c, size_t n);
void				*ft_memdup(const void *src, size_t n);
void				*ft_memchr(const void *str, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *src, const void *dst, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);

int					ft_sqrt(int nb);
int					ft_fact(int nb);
int					ft_isnum(char c);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isblank(int c);
int					ft_isdigit(int c);
int					ft_islower(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_isupper(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isprime(int nb);
int					ft_gcd(int x, int y);
int					ft_isoperator(int c);
int					ft_lstsize(t_list *lst);
int					ft_atoi(const char *str);
int					ft_rand(int min, int max);
int					ft_arraymin(int *tab, unsigned long n);
int					ft_arraymax(int *tab, unsigned long n);
int					ft_arraymean(int *tab, unsigned long n);
int					ft_arraymedian(int *tab, unsigned long n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strequ(const char *s1, const char *s2);
int					ft_atoi_base(const char *str, uint8_t base);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strnequ(const char *s1, const char *s2, size_t n);

long				ft_abs(int nb);
long				ft_fibo(int nb);
long				ft_pow(int nb, int power);

size_t				ft_strlen(const char *str);
size_t				ft_strcspn(const char *str, const char *rej);
size_t				ft_strlcat(char *dst, const char *src, size_t size);

char				*ft_itoa(int n);
char				*ft_strnew(size_t size);
char				*ft_strdup(const char *s1);
char				*ft_strrev(char *str, int n);
char				*ft_strtrim(const char *str);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strndup(const char *str, size_t n);
char				**ft_strsplit(const char *str, char c);
char				*ft_strtok(char *str, const char *sep);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_itoa_base(long int nb, uint8_t base);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strmap(const char *str, char (*f)(char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *s1, const char *s2, size_t n);
char				*ft_strjoinfree(char *s1, char *s2, char **addr);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strsub(const char *str, unsigned int start, size_t n);
char				*ft_strmapi(const char *str, char (*f)(unsigned int, char));

t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstpusharg(int ac, char **av);
t_list				*ft_lstat(t_list *lst, unsigned int n);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(const void *content, size_t content_size);
t_list				*ft_lstfind(t_list *lst, void *ref_content, int (*cmp)());

#endif
