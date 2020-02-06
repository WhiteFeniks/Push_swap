/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 21:30:19 by umoff             #+#    #+#             */
/*   Updated: 2020/02/03 21:30:21 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (!alst)
		return ;
	if (!del)
		return ;
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	(*alst)->content = NULL;
	(*alst)->content_size = 0;
	*alst = NULL;
}
