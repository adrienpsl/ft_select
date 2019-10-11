/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:50 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_STRUCTURES_H
#define FT_SELECT_STRUCTURES_H

# include <ft_array.structure.h>
# include <termios.h>

typedef struct	s_el
{
	char		*text;
	int			is_selected;
	int			is_current;
}				t_el;

typedef struct	s_term
{
	char		*move;
	char		*underline;
	char		*reverse;
	char		*clean;
	char		*clear_screen;
}				t_term;

typedef struct s_pos
{
	int x;
	int y;
} t_pos;

typedef struct s_window{
	int				elem_by_line;
	int				nb_lines;
	int				is_enough;
} t_window;

typedef struct	s_sct
{
	t_array			*elements;
	int				size_el;
	t_term			term;
	t_window		window;
	int				current;
	int				termios_set;
	struct termios	termios;
}					t_sct;



#endif
