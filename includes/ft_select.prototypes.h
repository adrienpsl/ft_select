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

#ifndef FT_SELECT_PROTOTYPES_H
#define FT_SELECT_PROTOTYPES_H

/*
**	handling the list element
*/
int get_min_size(t_array *array);
int init_ftselect(int ac, char **av, t_sct *select);

/*
**	Handling the canonical mode
*/
int set_canonical_mode(struct termios *backup_termios);
int unset_canonical_mode(struct termios *backup_termios);

/*
**	Signal
*/
void catch_all_signal(void);

#endif
