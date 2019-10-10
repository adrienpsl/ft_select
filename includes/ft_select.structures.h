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

typedef struct	s_sct
{
	t_array			*elememens;
	int				min_size;
	t_term			term;
	int				current;
	struct termios	termios;
	struct winsize size;
}					t_sct;



#endif
