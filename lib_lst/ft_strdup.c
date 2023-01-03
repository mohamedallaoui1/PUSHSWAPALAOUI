/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 11:15:19 by mabahani          #+#    #+#             */
/*   Updated: 2022/12/18 19:04:51 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swappush.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		len;
	int		i;

	if(!s1)
		return(NULL);
	i = 0;
	len = ft_strlen(s1);
	ptr = malloc((len + 1) * sizeof(char));
	if (ptr != NULL)
	{
		while (i < len)
		{
			ptr[i] = s1[i];
			i++;
		}
		ptr[i] = '\0';
	}
	return (ptr);
}
