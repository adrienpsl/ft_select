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

#include "ft_select.h"

bool get_window_size(void)
{
	if (-1 == ioctl(STDIN_FILENO, TIOCGWINSZ, &g_select.size))
		return (false);
	else
		return (true);
}

bool is_screen_wide_enough(int size_max, int nb_elements)
{
	int nb_by_line;
	int nb_total;

	size_max += 1;
	if (false == get_window_size())
		return (false);
	nb_by_line = (g_select.size.ws_col / size_max);
	nb_total = nb_by_line * g_select.size.ws_row;
	return (nb_total <= nb_elements);
}
// j'ai la taille de ma window, comment je regarde si je peux bouger?
// a droite : mon index de line + 1 * la size min <, taille window ?
// a gauche : inferieur. comment je get mon index ?
// je vais le mettre dans mon tableau !
// dailleur si mon tableau pouvais juste etre un array de ptr ce serai plus opti
//

// look if I can move at left rigth botton of up.
// if I can, I had to
