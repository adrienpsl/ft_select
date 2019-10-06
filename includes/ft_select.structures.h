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
	char		*data;
	int			is_selected;
	int			is_current;
}				t_el;

typedef struct	s_signal
{
	char ctrl_c:1;
	char ctrl_z:1;
	char change_window:1;
}		t_signal;

typedef struct	s_sct
{
	t_array			*elememens;
	int				min_size;
	struct termios	termios;
	t_signal		*signal;
}					t_sct;



#endif
