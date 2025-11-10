#include "push_swap.h"

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



int main(int argc, char **argv)
{

	(void)argc;
	(void)argv;

	t_stack *a;
	t_stack *b;
	int i;
	i = 0;
	a = NULL;
	b = NULL;

	int test_values[] = {3, 2, 5, 1, 4};

	while(i < 5)
	{
		t_stack *new_node = create_stack_node(test_values[i]);
		add_stack_node_end(&a, new_node);
		i++;
	}












    // int i;
    // i = 0;
    // char **final = NULL;
    // char **split;
    // if(argc == 1)
    //     return(0);
    // while(i < argc)
    // {
    //     split = ft_split(argv[i], ' ');
    //     final = ft_strjoin(final, split);
    //     //free(split)
    //     i++;
    // }
    // arg_check(final);


}