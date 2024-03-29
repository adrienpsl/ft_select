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

/*
**	Set terminal in canonical mode, and save the origin config in backup
*/

int	set_canonical(struct termios *termios_backup)
{
	struct termios new_termios;

	ft_bzero(termios_backup, sizeof(struct termios));
	if (-1 == tcgetattr(STDIN_FILENO, &new_termios)
		|| -1 == tcgetattr(STDIN_FILENO, termios_backup))
	{
		ft_dprintf(2, FT_SELECT_NAME
		"can't set the canonical terminal mode !");
		return (-1);
	}
	new_termios.c_lflag &= ~(ICANON | ECHO);
	new_termios.c_cc[VMIN] = 1;
	new_termios.c_cc[VTIME] = 0;
	if (-1 == tcsetattr(STDIN_FILENO, TCSANOW, &new_termios))
		return (-1);
	return (OK);
}

/*
**	Reset the backup terminal config
*/

int	unset_canonical_mode(struct termios *backup_termios)
{
	if (-1 == tcsetattr(STDIN_FILENO, TCSANOW, backup_termios))
	{
		ft_dprintf(2, FT_SELECT_NAME"can't set the original terminal mode !");
		return (-1);
	}
	return (OK);
}
