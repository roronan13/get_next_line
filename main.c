#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
#include "get_next_line.c"
#include "get_next_line_utils.c"


int main(int argc, char **argv)
{
    char *line;
    int fd;
    int nbr_line;
    nbr_line = 0;

    fd = open(argv[1], O_RDONLY);
    line = get_next_line(fd);
    while (line)
    {
        printf("%s", line);
        nbr_line++;
        line = get_next_line(fd);
    }
    printf("\nnbr_line : %d\n", nbr_line);
    close (fd);


    return (0);
}