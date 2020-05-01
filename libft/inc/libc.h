/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 08:19:10 by zseignon          #+#    #+#             */
/*   Updated: 2020/05/01 17:09:21 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBC_H
# define LIBC_H

# define LOMAGIC	0x0101010101010101ULL
# define HIMAGIC	0x8080808080808080ULL

# include <stdlib.h>
# include <unistd.h>

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
void					ft_strdel(char **as);
void					ft_strclr(char *str);
size_t					ft_strcspn(const char *s, const char *charset);
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

int						ft_atoi(const char *str);
char					*ft_itoa(int n);

void					ft_putchar(char c);
void					ft_putstr(char const *s);

void					ft_putendl(char const *s);
void					ft_putnbr(int n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);

int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);
int						ft_isalpha(int c);
int						ft_isdigit(int c);

#endif
