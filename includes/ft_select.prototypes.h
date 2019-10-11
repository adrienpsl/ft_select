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
bool is_screen_wide_enough(int size_max, int nb_elements);
void set_el(t_el *el, char *data, int selected, int current, t_array *array);
t_array *testing_array(void);



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
bool put_termcaps(char *name);

/*
**	CSS
*/
void print_in_underline_reverse(char *text);
void print_in_reverse(char *text);
void print_in_underline(char *text);
void clear_screen(void);

/*
**	utils
*/
bool get_window_size(t_window *w, int nb_elements);
bool is_good_index(int index);


/*
**	Print
*/
void loop_and_print(t_array *array);

/*
**	cursor interaction
*/
void move_if_valid_new_index(int step_size, t_sct *s);
void space(t_sct *s);
void del(t_sct *s);

/*
**	Buffer
*/
int ms__get_line(t_sct *s);



#endif
