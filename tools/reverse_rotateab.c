/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotateab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:57:13 by mabahani          #+#    #+#             */
/*   Updated: 2022/12/18 19:06:46 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../swappush.h"

void reverse_rotateab(t_list **stacka, t_list **stackb)
{
    reverse_rotate_stack_a(stacka);
    reverse_rotate_stack_b(stackb);
    printf("rrr\n");
}