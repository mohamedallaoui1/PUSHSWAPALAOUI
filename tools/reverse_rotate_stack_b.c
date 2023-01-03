/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_stack_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:57:18 by mabahani          #+#    #+#             */
/*   Updated: 2022/12/22 22:22:51 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../swappush.h"

void reverse_rotate_stack_b(t_list **stackb)
{
    if(ft_lstsize(*stackb) < 2)
        return ;
    t_list *last = *stackb;
    t_list *second_last = NULL;
    while(last->next != NULL)
    {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = *stackb;
    *stackb = last;
    printf("rrb\n");
}
