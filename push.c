/* push.c */
#include "push_swap.h"

static void push(t_stack **dst, t_stack **src)
{
    t_stack *tmp;
    t_stack *dst_last;
    t_stack *src_last;

    if (!*src) // Kaynak boşsa işlem yapma [cite: 184, 186]
        return;
    tmp = *src;
    // Kaynaktan düğümü kopar
    if (tmp->next == tmp) // Kaynakta tek eleman varsa
        *src = NULL;
    else
    {
        src_last = tmp->prev;
        src_last->next = tmp->next;
        tmp->next->prev = src_last;
        *src = tmp->next;
    }
    // Hedefe düğümü ekle
    if (!*dst) // Hedef boşsa
    {
        *dst = tmp;
        tmp->next = tmp;
        tmp->prev = tmp;
    }
    else
    {
        dst_last = (*dst)->prev;
        tmp->next = *dst;
        tmp->prev = dst_last;
        dst_last->next = tmp;
        (*dst)->prev = tmp;
        *dst = tmp; // Listenin başını yeni gelen eleman yap
    }
}

void pa(t_stack **a, t_stack **b)
{
    push(a, b); // b'den al a'ya koy [cite: 183]
    ft_putstr_fd("pa\n", 1); // [cite: 244]
}

void pb(t_stack **a, t_stack **b)
{
    push(b, a); // a'dan al b'ye koy [cite: 185]
    ft_putstr_fd("pb\n", 1); // [cite: 244]
}