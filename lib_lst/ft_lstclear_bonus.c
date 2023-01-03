/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:37:01 by mabahani          #+#    #+#             */
/*   Updated: 2022/12/18 19:05:04 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swappush.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*saver;

	if (*lst && del)
	{
		while (*lst)
		{
			saver = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = saver;
		}
	}
}
