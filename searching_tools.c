#include "swappush.h"

// now we gonna make a function that searches for the first appearance of any number of the table in the stack
// and returns the index of the number
int search_first_appearance(t_list **stacka, int *tab, int size)
{
    int i = 0;
    int j = 0;
    int index = -1;
    t_list *tmp = *stacka;
    if(stacka == NULL)
        return (-1);
    while (tmp)
    {
        i = 0;
        while (i < size)
        {
            if (tmp->content == tab[i])
            {
                index = j;
                return (index);
            }
            i++;
        }
        tmp = tmp->next;
        j++;
    }
    return (index);
}
// now we gonna make a function that searches for the last appearance of any number of the table in the stack
// and returns the index of the number and to do so we gonna keep searching for the number 
// whenever we find it we gonna save the index and keep searching until the end of the stack
// then we gonna return the last index we found
int search_last_appearance(t_list **stacka, int *tab, int size)
{
    int i = 0;
    int j = 0;
    int index = -1;
    t_list *tmp = *stacka;
    if(stacka == NULL)
        return (-1);
    while (tmp)
    {
        i = 0;
        while (i < size)
        {
            if (tmp->content == tab[i])
            {
                index = j;
            }
            i++;
        }
        tmp = tmp->next;
        j++;
    }
    return (index);
}
//we'll make a function that takes the two indexes of the first and last appearance of the number 
// what we need to do is simple we gonna take the two indexes and test if the index belongs to the first half if it does we'll test 
// how much distance between it and the top of the stack and if it's belongs in the lower half we'll test how much distance between it and the bottom of the stack
// and then we return the index of the winner in other words the one with less distance to the top or bottom of the stack
int closest_to_the_exit(t_list **stacka,int *tab, int sizetab)
{
    int distancefront;
    int distancelast;
    int size;
    int indlast;
    int indfront;

    distancelast = 0;
    distancefront = 0;
    indfront = search_first_appearance(stacka, tab, sizetab);
    //printf("indfront = %d\n", indfront);
    indlast = search_last_appearance(stacka, tab, sizetab);
    //printf("indlast = %d\n", indlast);
    size = ft_lstsize(*stacka);
    if(indlast < size / 2)
        distancefront = indlast + 1;
    else
        distancefront = size - indlast + 1;
    //printf("distancelast = %d\n", distancefront);
    if(indfront < size / 2)
        distancelast = indfront + 1;
    else
        distancelast = size - indfront + 1;
    //printf("distancefront = %d\n", distancelast);
    if(distancefront < distancelast)
        return (indlast);
    else if(distancefront == distancelast)
            return (indlast);
    else
        return (indfront);
}

// now let's test this if it woks we'll creat a list of 10 random numbers and use the search functions to find the first and last appearance of 3 numbers
// and then we'll use the closest to top function to determine which of the two indexes is the closest to the top of the stack
// we'll print the index and the R value to see if it's working

// int main()
// {
//     t_list *stacka = NULL;
//     int tab[3] = {75, 272, 252};
//     int indexlast = 0;
//     int indexfront = 0;
//     int index = 0;
//     int i = 0;
//     ft_lstadd_back(&stacka, ft_lstnew(1));
//     ft_lstadd_back(&stacka, ft_lstnew(75));
//     ft_lstadd_back(&stacka, ft_lstnew(3));
//     ft_lstadd_back(&stacka, ft_lstnew(5));
//     ft_lstadd_back(&stacka, ft_lstnew(5772));
//     ft_lstadd_back(&stacka, ft_lstnew(6));
//     ft_lstadd_back(&stacka, ft_lstnew(272));
//     ft_lstadd_back(&stacka, ft_lstnew(8));
//     ft_lstadd_back(&stacka, ft_lstnew(252));
//     ft_lstadd_back(&stacka, ft_lstnew(10));
//     indexlast = search_last_appearance(&stacka, tab, 3);
//     indexfront = search_first_appearance(&stacka, tab, 3);
//     printf("indexlast = %d\n", indexlast);
//     printf("indexfront = %d\n", indexfront);
//     index = closest_to_the_exit(&stacka, indexlast, indexfront);
//     printf("index = %d\n", index);
//     return (0);
// }

