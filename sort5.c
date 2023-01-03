#include "swappush.h"


void stack_pusher_b(t_list **stacka,t_list **stackb ,int content)
{
    int size;
    int index;
    
    stacka_fixer(stacka);
    while (ft_lstsize(*stackb))
    {
        size = ft_lstsize(*stackb);
        if(size == 1)
        {
            pushb(stacka, stackb);
            break;
        }
        index = get_position(*stackb, content);
        if(index == 0)
        {
            pushb(stackb,stacka);
            break;;
        }
        if(index >= size / 2)
            reverse_rotate_stack_a(stackb);
        else
            rotate_a(stackb);
    }
    //stacka_fixer(stacka);
}

int get_min(t_list *stack)
{
    int min;
    t_list *tmp;
    tmp = stack;
    min = stack->content;
    while (tmp)
    {
        if (tmp->content < min)
        {
            min = tmp->content;
        }
        tmp = tmp->next;
    }
    return (min);
}

void sort5(t_list **stacka, t_list **stackb)
{
    int max;

    while(ft_lstsize(*stacka) > 3)
    {
        max = get_min(*stacka);
        stack_pusher_b(stackb,stacka,max);
    }
    sort3(stacka);
    if (ft_lstsize(*stackb) == 3)
        sort3(stackb);
    if (ft_lstsize(*stackb) == 1)
    {
        pusha(stacka,stackb);
        rotate_a(stacka);
        return ;
    }
    if((*stackb)->content < (*stackb)->next->content)
        swapb(stackb);
    while(ft_lstsize(*stackb))
        pusha(stacka,stackb);
}
