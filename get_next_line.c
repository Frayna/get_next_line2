/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgourran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 01:22:29 by pgourran          #+#    #+#             */
/*   Updated: 2016/05/25 00:40:04 by pgourran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strsub_free(char *s, unsigned int start, size_t len)
{
	char	*out;
	int		i;

	i = 0;
	if ((out = ft_strnew(len)))
	{
		while (len-- > 0)
			out[i++] = s[start++];
		out[i] = '\0';
		if (s)
			free(s);
		return (out);
	}
	return(NULL);
}

s_gnl	*ngnl(s_gnl	*list, int fd, int next)
{
	s_gnl *new;

	if (!(new = malloc(sizeof(s_gnl))))
		return(NULL);
	if (fd)
		new->ref = fd;
	new->next = NULL;
	new->str = NULL;
	if (next)
		list->next = new;
	return(new);
}

s_gnl	*find_fd(s_gnl	*list, int fd)
{
	s_gnl	*ret;

	ret = list;
	while (ret->ref != fd && ret->next)
		ret = ret->next;
	if (ret->ref != fd)
		return(ngnl(ret, fd, 1));
	return(ret);
}

char	*ft_strjoin_free(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*out;

	if ((out = ft_strnew(ft_strlen(s1) + ft_strlen((char *)s2))))
	{
		i = 0;
		j = 0;
		while (s1[i])
		{
			out[i] = s1[i];
			i++;
		}
		while (s2[j])
			out[i++] = s2[j++];
		out[i] = '\0';
		if (s1)
			free(s1);
		return(out);
	}
	return (NULL);
}

int		get_next_buf(int const fd, int ret, char **save)
{
	char *buf;

	if (!(buf = ft_strnew(BUFF_SIZE)))
		return(-1);
	if ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(*save = ft_strjoin_free(*save, buf)))
			return (-1);
	}
	if (buf)
		free(buf);
	return (ret);
}

int		ft_endofbuff(char **line, char **s)
{
	if ((*s)[0])
	{
		if (!(*line = ft_strdup(*s)))
			return (-1);
		if (*s)
			free(*s);
		*s = NULL;
		return (1);
	}
	return(0);
}

int		get_next_line(int const fd, char **line)
{
static s_gnl *s;
s_gnl	*t;
int		ret;
char	*tmp;

	if(!s && fd >= 0 && line)
		s = ngnl(s, fd, 0);
	if (fd < 0 || line == NULL || (!(t = find_fd(s, fd)))
			|| (!(t->str) && (!(t->str = ft_strnew(BUFF_SIZE)))))
		return (-1);
	ret = 1;
	while ((t->str) && (!(tmp = ft_strchr(t->str, '\n')) && ret > 0))
		if ((ret = get_next_buf(fd, ret, &t->str)) == -1)
			return (-1);
	if (ret == 0 || !tmp)
		return (ft_endofbuff(line, &(t->str)));
	if (!(*line = ft_strsub(t->str, 0, tmp - t->str)))
		return (-1);
	if (!(t->str = ft_strsub_free(t->str, tmp - t->str + 1, ft_strlen(tmp + 1))))
		return (-1);
	return(1);
}
