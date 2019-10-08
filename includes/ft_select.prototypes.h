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

#include <stdbool.h>

// tmp
bool is_screen_wide_enouth(int size_max, int nb_element);


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

/*
**	Termcaps
*/
int load_term_caps(void);

/*
**	CSS
*/
void print_in_underline_reverse(char *text);
void print_in_reverse(char *text);
void print_in_underline(char *text);
void clear_screen(void);


#endif
