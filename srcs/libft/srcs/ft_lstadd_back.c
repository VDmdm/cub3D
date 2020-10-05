/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:07:20 by jalvaro           #+#    #+#             */
/*   Updated: 2020/05/01 23:49:41 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *beg;

	if (lst && new)
	{
		if (*lst == 0)
			*lst = new;
		else
		{
			beg = ft_lstlast(*lst);
			beg->next = new;
		}
	}
}
