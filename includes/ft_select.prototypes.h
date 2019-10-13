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
void test(t_sct *s);

/*
**	Helpers
*/
int go_last(void);
int go_first(void);

/*
**	getter
*/
t_sct *set_sct(t_sct *s);
t_sct *get_sct(void);
t_term *get_term(void);
t_window *get_win(void);
t_array *get_elements(void);
int get_elements_length(void);

int g_current(void);
int *set_current(void);

char *get_buffer(void);
char **set_buffer(void);

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
int handle_all_signal(void);

/*
**	Termcaps
*/
int load_termcaps(t_term *t);
bool put_termcaps(char *name);

/*
**	CSS
*/
int print_in_underline_reverse(char *text);
int print_in_reverse(char *text);
int print_in_underline(char *text);
int clear_screen(void);

/*
**	utils
*/
bool get_window_size(t_window *w, int nb_elements, int size_el);
bool is_good_index(int index, int nb_elements);
void get_window_and_print(t_sct *s);

/*
**	Display
*/
void move_display(int step);

/*
**	Print
*/
void print_list(t_array *els);
void print_color_file(char *file_name);

/*
**	cursor interaction
*/
int move_selector(int step_size, t_sct *s);
int space(t_sct *s);
int del(t_sct *s);
int dispatch_user_key(long *buffer, t_sct *s);
int putchar_0(int c);

/*
**	Buffer
*/
int loop_user_input(t_sct *s);
void quit_binary(t_array *elements, struct termios *backup);

#endif
