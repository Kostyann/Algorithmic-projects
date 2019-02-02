
















































t_room	**get_rooms(t_farm *farm)
{
	t_room	**rooms;
	char	*line;
	char 	**split = 0;
	int 	valid;
	int 	start = 0;
	int 	end = 0;
	int 	nodes = 5;
	int 	i;
	int 	fd;

	valid = 1;
	i = -1;
	rooms = (t_room**)ft_memalloc(sizeof(t_room*) * (nodes + 1));
	fd = 0;
	while ((get_next_line(fd, &line) > 0) && valid)
	{
		if (i == nodes)
		{
			nodes *= 2;
			rooms = (t_room**)ft_realloc(rooms, sizeof(t_room*) * (nodes + 1));
		}
		if (i == -1)
		{
			if ((farm->ants = ft_atoi(line)) > 0)
				i++;
			else
			{
				ft_printf("ERROR: no ants!\n");
				exit(0);
			}
		}
		else if (ft_strequ(line, "##start"))
			start = 1;
		else if (ft_strequ(line, "##end"))
			end = 1;
		else if ((line[0] == '#' && line[1] != '#') ||
				 (line[0] == '#' && line[1] == '#' && line[2] != '#'))
			;
		else if (ft_strchr(line, ' '))
		{
			split = ft_strsplit(line, ' ');
			if (split[3] || !split[2])
				break ;
			rooms[i] = (t_room*)ft_memalloc(sizeof(t_room) + 1);
			rooms[i]->name = ft_strdup(split[0]);
			rooms[i]->index = ft_itoa(i);
			rooms[i]->x = ft_atoi(split[1]);
			rooms[i]->y = ft_atoi(split[2]);
			if (start)
			{
				rooms[i]->status = 1;
				start = 0;
			}
			else if (end)
			{
				rooms[i]->status = 2;
				end = 0;
			}
			i++;
		}
		else if (ft_strchr(line, '-'))
		{
			split = ft_strsplit(line, '-');
			if (split[2] || !split[1])
				break ;
			if (!(add_link(rooms, split[0], split[1])))
			{
				ft_printf("ERROR: wrong link!\n");
				exit(0);
			}
			add_link(rooms, split[1], split[0]);
		}
		else
			valid = 0;
		if (split)
			ft_memdel_arr((void***)&split);
		free(line);
	}
	rooms[i] = 0;
	return (rooms);
}