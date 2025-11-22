#include "push_swap.h"

// --- YARDIMCI FONKSİYONLAR ---

// Stack'i ve Split dizisini temizlemek için
void    free_matrix(char **argv)
{
    int i;

    i = 0;
    if (!argv)
        return ;
    while (argv[i])
    {
        free(argv[i]);
        i++;
    }
    free(argv);
}

void    free_stack(t_stack **stack)
{
    t_stack *tmp;
    t_stack *current;

    if (!stack || !*stack)
        return ;
    current = *stack;
    while (current->next != *stack) // Dairesel olduğu için başa dönene kadar
    {
        tmp = current;
        current = current->next;
        free(tmp);
    }
    free(current); // Son elemanı (veya tek kalan elemanı) serbest bırak
    *stack = NULL;
}



// --- USER FONKSİYONLARI (Senin Yazdıkların) ---

t_stack *create_stack_node(int value)
{
    t_stack *new_node;
    new_node = (t_stack *)malloc(sizeof(t_stack));
    if(!new_node)
        return (NULL);
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = NULL;
    return (new_node);
}

void add_stack_node_end(t_stack **stack, t_stack *new_node)
{
    t_stack *last;
    if(!stack || !new_node)
        return;
    if(*stack == NULL)
    {
        *stack = new_node;
        new_node->prev = new_node;
        new_node->next = new_node;
        return;
    }
    else
    {
        last = (*stack)->prev;
        last->next = new_node;
        new_node->prev = last;
        new_node->next = *stack;
        (*stack)->prev = new_node;
    }
}


// --- MAIN ---

int main(int argc, char **argv)
{
    t_stack *a = NULL;
    t_stack *b = NULL;
    char    **tmp_argv;
    int     i;
    int     j;
    long    n;

    // Argüman yoksa hiçbir şey yapma [cite: 248]
    if (argc < 2)
        return (0);

    i = 1;
    while (i < argc)
    {
        // Argümanları boşluklara göre ayır (Örn: "1 2 3" gelirse)
        tmp_argv = ft_split(argv[i], ' ');
        if (!tmp_argv || !*tmp_argv) // Boş string kontrolü ("")
             error_exit(&a, tmp_argv, 1); // tmp_argv'yi temizle ve çık

        j = 0;
        while (tmp_argv[j])
        {
            // 1. Syntax Kontrolü (Sayı mı?)
            if (!check_syntax(tmp_argv[j]))
                error_exit(&a, tmp_argv, 1);
            
            // 2. Sayıyı long'a çevir
            n = ft_atol(tmp_argv[j]);

            // 3. Integer Overflow Kontrolü (> MAX veya < MIN) [cite: 250]
            if (n > 2147483647 || n < -2147483648)
                error_exit(&a, tmp_argv, 1);

            // 4. Duplicate (Tekrar) Kontrolü [cite: 250]
            if (check_duplicate(a, (int)n))
                error_exit(&a, tmp_argv, 1);

            // 5. Stack'e Ekleme
            add_stack_node_end(&a, create_stack_node((int)n));
            j++;
        }
        free_matrix(tmp_argv); // Split ile ayrılan hafızayı temizle
        i++;
    }

    // --- SIRALAMA ALGORİTMASI ---
    if (!is_sorted(a))
    {
        if (stack_size(a) == 2)
            sa(&a);
        else if (stack_size(a) == 3)
            sort_three(&a);
        else
            sort_stack(&a, &b);
    }

    // Program bitişinde her şeyi temizle
    free_stack(&a);
    free_stack(&b); // Genelde b boş olur ama güvenlik için
    return (0);
}