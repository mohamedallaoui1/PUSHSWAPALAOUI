/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:08:01 by mabahani          #+#    #+#             */
/*   Updated: 2022/12/18 19:05:07 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swappush.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
	else
	{
		*lst = new;
	}
}
// void del(void *lst){
//     free(lst);
// }
// void f(void *c)
// {
//     char *d = (char *)c;
//     int i = 0;
//     while(i < strlen(d))
//     {
//     if(islower(*d))
//         *d = *d - 32;
//     d++;
//     }
// }


// // void f(void *c)
// // {
// //     int i = 0;
// //     while  (((char *)c)[i])
// //     {
// //         ((char *)c)[i] -= 32;
// //         i++;
// //     }
// // }
// int main()
// {
//     t_list *head = NULL;
//     t_list *nod1 = malloc(sizeof(t_list));
//     t_list *nod2 = malloc(sizeof(t_list));
//     t_list *nod3 = malloc(sizeof(t_list));
//     t_list *temp;
//     t_list *addfr = ft_lstnew(ft_strdup("hello they added me to the front i should be at the top :)"));
//     t_list *addbc = ft_lstnew(ft_strdup("hello they added me to the back i'm sad :("));


//     head = nod1;
//     nod1->next = nod2;
//     nod1->content = ft_strdup("i'm in nod1");
//     nod2->next = nod3;
//     nod2->content = ft_strdup("i'm in nod2");
//     nod3->next = NULL;
//     nod3->content = ft_strdup("i'm in nod3");

//     ft_lstadd_front(&head,addfr);
//     ft_lstadd_back(&head,addbc);
//     //ft_lstdelone(nod2,del);
//     //ft_lstclear(&nod2,del);
//     ft_lstiter(head,f);
//     temp = head;
//     while(temp)
//     {
//         printf(" > %s\n",temp->content);
//         temp = temp->next;
//     }

// }