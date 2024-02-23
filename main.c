#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int		fd = open("fichier.txt", O_RDONLY);
	char	*line = get_next_line(fd);
	//int a = 13;

	while (line)
	{
		printf("%ld %s", ft_strlen(line), line);
		free(line);
		line = get_next_line(fd);
	}
	printf("%s", line);
	free(line);
	close(fd);
}
