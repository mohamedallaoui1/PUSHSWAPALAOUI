/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:51:42 by mabahani          #+#    #+#             */
/*   Updated: 2022/12/18 19:05:10 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swappush.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (*lst && new)
	{
		temp = ft_lstlast(*lst);
		temp->next = new;
	}
	else
		*lst = new;
}

