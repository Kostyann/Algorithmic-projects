/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:50:44 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/11/10 12:50:45 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char				*ft_strnew(size_t size);
int					check_tet(int *list);
int					check_valid(char *buf, int i, int j);
int					read_tet(char *source);
int					power_two(int power);
void				print_field(char **field);
void				save_tet(int t);
int					ft_sqrt(int num);
char				**create_field(int t);
int					check_free(char ***field, int fi, int fj, int *coord);
void				clear_tets(char ***field, int fi, int fj, int *coord);
int					place_tets(char ***field, int quant, int to_place);

int					g_comb_numbs[27][17];
int					**g_coord;

#endif
