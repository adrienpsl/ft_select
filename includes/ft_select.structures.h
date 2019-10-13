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
#include <ft_s.h>

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
	char		*reset;
	char		*clear_screen;
}				t_term;

typedef struct s_pos
{
	int x;
	int y;
	// also, where I am ?
	// I mean : 
} t_pos;

typedef struct s_window{
	int				line_wide;
	int				nb_line;
	int				current_step;
	int				capacity;
	int				is_enough;
	int				last_step;
	int				window_y;
} t_window;

typedef struct	s_sct
{
	t_array			*elements;
	int				size_el;
	t_term			term;
	t_window		window;
	int				current;
	struct termios	termios;
	char *buffer;
	
	int	max_y;
	int	max_x;
	
}					t_sct;



#endif
