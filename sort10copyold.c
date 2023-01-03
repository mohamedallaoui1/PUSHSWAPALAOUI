#include "swappush.h"

// int get_position_max(t_list *stack)
// {
//     int max;
//     int position;
//     t_list *tmp;
//     tmp = stack;
//     max = stack->content;
//     position = 0;
//     while (tmp)
//     {
//         if (tmp->content > max)
//         {
//             max = tmp->content;
//         }
//         tmp = tmp->next;
//     }
//     tmp = stack;
//     while(tmp)
//     {
//         if(tmp->content == max)
//             return (position);
//         position++;
//         tmp = tmp->next;
//     }
//     return (position);
// }
// i need a fucntion that returns the position of the second highest number in the stack
// int get_position_max2(t_list *stacka)
// {
//     int max;
//     int max2;
//     int position;
//     int position2;
//     t_list *tmp;
//     tmp = stacka;
//     max = stacka->content;
//     max2 = stacka->content;
//     position = 0;
//     position2 = 0;
//     while (tmp)
//     {
//         if (tmp->content > max)
//         {
//             max = tmp->content;
//         }
//         tmp = tmp->next;
//     }
//     tmp = stacka;
//     while (tmp)
//     {
//         if (tmp->content > max2 && tmp->content < max)
//         {
//             max2 = tmp->content;
//         }
//         tmp = tmp->next;
//     }
//     tmp = stacka;
//     while(tmp)
//     {
//         if(tmp->content == max2)
//             return (position);
//         position++;
//         tmp = tmp->next;
//     }
//     return (position);
// }
// int closest_to_sort_exit(t_list **stackb, int indmax1, int indmax2)
// {
//     int distancefront;
//     int distancelast;
//     int size;

//     distancelast = 0;
//     distancefront = 0;
//     size = ft_lstsize(*stackb);
//     if(indmax1 < size / 2)
//         distancefront = indmax1;
//     else
//         distancefront = size - indmax1;
//     if(indmax2 < size / 2)
//         distancelast = indmax2;
//     else
//         distancelast = size - indmax2;
//     if(distancefront < distancelast)
//         return (indmax1);
//     else
//         return (indmax2);
// }
void stacka_fixer(t_list **stacka)
{
    if((*stacka) && (*stacka)->next)
    {
        if((*stacka)->content > (*stacka)->next->content)
        {
            swapa(stacka);
        }
    }
}

// void sort(t_list **stacka, t_list **stackb)
// {
//     //printf("max1 = %d && max2 = %d", max1, max2);
//     int position;
//     int size = 0;
//     size = ft_lstsize(*stackb);
//     while(ft_lstsize(*stackb))
//     {
//         int max1 = get_position_max(*stackb);
//         int max2 = get_position_max2(*stackb);
//         position = closest_to_sort_exit(stackb, max1, max2);
//         //position = get_position_max(*stackb);
//         if(position == 0)
//         {
//             stacka_fixer(stacka);
//             pusha(stacka, stackb);
//             size--;
//             stacka_fixer(stacka);
//         }
//         if (position < size/2)
//             rotate_b(stackb);
//         else
//             reverse_rotate_stack_b(stackb);
//     }
// }

int *table_maker(t_list **stacka, int size)
{
    //first i need to creat a table with all the ellements
    int *tab = malloc(sizeof(int) * size);
    int i = 0;
    t_list *tmp = *stacka;
    //now let's move the ellements to the table
    while (tmp)
    {
        tab[i] = tmp->content;
        tmp = tmp->next;
        i++;
    }
    return (tab);
}
void table_sort(int *tab, int size)
{
    int i = 0;
    int j = 0;
    int tmp;
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            if (tab[i] < tab[j])
            {
                tmp = tab[i];
                tab[i] = tab[j];
                tab[j] = tmp;
            }
            j++;
        }
        i++;
    }
}

void table_insert(int **tab_shank, int *tab, int shank)
{
    int i = 0;
    int j = 0;
    int count = 0;
    while(i < 8)
    {
        tab_shank[i] = malloc(sizeof(int) * shank);
        j = 0;
        while (j < shank)
        {
            tab_shank[i][j] = tab[count];
            j++;
            count++;
        }
        i++;
    }
    tab_shank[i] = NULL;
}

// now we'll have to creat that will deside if the number gonna be pushed to stackb is higher than half of the chank or not
// if it is higher than half of the chank we'll have to push it to the bottom of the stack so we gonna pushb and reverse rotate the stack
// if it is lower than half of the chank we'll have to push it to the top of the stack so we gonna pushb only 

void push_decider(t_list **stacka, t_list **stackb, int *tab, int shank)
{
    int i = 0;
    int j = 0;
    int count = 0;
        j = 0;
        while (j < shank)
        {
            if (tab[j] == (*stacka)->content)
            {
                if (j < shank/2)
                {
                    pushb(stacka, stackb);
                    break;
                }
                else
                {
                    pushb(stacka, stackb);
                    rotate_b(stackb);
                    break;
                }
            }
            j++;
        }
}

void sort10(t_list **stacka, t_list **stackb)
{
    //printf("here");
    int *tab = table_maker(stacka, ft_lstsize(*stacka));
    int size = ft_lstsize(*stacka);
    table_sort(tab, size);
    int shank = size / 8 + 1;
    int **tab_shank = malloc(sizeof(int *) * (8 + 1));
    table_insert(tab_shank, tab, shank);
    int i = 0;
    int index = 0;
    int count = shank;
    while(ft_lstsize(*stacka))
    {
        count = shank;
        while(ft_lstsize(*stacka) && count != 0)
        {
            index = closest_to_the_exit(stacka, tab_shank[i], shank);
            if(index == -1)
                break;
            if(ft_lstsize(*stacka) < 2)
            {
                pushb(stacka, stackb);
                break;
            } else if(index < ft_lstsize(*stacka) / 2)
            {
                while(index--)
                    rotate_a(stacka);
                push_decider(stacka, stackb, tab_shank[i], shank);
                //pushb(stacka, stackb);
            }
            else
            {
                while(index++ < ft_lstsize(*stacka))
                    reverse_rotate_stack_a(stacka);
                push_decider(stacka, stackb, tab_shank[i], shank);
                //pushb(stacka, stackb);
            }
            count--;
        }
        //doublestackprinter(stacka, stackb);
        i++;
    }
    //doublestackprinter(stacka, stackb);
    sort(stacka, stackb);
    //doublestackprinter(stacka, stackb);
}