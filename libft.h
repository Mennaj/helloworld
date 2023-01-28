#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <ctype.h>

int ft_isalpha(int c);
int ft_isdigit(int arg);
int ft_isalnum(int arg);
int ft_isascii(int arg);
int ft_isprint(int arg);
int ft_strlen(char *str);
void *ft_memset(void *dest, int c, size_t count);
void ft_bzero(void *dst, size_t n);
void *ft_memcpy(void *dest, const char *src, size_t n);
void *ft_memmove(void *dest, const void *src, size_t n);
size_t ft_strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);
size_t  ft_strlcat(char *dst, const char *src, size_t size);
int ft_topper(int ch);
int ft_tolower(int ch);
char *ft_strchr(const char *str, int ch);
char *ft_strrchr(const char *str, int ch);
int ft_strncmp(const char *s1, const char *s2, size_t n);
void *ft_memchr(const void *str, int c, size_t n);
int ft_memcmp(const void *s1, const void *s2, size_t n);
char 	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int ft_atoi(const char *str);
char *ft_strdup(const char *ch);
void *ft_calloc(size_t count, size_t size);
int ft_atoi(const char *ch);
char *ft_substr(char const *s, unsigned int start,size_t len);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strtrim(char const *s1, char const *set);

#endif
