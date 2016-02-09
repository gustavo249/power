/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <jfazakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 22:46:41 by jfazakas          #+#    #+#             */
/*   Updated: 2016/01/10 01:18:32 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_slist
{
	void			*data;
	struct s_slist	*next;
}					t_slist;

typedef struct		s_nlist
{
	int				value;
	struct s_nlist	*next;
}					t_nlist;

typedef struct		s_uclist
{
	unsigned char	value;
	struct s_uclist	*next;
}					t_uclist;

typedef struct		s_plist
{
	void			*pointer;
	struct s_plist	*next;
}					t_plist;

typedef struct		s_btree
{
	void			*item;
	struct s_btree	*left;
	struct s_btree	*right;
}					t_btree;
/*
** string
*/
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strcapitalize(char *str);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
char				*ft_strlowcase(char *str);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strrev(char *str);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				*ft_strupcase(char *str);
/*
** memory
*/
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
/*
** char
*/
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isanyof(int c, char *s);
int					ft_isascii(int c);
int					ft_isblank(int c);
int					ft_isdigit(int c);
int					ft_islower(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_isupper(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
/*
** conversion
*/
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
char				*ft_ltoa(long n);
char				*ft_lltoa(long long n);
char				*ft_uitoa(unsigned int n);
char				*ft_ultoa(unsigned long n);
char				*ft_ulltoa(unsigned long long n);
char				*ft_utobin(unsigned long long n);
char				*ft_utohexa(unsigned long long n);
char				*ft_utooctal(unsigned long long n);
char				*ft_dtoa(long double number, int precision);
/*
** number
*/
unsigned int		ft_numlen(long long n);
unsigned int		ft_unumlen(unsigned long long n);
int					ft_abs(int n);
void				ft_swap(int *a, int *b);
/*
** print
*/
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnuml(int n);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putwchar(wchar_t wide_char);
void				ft_putwstr(const wchar_t *wide_char);
/*
** list
*/
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstaddend(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstinsert(t_list **lst, t_list *new,
							int (*cmp)(t_list *, t_list *));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstnewnode(void *content, size_t content_size);
int					ft_lstsize(t_list *lst);
void				ft_lstsort(t_list *lst, int (*cmp)(t_list *, t_list *));
void				ft_lstswap(t_list *a, t_list *b);
/*
** type_list
*/
t_slist				*ft_slistnew(void *data);
void				ft_slistadd(t_slist **begin, t_slist *new);
int					ft_slistsize(t_slist *list);
void				ft_slistswap(t_slist *a, t_slist *b);
t_nlist				*ft_nlistnew(int value);
void				ft_nlistadd(t_nlist **begin, t_nlist *new);
t_uclist			*ft_uclistnew(unsigned char value);
void				ft_uclistadd(t_uclist **begin, t_uclist *new);
t_plist				*ft_plistnew(void *pointer);
void				ft_plistadd(t_plist **begin, t_plist *new);
void				ft_plistdel(t_plist **begin);
/*
** wide_string
*/
unsigned int		ft_wide_char_size(wchar_t wide_char);
unsigned int		ft_wide_string_length(const wchar_t *wide_string);
unsigned int		ft_wide_string_size(const wchar_t *wide_string);
wchar_t				*ft_wide_string_new(unsigned int length);
wchar_t				*ft_wide_string_dup(const wchar_t *wide_string);
/*
** binary_tree
*/
t_btree				*btree_create_node(void *item);
void				btree_apply_prefix(t_btree *root, void (*apply)(void *));
void				btree_apply_infix(t_btree *root, void (*apply)(void *));
void				btree_apply_suffix(t_btree *root, void (*apply)(void *));
void				btree_insert_data(t_btree **root, void *item,
							int (*cmpf)(void *, void *));
void				*btree_search_item(t_btree *root, void *data_ref,
							int (*cmpf)(void *, void *));
int					btree_level_count(t_btree *root);

#endif
