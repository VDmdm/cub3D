/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:07:55 by jalvaro           #+#    #+#             */
/*   Updated: 2020/05/01 23:49:21 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_n;
	t_list	*temp;

	lst_n = 0;
	if (!lst || !f || !del)
		return (0);
	while (lst)
	{
		if (!(temp = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&lst_n, del);
			return (0);
		}
		ft_lstadd_back(&lst_n, temp);
		lst = lst->next;
	}
	return (lst_n);
}
