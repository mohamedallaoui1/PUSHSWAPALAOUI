/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:38:49 by mabahani          #+#    #+#             */
/*   Updated: 2022/12/18 19:04:44 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swappush.h"

size_t	ft_strlen(const char *s)
{
	//protection to safely impliment it on other functions 
	if (!s)
		return(0);
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
