#include "swappush.h"
void bnn(t_list **stacka)
{
    if((*stacka)->next->content > (*stacka)->next->next->content)
    {
        rotate_a(stacka);
        swapa(stacka);
    }
    else
        rotate_a(stacka);
}

void nbn(t_list **stacka)
{
    if((*stacka)->content > (*stacka)->next->next->content)
        reverse_rotate_stack_a(stacka);
    else
    {
        reverse_rotate_stack_a(stacka);
        swapa(stacka);
    }
}

void nnb(t_list **stacka)
{
    if((*stacka)->content > (*stacka)->next->content)
        swapa(stacka);
}

void sort3(t_list **stacka)
{
    int content;
    int position;

    content = get_max(*stacka);
    position = get_position(*stacka, content);
    if(position == 2)
        nnb(stacka);
    else if(position == 1)
        nbn(stacka);
    else if(position == 0)
        bnn(stacka);
}
