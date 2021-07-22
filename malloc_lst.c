/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:38:12 by abourdar          #+#    #+#             */
/*   Updated: 2021/07/19 10:38:15 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	*lst_add(t_map *map, void *ptr)
{
	t_list	*elem;

	elem = ft_lstnew(ptr);
	if (!(elem))
	{
		free(ptr);
		return (NULL);
	}
	if (!(map->ptrs))
		map->ptrs = elem;
	else
		ft_lstadd_back(&map->ptrs, elem);
	return (ptr);
}

void	*malloc_list(t_map *map, int size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	if (!lst_add(map, ptr))
	{
		free(ptr);
		return (NULL);
	}
	return (ptr);
}

void	*free_malloc_lst(t_map *map)
{
	ft_lstclear(&map->ptrs, free);
	return (0);
}
