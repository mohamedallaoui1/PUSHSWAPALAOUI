/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:57:01 by mabahani          #+#    #+#             */
/*   Updated: 2022/12/18 19:06:34 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../swappush.h"

void pushb(t_list **stacka, t_list **stackb)
{
    t_list *temp;

    if(ft_lstsize(*stacka) < 1)
        return;
    temp = *stacka;
    *stacka = (*stacka)->next;
    temp->next = *stackb;
    *stackb = temp;
    printf("pb\n");
}
