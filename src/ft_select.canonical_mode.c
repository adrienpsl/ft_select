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

#include <ft_select.h>

int activate_canonical_mode(struct termios *backup_termios)
{
	struct termios new_termios;

	if (-1 == tcgetattr(STDIN_FILENO, &new_termios)
		|| -1 == tcgetattr(STDIN_FILENO, backup_termios))
	{
		ft_printf(FT_SELECT_NAME"can't set the canonical terminal mode !");
		return (-1);
	}
	new_termios.c_lflag &= ~(ICANON | ECHO);
	new_termios.c_cc[VMIN] = 1;
	new_termios.c_cc[VTIME] = 0;
	if (-1 == tcsetattr(STDIN_FILENO, TCSANOW, &new_termios))
		return (-1);
	return (OK);
}

int desactivate_canonical_mode(struct termios *backup_termios)
{
	if (-1 == tcsetattr(STDIN_FILENO, TCSANOW, backup_termios))
	{
		ft_printf(FT_SELECT_NAME"can't reset the original terminal mode !");
		return (-1);
	}
	return (OK);
}
