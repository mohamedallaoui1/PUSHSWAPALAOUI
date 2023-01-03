#include "swappush.h"

int get_position_min(t_list *stack)
{
    int min;
    int position;
    t_list *tmp;
    tmp = stack;
    min = stack->content;
    position = 0;
    while (tmp)
    {
        if (tmp->content < min)
        {
            min = tmp->content;
        }
        tmp = tmp->next;
    }
    tmp = stack;
    while(tmp)
    {
        if(tmp->content == min)
            return (position);
        position++;
        tmp = tmp->next;
    }
    return (position);
}

int get_position_max(t_list *stack)
{
    int max;
    int position;
    t_list *tmp;
    tmp = stack;
    max = stack->content;
    position = 0;
    while (tmp)
    {
        if (tmp->content > max)
        {
            max = tmp->content;
        }
        tmp = tmp->next;
    }
    tmp = stack;
    while(tmp)
    {
        if(tmp->content == max)
            return (position);
        position++;
        tmp = tmp->next;
    }
    return (position);
}

// int get_max(t_list **stacka)
// {
//     int max;
//     int position;
//     t_list *tmp;
//     tmp = *stacka;
//     max = tmp->content;
//     while (tmp)
//     {
//         if (tmp->content > max)
//         {
//             max = tmp->content;
//         }
//         tmp = tmp->next;
//     }
//     return(max);
// }
void sort10(t_list **stacka, t_list **stackb)
{
    int position;
    t_list *tmp;
    int size;
    size = ft_lstsize(*stacka);
    while(ft_lstsize(*stacka))
    {
        position = get_position_min(*stacka);
        if(position == 0)
            pushb(stacka, stackb);
        if (position < size/2)
            rotate_a(stacka);
        else
            reverse_rotate_stack_a(stacka);
    }
    while (ft_lstsize(*stackb))
        pusha(stacka, stackb);
}
int num_finder(int min,int max,t_list **stacka)
{
    int target = -1;
    int position;
    t_list *tmp;
    tmp = *stacka;
    position = 0;
    while (tmp)
    {
        if (tmp->content > min && tmp->content < max)
        {
            target = tmp->content;
            break;
        }
        tmp = tmp->next;
    }
    if(target == -1)
        return(-1);
    tmp = *stacka;
    while(tmp)
    {
        if(tmp->content == target)
            return (position);
        position++;
        tmp = tmp->next;
    }
    return (position); 
}
void sort1011(t_list **stacka, t_list **stackb)
{
// first let's send data to stackb in parts
int size = ft_lstsize(*stacka);

int numb = 0;
int min = get_position_min(*stacka);
int max = get_position_max(*stacka);
int mxnum  = get_max(stacka); 
printf("%d",mxnum);
int i = max/2;
    while(stacka && i < max)
    {
        while((numb = num_finder(i,mxnum,stacka)) != -1)
        {
            if(numb == 0)
                pushb(stacka, stackb);
            if (numb < size/2)
            {
                while(numb != 0)
                {
                    rotate_a(stacka);
                    numb--;
                }
            }
            else
            {
                while(numb != mxnum + 1)
                {
                    reverse_rotate_stack_a(stacka);
                    numb--;
                }
            }
        }
        i = i + mxnum/5;
    } 
}
