#include "push_swap.h"

void    error_handler(char *message)
{
    ft_putstr_fd(message, 2);
    exit(EXIT_FAILURE);
}

void    error_exit(t_stack **a, char **tmp_argv, int flag_split)
{
    if (a && *a)
        free_stack(a);
    if (flag_split && tmp_argv) // Eğer split ile ayrılmışsa matrixi temizle
        free_matrix(tmp_argv);
    write(2, "Error\n", 6); // 
    exit(1);
}