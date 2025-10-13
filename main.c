#include <push_swap.h>

int main(int argc, char **argv)
{
    int i;
    i = 0;
    char **final = NULL;
    char **split;
    if(argc == 1)
        return(0);
    while(i < argc)
    {
        split = ft_split(argv[i], ' ');
        final = ft_strjoin(final, split);
        //free(split)
        i++;
    }
    arg_check(final);


}