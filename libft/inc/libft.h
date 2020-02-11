/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 15:53:36 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/09 13:08:27 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define INT_MIN		-2147483648
# define INT_MAX		2147483647
# define LOMAGIC		0x0101010101010101ULL
# define HIMAGIC		0x8080808080808080ULL
# define BUFF_SIZE		1

typedef	struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

typedef struct			s_data
{
	void				*data;
	size_t				len;
}						t_data;

typedef struct			s_tab_data
{
	struct s_data		**data;
	size_t				len;
}						t_tab_data;

typedef struct			s_read
{
	struct s_data		*data;
	struct s_read		*next;
}						t_read;

typedef unsigned long	t_ul;
typedef unsigned char	t_byte;

void					*ft_memalloc(size_t len);
void					ft_bzero(void *p, size_t len);
void					*ft_memset(void *dst, int c, size_t len);
void					*ft_memchr(const void *p, int c, size_t len);
void					*ft_memcpy(void *dst, const void *src, size_t len);
void					*ft_memccpy(void *dst, const void *src, int c,
		size_t len);
void					*ft_memdup(const void *src, size_t len);
void					*ft_memmove(void *dst, const void *src, size_t len);
int						ft_memcmp(const void *p1, const void *p2, size_t len);
void					ft_memdel(void **ap);

char					*ft_strnew(size_t size);
void					ft_strclr(char *str);
size_t					ft_strlen(const char *s);
char					*ft_strchr(const char *s, int c);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strncpy(char *dest, const char *src, size_t len);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strncat(char *s1, const char *s2, size_t n);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
char					*ft_strstr(const char *haystack, const char *needle);
char					*ft_strnstr(const char *haystack, const char *needle,
		size_t len);
void					ft_putendl_fd(char const *s, int fd);
char					*ft_strdup(const char *s1);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s,
		char (*f)(unsigned int, char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strsub(char const *s, unsigned int start,
		size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s);
char					**ft_strsplit(char const *s, char c);

t_data					*ft_read(char *file_name, int fd);
t_data					*ft_data_alloc(size_t len);
t_read					*ft_read_alloc(size_t len);
t_data					*ft_data_cat(t_read *begin);
void					ft_read_free(t_read **begin);
void					ft_data_free(t_data **datap);

int						ft_atoi(const char *str);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_is_strdigit(char *str);
void					ft_putchar(char c);
void					ft_putstr(char const *s);
char					*ft_itoa(int n);
void					ft_putendl(char const *s);
void					ft_putnbr(int n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
void					ft_strdel(char **as);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_isspace(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);
t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstdelone(t_list **alst,
		void (*del)(void *, size_t));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int						nmatch(char *s1, char *s2);
size_t					ft_count_words(char *s, char c);


typedef struct			s_gnl
{
	struct s_gnl		*next;
	char				*actual;
	char				*temp;
	int					current_fd;
}						t_gnl;

int				get_next_line(int fd, char **line);

#endif
