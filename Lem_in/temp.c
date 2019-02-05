


















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
							} */

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














