#include "swappush.h"

// we need to make a program that returns the position of a content in a stack
int get_position(t_list *stack, int content)
{
    int position;
    t_list *tmp;
    tmp = stack;
    position = 0;
    while (tmp)
    {
        if (tmp->content == content)
        {
            return (position);
        }
        tmp = tmp->next;
        position++;
    }
    return (position);
}

// now we need a function that returns the content of the position in the stack
int get_content(t_list *stack, int position)
{
    int i;
    t_list *tmp;
    tmp = stack;
    i = 0;
    while (tmp)
    {
        if (i == position)
        {
            return (tmp->content);
        }
        tmp = tmp->next;
        i++;
    }
    return (0);
}
// now we need a function that returns the content of the highest number in the stack
int get_max(t_list *stack)
{
    int max;
    t_list *tmp;
    tmp = stack;
    max = stack->content;
    while (tmp)
    {
        if (tmp->content > max)
        {
            max = tmp->content;
        }
        tmp = tmp->next;
    }
    return (max);
}

// now we need a function that returns the content of the second highest number in the stack
int get_max2(t_list *stack, int max)
{
    int max2;
    t_list *tmp;
    if(ft_lstsize(stack) == 1)
        return (0);
    tmp = stack;
    max2 = stack->content;
    if(stack->content == max)
        max2 = stack->next->content;
    while (tmp)
    {
        if (tmp->content > max2 && tmp->content < max)
        {
            max2 = tmp->content;
        }
        tmp = tmp->next;
    }
    return (max2);
}

// now we need a function that decides which of the two max's is closer to the top of the stack or the bottom of the stack
int closest_to_sort_exit(t_list **stackb, int content1, int content2)
{
    int distancefront;
    int distancelast;
    int size;
    int position1;
    int position2;

    position1 = get_position(*stackb, content1);
    position2 = get_position(*stackb, content2);
    distancelast = 0;
    distancefront = 0;
    size = ft_lstsize(*stackb);
    if(position1 < size / 2)
        distancefront = position1;
    else
        distancefront = size - position1;
    if(position2 < size / 2)
        distancelast = position2;
    else
        distancelast = size - position2;
    if(distancefront < distancelast)
        return (content1);
    else
        return (content2);
}
// now we need a function that takes a content and pushes it to stacka using two ways either if the content position
// is higher than the ghalf oof the stack or if it is lower than the half of the stack
// if it is higher than the half of the stack we need to reverse rotate the stack
// if it is lower than the half of the stack we need to rotate the stack
void stack_pusher_a(t_list **stacka,t_list **stackb ,int content)
{
    int size;
    int index;
    
    stacka_fixer(stacka);
    while (ft_lstsize(*stackb))
    {
        size = ft_lstsize(*stackb);
        if(size == 1)
        {
            pusha(stacka, stackb);
            break;
        }
        index = get_position(*stackb, content);
        if(index == 0)
        {
            pusha(stacka, stackb);
            break;;
        }
        if(index >= size / 2)
            reverse_rotate_stack_b(stackb);
        else
            rotate_b(stackb);
    }
    stacka_fixer(stacka);
}

void sort(t_list **stacka, t_list **stackb)
{
    int winmax;
    int size;
    int max1;
    int max2;

    size = ft_lstsize(*stackb);
    while(ft_lstsize(*stackb))
    {
        max1 = get_max(*stackb);
        max2 = get_max2(*stackb, max1);
        winmax = closest_to_sort_exit(stackb, max1, max2);
        if(winmax == max1)
        {
            stack_pusher_a(stacka, stackb, max1);
            stack_pusher_a(stacka, stackb, max2);
        }
        else
        {
            stack_pusher_a(stacka, stackb, max2);
            stack_pusher_a(stacka, stackb, max1);
        }
    }
}