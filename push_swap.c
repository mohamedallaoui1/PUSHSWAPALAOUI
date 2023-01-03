/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 22:58:56 by mabahani          #+#    #+#             */
/*   Updated: 2022/12/26 22:28:04 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swappush.h"
void doublestackprinter(t_list **stacka, t_list **stackb)
{
    t_list *tmpa;
    t_list *tmpb;
    tmpa = *stacka;
    tmpb = *stackb;
    printf(">-------<     >-------<\n");
    while (tmpa || tmpb)
    {
        if (tmpa)
        {
            printf("   <%d>\t\t", tmpa->content);
            tmpa = tmpa->next;
        }
        else
            printf("   < >\t\t");
        if (tmpb)
        {
            printf("<%d>\n", tmpb->content);
            tmpb = tmpb->next;
        }
        else
            printf("< >\n");
    }
        printf(">---sa---<   >---sb---<\n");
}
//to check if the string is a valid number and if it is not already in the stack using ft_atoi
int problem_checker(t_list *stacka, char *number)
{
    if(ft_atoi(number) == 0 && number[0] != '0')
        return (0);
    while(stacka)
    {
        if(stacka->content == ft_atoi(number))
            return (0);
        stacka = stacka->next;
    }
    return (1);
}

void	free_double_ptr_int(int **ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != NULL)
		free(ptr[i++]);
	free(ptr);
}
void	free_double_ptr_char(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != NULL)
		free(ptr[i++]);
	free(ptr);
}

int stack_init(t_list **stacka, char **av)
{
    int i;
    int j;
    char **p;
    
    i = 1;
    j = 0;
    while(av[i])
    {
        p = ft_split(av[i],' ');

        while(p[j])
        {
            if(problem_checker(*stacka, p[j]) == 0)
            {
                printf("Error");
                return (0);
            }
            ft_lstadd_back(stacka, ft_lstnew(ft_atoi(p[j])));
            j++;
        }
        j = 0;
        i++;
        free_double_ptr_char(p);
    }
    return (1);
}
int main(int ac, char **av)
{
    t_list *stacka;
    t_list *stackb;

    int i;
    int j;

    i = 1;
    j = 0;
    stacka = NULL;
    stackb = NULL;
    if(ac == 1)
        return (0);
    if(stack_init(&stacka, av) == 0)
        return (0);
    if(ft_lstsize(stacka) < 4)
    {
        sort3(&stacka);
    }
    else if(ft_lstsize(stacka) < 7)
    {
        printf("went to sort5\n");
        sort5(&stacka,&stackb);
        printf("ended to sort5\n");
    }
    else if(ft_lstsize(stacka) <= 300)
        ultimate_sort(&stacka,&stackb,4);
    else if(ft_lstsize(stacka) >= 300)
        ultimate_sort(&stacka, &stackb,9);
    //system("leaks a.out");
    return (0);
}
