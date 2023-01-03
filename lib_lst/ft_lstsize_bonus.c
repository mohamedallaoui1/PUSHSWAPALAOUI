/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 23:16:08 by mabahani          #+#    #+#             */
/*   Updated: 2022/12/18 19:04:55 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swappush.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = lst;
	if (lst)
	{
		while (temp)
		{
			temp = temp->next;
			i++;
		}
	}
	return (i);
}



