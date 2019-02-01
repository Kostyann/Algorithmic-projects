













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