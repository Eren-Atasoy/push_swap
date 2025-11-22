#include "push_swap.h"

// --- PARSING VE KONTROL ---

long    ft_atol(const char *str)
{
    long    res;
    int     sign;
    int     i;

    res = 0;
    sign = 1;
    i = 0;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i])
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return (res * sign);
}

int check_syntax(char *str_n)
{
    int i = 0;
    if (!str_n) return (0);
    if (str_n[i] == '-' || str_n[i] == '+')
        i++;
    if (!str_n[i]) return (0); // Sadece "+" veya "-" durumu
    while (str_n[i])
    {
        if (!ft_isdigit(str_n[i]))
            return (0);
        i++;
    }
    return (1);
}

int check_duplicate(t_stack *a, int n)
{
    t_stack *tmp;

    if (!a) return (0);
    tmp = a;
    while (1)
    {
        if (tmp->value == n)
            return (1);
        tmp = tmp->next;
        if (tmp == a) // Dairesel yapı, başa döndük
            break;
    }
    return (0);
}