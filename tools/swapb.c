/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:57:45 by mabahani          #+#    #+#             */
/*   Updated: 2022/12/18 19:07:07 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../swappush.h"

static void swapFirstTwot_list(t_list **head)
{
    t_list *first;
    t_list *second;

    if (*head == NULL || (*head)->next == NULL)
        return;

    first = *head;
    second = first->next;

    first->next = second->next;
    second->next = first;
    *head = second;
}

void swapb(t_list **stackb)
{
    swapFirstTwot_list(stackb);
    printf("sb\n");
}
