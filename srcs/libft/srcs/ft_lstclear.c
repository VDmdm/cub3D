/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:07:31 by jalvaro           #+#    #+#             */
/*   Updated: 2020/05/01 23:49:34 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *beg;
	t_list *tmp;

	beg = *lst;
	while (beg && del)
	{
		tmp = beg->next;
		del(beg->content);
		free(beg);
		beg = tmp;
	}
	*lst = 0;
}
