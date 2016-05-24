#ifndef GNL
#define GNL
#define BUFF_SIZE 3
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft/libft.h"

typedef struct	t_gnl
{
	int			ref;
	char		*str;
	struct t_gnl	*next;
}				s_gnl;





/*
char	*ft_strsub(char const *s, unsigned int start, size_t len);
void	ft_putstr(char const *str);
void	ft_putnbr(int i);
int		ft_strlen(char *str);
char	*ft_strchr(const char *s, int c);
*/int		get_next_line(int const fd, char **line);
/*char	*ft_strcpy(char *dst, const char *src);
char	*ft_strnew(int i);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s);
char	*ft_strncpy(char *dst, const char *src, size_t n);
void	ft_puttab(char **tab);
void	*ft_memcpy(void *dst, const void *src, size_t n);
*/
#endif
