#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    if(ac != 2)
    {
        printf("\e[1;31myou need to provide the commit message only!\e[0m\n");
        return 1;
    }
    system("git add .");
    char *str = calloc(strlen("git commit -m ") + strlen(av[1]), sizeof(char));
    strcpy(str, "git commit -m \"");
    strcat(str, av[1]);
    strcat(str, "\"");
    system(str);
    system("git push");
    free(str);
    return 0;
}