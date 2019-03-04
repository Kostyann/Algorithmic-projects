




#include <stdio.h>
#include <stdint.h>

int main(void)
{
	uint16_t x = 1; /* 0x0001 */
	printf("%s\n", *((uint8_t *) &x) == 0 ? "big-endian" : "little-endian");
	return (0);
}


















/*
void	print_paths(t_path **paths, t_farm *farm)
{
	int	i = -1;
	int j = -1;


	ft_printf("POSSIBLE PATHS\n -----------------------------------\n");
	while (paths[++j])
	{
		i = -1;
		if (!paths[j]->invalid)
		{
			ft_printf("Depth %d\n", paths[j]->depth);
//			ft_printf("Invalid? %d\n", paths[j]->invalid);
			ft_printf("Path #%d: ", j);
			while (paths[j]->path[++i])
			{
//		ft_printf("lala\n");
				if (i == 0)
					ft_printf("%s", paths[j]->path[i]->name);
				else
					ft_printf("--> %s", paths[j]->path[i]->name);
				/*			if (paths[j]->path[i]->arrivals)
							{
								k = -1;
								ft_printf("\nArrivals[");
								while (++k < (farm->ants + farm->rooms_n))
									ft_printf("%d, ", paths[j]->path[i]->arrivals[k]);
								ft_printf("]\n");
							}

			}
			ft_printf("\n");
		}
	}
	ft_printf(" -----------------------------------\n");
}

void	print_farm(t_farm *farm)
{
	int i = -1;
	int j;

	ft_printf(" -----------------------------------\n");
	ft_printf("GRAPG REPRESENTATION (Adjacency list)\n -----------------------------------\n");
	ft_printf("Number of ants - %d\n", farm->ants);
	ft_printf("Number of rooms - %d\n", farm->rooms_n);
	ft_printf("Start index - %s\n", farm->s_index);
	ft_printf("End index - %s\n", farm->e_index);
	while (farm->rooms[++i])
	{
		j = -1;
		ft_printf("%-3s ", farm->rooms[i]->index);
		ft_printf("%-6s ", farm->rooms[i]->name);
		if (farm->rooms[i]->edges)
			while (farm->rooms[i]->edges[++j])
				ft_printf("->%-7s", farm->rooms[i]->edges[j]->name);
		ft_printf("\n");
	}
	ft_printf(" -----------------------------------\n");
}


// BFS

int		shortest_path(t_farm *farm, int *checked)
{
	int k;
	int	i;
	int j;

	farm->bfs_to_visit = (t_room**)ft_memalloc(sizeof(t_room*) * (farm->rooms_n + 1));
	farm->bfs_to_visit[0] = farm->rooms[ft_atoi(farm->s_index)];
	k = -1;
	while (farm->bfs_to_visit[++k])
	{
		i = -1;
		checked[ft_atoi(farm->bfs_to_visit[k]->index)] = 1;
		while (farm->bfs_to_visit[k]->edges[++i])
		{
			if (!farm->bfs_to_visit[k]->edges[i]->depth)
				farm->bfs_to_visit[k]->edges[i]->depth = farm->bfs_to_visit[k]->depth + 1;
			if (ft_strequ(farm->bfs_to_visit[k]->edges[i]->index, farm->e_index))
				return (farm->bfs_to_visit[k]->edges[i]->depth);
		}

		i = -1;
		while (farm->bfs_to_visit[k]->edges[++i])
		{
			if (!(checked[ft_atoi(farm->bfs_to_visit[k]->edges[i]->index)]))
			{
				j = -1;
				while (farm->bfs_to_visit[++j])
					;
				farm->bfs_to_visit[j] = farm->bfs_to_visit[k]->edges[i];
			}
		}
	}
	free(farm->bfs_to_visit);
	return (0);
}

*/

void	clean_member(t_path **paths, int w)
{
	int	i;
	int p;
	int	victim;

	i = 0;
	victim = 0;
/*	while (++i < paths[w]->depth)
		if (victim == 0 || paths[w]->path[i]->edges_n > paths[w]->path[victim]->edges_n)
			victim = i;
	paths[w]->path[victim]->blocked = w + 1;
	ft_printf("victim name - %s\n", paths[w]->path[victim]->name);
	p = 0;
	while (w - p++ > 0 && p < 30)
	{
		i = -1;
		while (paths[w - p]->path[++i])
			if (paths[w - p]->path[i] == paths[w]->path[victim])
			{
				i = -1;
		//		ft_printf("lala\n");
				while (paths[w - p]->path[++i])
				{
		//			ft_printf("lalaz\n");
					if (paths[w - p]->path[i]->blocked &&
						paths[w - p]->path[i]->blocked == w - p + 1)
						paths[w - p]->path[i]->blocked = 0;
				}


			}
	} */


}


int		check_edges_dfs(t_farm *farm, t_path **paths, int *checked, int *j)
{
	int		i;
	t_room	*start;

	i = -1;
	start = farm->rooms[ft_atoi(farm->s_index)];
	checked[ft_atoi(start->index)] = 1;
	paths[*j]->path[++(paths[*j]->depth)] = start;
	while (start->edges[++i])
		if (ft_strequ(start->edges[i]->index, farm->e_index))
		{
			paths[*j]->path[++(paths[*j]->depth)] = start->edges[i];
			checked[ft_atoi(start->index)] = 0;
			return (1);
		}
	return (0);
}

int		find_paths_dfs(t_farm *farm, t_path **paths, int *checked, int *j)
{
	int		i;
	t_room	*start;

	start = farm->rooms[ft_atoi(farm->s_index)];
	if ((i = -1) == -1 && check_edges_dfs(farm, paths, checked, j))
		return (1);
	while (start->edges[++i])
		if (!(checked[ft_atoi(start->edges[i]->index)]))
		{
			farm->s_index = start->edges[i]->index;
			if (find_paths_dfs(farm, paths, checked, j))
			{
				if (*j >= 600)
					return (1);
				(*j)++;
				path_mem(farm, paths, *j, paths[*j - 1]->depth - 2);
				paths[*j]->path = ft_memcpy(paths[*j]->path, paths[*j - 1]->path,
											sizeof(paths[*j - 1]->path) * (paths[*j - 1]->depth - 1));
			}
			else
			{
				paths[*j]->path[(paths[*j]->depth)--] = 0;
				checked[ft_atoi(start->edges[i]->index)] = 0;
			}
		}
	return (0);
}

int		ft_strbrstr(t_room **haystack, t_room **needle)
{
	int i;
	int j;

	i = -1;
	while (haystack[++i])
	{
		j = 0;
		while (haystack[i + j] && needle[j] &&
			   ft_strequ(haystack[i + j]->index, needle[j]->index))
			j++;
		if (!needle[j])
			return (1);
	}
	i = -1;
	while (needle[++i])
	{
		j = 0;
		while (needle[i + j] && haystack[j] &&
			   ft_strequ(needle[i + j]->index, haystack[j]->index))
			j++;
		if (!haystack[j])
			return (1);
	}
	return (0);
}

void	check_valid(t_path **paths)
{
	int	i;
	int	j;

	i = -1;
	while (paths[++i])
	{
		if (!paths[i]->invalid)
		{
			j = 0;
			while (paths[i + ++j])
			{
				if (!paths[i + j]->invalid && ft_strbrstr(paths[i]->path,
														  paths[i + j]->path))
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







