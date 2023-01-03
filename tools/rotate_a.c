/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:57:24 by mabahani          #+#    #+#             */
/*   Updated: 2022/12/18 19:06:50 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../swappush.h"

void rotate_a(t_list **stacka)
{
  if (*stacka && (*stacka)->next) {
    t_list *temp = *stacka;
    ft_lstadd_back(stacka, ft_lstnew(temp->content));
    *stacka = (*stacka)->next;
    free(temp);
    printf("ra\n");
  }
}

