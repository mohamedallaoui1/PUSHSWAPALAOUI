/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:57:34 by mabahani          #+#    #+#             */
/*   Updated: 2022/12/18 19:06:54 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../swappush.h"

// void rotate_b(t_list **stackb)
// {
//     t_list *temp;
//     int last;

//     if(ft_lstsize(*stackb) < 2)
//         return;

//     last = (*stackb)->content;
//     temp = *stackb;
//     while((*stackb)->next != NULL)
//     {
//         temp->content = (*stackb)->next->content;
//         temp = temp->next;
//         *stackb = (*stackb)->next;
//     }
//     temp = ft_lstlast(*stackb);
//     temp->content = last;
// }
void rotate_b(t_list **stackb)
{
  if (*stackb && (*stackb)->next) {
    t_list *temp = *stackb;
    ft_lstadd_back(stackb, ft_lstnew(temp->content));
    *stackb = (*stackb)->next;
    free(temp);
    printf("rb\n");
  }
}