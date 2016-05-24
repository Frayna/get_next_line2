#include "get_next_line.h"
#include "libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

int     main()
{
	int		fd;
	int		fd2;
	char	*line;

	fd = open("test", O_RDONLY);
	fd2 = open("test2", O_RDONLY);
	if (fd == -1)
	{
//		perror("open");
		return (1);
	}
	get_next_line((int const)fd, &line);
		ft_putstr(line);
		ft_putchar('\n');
		free (line);
	if (fd2 == -1)
	{
//		perror("open");
		return (1);
	}
	get_next_line((int const)fd2, &line);
		ft_putstr(line);
		ft_putchar('\n');
		free (line);
	if (fd == -1)
	{
//		perror("open");
		return (1);
	}
	get_next_line((int const)fd, &line);
		ft_putstr(line);
		ft_putchar('\n');
		free (line);
	if (fd2 == -1)
	{
//		perror("open");
		return (1);
	}
	get_next_line((int const)fd2, &line);
		ft_putstr(line);
		ft_putchar('\n');
		free (line);
	return (1);
}
