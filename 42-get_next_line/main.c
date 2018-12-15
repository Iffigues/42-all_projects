#include <stdlib.h>
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int             main(int ac, char **av)
{
        int             ret;
        int             fd;
        char    *line;

        if (ac != 2)
                return (0);
        fd = open(av[1], O_RDONLY);

        while ((ret = get_next_line(fd, &line)))
        {
                printf("line: %i\t %s\n", ret, line);
                free(line);
        }
//        while (1)
//                ;
        return (1);
}

/* gcc -Wall -Wextra -Werror main.c get_next_line.c -L libft -lft
./a.out get_next_line.c
leaks a.out | less */
