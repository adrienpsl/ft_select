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
void set_el(t_el *el, char *data, int selected, int current, t_array *array);
t_array *testing_array(void);

/*
**	handling the list element
*/
int get_min_size(t_array *array);

/*
**	Handling the canonical mode
*/
int set_canonical(struct termios *termios_backup);
int unset_canonical_mode(struct termios *backup_termios);

/*
**	Signal
*/
void catch_all_signal(void);

/*
**	Termcaps
*/
int load_termcaps(t_term *t);
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
bool get_window_size(t_window *w, int nb_elements, int size_el);
bool is_good_index(int index, int nb_elements);
void start_display(t_sct *s);
int putchar_on_fd_0(int a);

/*
**	getter
*/
t_sct *get_sct(t_sct *s);
t_term *get_term(void);

/*
**	Print
*/
void print_data(t_array *els, t_term *t, t_window *w, int size_el);

/*
**	cursor interaction
*/
int move_selector(int step_size, t_sct *s);
int space(t_sct *s);
int del(t_sct *s);
int dispatch_user_key(char *buffer, t_sct *s);

/*
**	Buffer
*/
int loop_user_input(t_sct *s);
void quit_binary(t_array *elements, struct termios *backup);

#endif
