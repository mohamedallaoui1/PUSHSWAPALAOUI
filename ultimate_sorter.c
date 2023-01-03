#include "swappush.h"


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

void table_insert(int **tab_shank, int *tab, int shank, int howmany)
{
    int i = 0;
    int j = 0;
    int count = 0;
    while(i < howmany)
    {
        tab_shank[i] = malloc(sizeof(int) * shank + 1);
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
    //now we gonna print the table
    // i = 0;
    // while (tab_shank[i])
    // {
    //     j = 0;
    //     while (j < shank)
    //     {
    //         printf("%d ", tab_shank[i][j]);
    //         j++;
    //     }
    //     printf("\n");
    //     i++;
    // }
}

// now we'll have to creat that will deside if the number gonna be pushed to stackb is higher than half of the chank or not
// if it is higher than half of the chank we'll have to push it to the bottom of the stack so we gonna pushb and reverse rotate the stack
// if it is lower than half of the chank we'll have to push it to the top of the stack so we gonna pushb only 

void push_decider(t_list **stacka, t_list **stackb, int *tab, int shank)
{
    int j;

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

void ultimate_sort(t_list **stacka, t_list **stackb, int howmany)
{
    int *tab = table_maker(stacka, ft_lstsize(*stacka));
    int size = ft_lstsize(*stacka);
    table_sort(tab, size);
    int shank = size / howmany + 1;
    int **tab_shank = malloc(sizeof(int *) * (howmany + 1));
    table_insert(tab_shank, tab, shank, howmany);
    int i = 0;
    int index = 0;
    int count = shank;
    while(ft_lstsize(*stacka))
    {
        count = shank;
        while(ft_lstsize(*stacka) && count != 0)
        {
            index = closest_to_the_exit(stacka, tab_shank[i], shank);
            //doublestackprinter(stacka, stackb);
            //printf("index = %d\n", index);
           // printf("the content chosen is %d\n", tab_shank[i][index]);
            if(index == -1)
                break;
            if(ft_lstsize(*stacka) < 2)
            {
                pushb(stacka, stackb);
                break;
            }
            else if(index < ft_lstsize(*stacka) / 2)
            {
                while(index--)
                    rotate_a(stacka);
                push_decider(stacka, stackb, tab_shank[i], shank);
            }
            else
            {
                while(index++ < ft_lstsize(*stacka))
                    reverse_rotate_stack_a(stacka);
                push_decider(stacka, stackb, tab_shank[i], shank);
            }
            count--;
        }
        i++;
    }
    free(tab);
    free_double_ptr_int(tab_shank);
    sort(stacka, stackb);
}
