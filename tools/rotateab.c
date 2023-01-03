/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotateab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:57:29 by mabahani          #+#    #+#             */
/*   Updated: 2022/12/18 19:06:57 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../swappush.h"

void rotateab(t_list **stacka, t_list **stackb)
{
    rotate_a(stacka);
    rotate_b(stackb);
    printf("rr\n");
}