/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_stack_a.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:57:08 by mabahani          #+#    #+#             */
/*   Updated: 2022/12/22 22:23:23 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../swappush.h"

void reverse_rotate_stack_a(t_list **stacka)
{
    if(ft_lstsize(*stacka) < 2)
        return ;
    t_list *last = *stacka;
    t_list *second_last = NULL;
    while(last->next != NULL)
    {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = *stacka;
    *stacka = last;
    printf("rra\n");
}