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

#ifndef FT_SELECT_DEFINES_H
#define FT_SELECT_DEFINES_H
// [
# define FT_SELECT_NAME "ft_select: "

# define FT_UP 		"\x1b" "\x5b" "\x41"
# define FT_DOWN 	"\x1b" "\x5b" "\x42"
# define FT_RIGHT	"\x1b" "\x5b" "\x43"
# define FT_LEFT	"\x1b" "\x5b" "\x44"
# define FT_ECHAP	"\x1b"
# define FT_DEL 	"\x1b" "\x5b" "\x33" "\x7e"
# define FT_BACKSPACE 	"\x7f"
# define FT_SPACE 	" "
# define FT_ENTER 	"\xa"


t_sct *g_select;

#endif
