/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swappush.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 22:59:59 by mabahani          #+#    #+#             */
/*   Updated: 2022/12/26 22:27:10 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAPPUSH_H
# define SWAPPUSH_H

typedef struct s_list
{
	int			content;
	struct s_list	*next;
}	t_list;

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>


t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
int	ft_atoi(const char	*str);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	**ft_split(char *str, char c);
int	ft_atoi(const char	*str);
void ultimate_sort(t_list **stacka, t_list **stackb, int howmany);
void sort3(t_list **stacka);
int closest_to_the_exit(t_list **stacka,int *tab, int sizetab);
void doublestackprinter(t_list **stacka, t_list **stackb);
void sort(t_list **stacka, t_list **stackb);
void stacka_fixer(t_list **stacka);
void stack_pusher(t_list **stacka,t_list **stackb ,int content);
int get_max(t_list *stack);
int get_min(t_list *stack);
int get_content(t_list *stack, int position);
int get_position(t_list *stack, int content);
void sort3(t_list **stacka);
void stack_pusher_a(t_list **stacka,t_list **stackb ,int content);
void stack_pusher_b(t_list **stacka,t_list **stackb ,int content);
void sort5(t_list **stacka, t_list **stackb);
void	free_double_ptr_int(int **ptr);
void	free_double_ptr_char(char **ptr);






void reverse_rotateab(t_list **stacka, t_list **stackb);
void reverse_rotate_stack_a(t_list **stacka);
void reverse_rotate_stack_b(t_list **stackb);
void rotate_a(t_list **stacka);
void rotate_b(t_list **stackb);
void rotateab(t_list **stacka, t_list **stackb);
void swapb(t_list **stackb);
void swapa(t_list **stacka);
void swapab(t_list **stacka, t_list **stackb);
void pusha(t_list **stacka, t_list **stackb);
void pushb(t_list **stacka, t_list **stackb);


#endif