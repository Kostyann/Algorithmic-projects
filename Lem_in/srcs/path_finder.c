/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:27:43 by kmerkulo          #+#    #+#             */
/*   Updated: 2019/01/30 16:27:45 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

// Function that finds broken needle in a haystack (add to libft?)

int		ft_strbrstr(t_room **haystack, t_room **needle)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (haystack[++i])
	{
		while (haystack[i + j] && ft_strequ(haystack[i + j]->index, needle[j]->index))
			j++;
		if (!needle[j])
			return (1);
	}
	i = -1;
	j = 0;
	while (needle[++i])
	{
		while (needle[i + j] && ft_strequ(needle[i + j]->index, haystack[j]->index))
			j++;
		if (!haystack[j])
			return (1);
	}
	return (0);
}

// ^ function that finds broken needle in a haystack (add to libft?)

int		path_exists(t_farm *farm, t_room *start, int *checked)
{
	int	i = -1;
	checked[ft_atoi(start->index)] = 1;

	while (start->edges[++i])
	{
		if (ft_strequ(start->edges[i]->index, farm->e_index))
			return (1);
		if (!(checked[ft_atoi(start->edges[i]->index)]))
			if (path_exists(farm, start->edges[i], checked))
				return (1);
	}
	return (0);
}

int		find_paths(t_farm *farm, t_room *start, t_path **paths, int *checked, int *j)
{
	int	i = -1;
	checked[ft_atoi(start->index)] = 1;
	paths[*j]->path[++(paths[*j]->depth)] = start;

	while (start->edges[++i])
	{
		if (ft_strequ(start->edges[i]->index, farm->e_index))
		{
			paths[*j]->path[++(paths[*j]->depth)] = start->edges[i];
			checked[ft_atoi(start->index)] = 0;
			return (1);
		}
	}
	i = -1;
	while (start->edges[++i])
	{
		if (!(checked[ft_atoi(start->edges[i]->index)]))
		{
			if (find_paths(farm, start->edges[i], paths, checked, j))
			{
				(*j)++;
				paths[*j] = (t_path*)ft_memalloc(sizeof(t_path) + 1);
				paths[*j]->path = (t_room**)ft_memalloc(sizeof(t_room*)
														* (farm->quantity * 2 + 1));
				paths[*j]->depth = paths[*j - 1]->depth - 2;
				paths[*j]->path = ft_memcpy(paths[*j]->path,
											paths[*j - 1]->path,
											sizeof(paths[*j - 1]->path) * (paths[*j - 1]->depth - 1));
			}
			else
			{
				paths[*j]->path[(paths[*j]->depth)--] = 0;
				checked[ft_atoi(start->edges[i]->index)] = 0;
			}
		}
	}
	return (0);
}

void	check_valid(t_path **paths)
{
	int	i = -1;
	int	j;

	while (paths[++i])
	{
		if (!paths[i]->invalid)
		{
			j = 0;
			while (paths[i + ++j])
			{
				if (!paths[i + j]->invalid && ft_strbrstr(paths[i]->path, paths[i + j]->path))
				{

					if (paths[i]->depth > paths[i + j]->depth)
						paths[i]->invalid = 1;
					else
						paths[i + j]->invalid = 1;
				}
			}
		}
	}
}

int		no_end(t_room **path, int index)
{
	int i = 0;

	while (path[i])
		i++;
	if (ft_atoi(path[i - 1]->index) == index)
		return (0);
	return (1);

}

t_path	**get_paths(t_farm *farm)
{
	t_path	**paths;
	int 	*checked;
	int 	j = 0;

	checked = (int*)ft_memalloc(sizeof(int) * (farm->quantity + 1));
	paths = (t_path**)ft_memalloc(sizeof(t_path*) * (farm->quantity / 2
													 * (farm->quantity + 1)));
	paths[j] = (t_path*)ft_memalloc(sizeof(t_path) + 1);
	paths[j]->path = (t_room**)ft_memalloc(sizeof(t_room*) * (farm->quantity + 1));
	paths[j]->depth = -1;
	ft_printf("path exists? - %d\n", path_exists(farm, farm->rooms[ft_atoi(farm->s_index)], checked));
	find_paths(farm, farm->rooms[ft_atoi(farm->s_index)], paths, checked, &j);
	if (no_end(paths[j]->path, ft_atoi(farm->e_index)))
	{
		ft_memdel((void**)&paths[j]->path);
		ft_memdel((void**)&paths[j]);
	}
//	while (++i < farm->quantity)
//		ft_printf("%d ", checked[i]);

	check_valid(paths);

	free(checked);
	return (paths);
}