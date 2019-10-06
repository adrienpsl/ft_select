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

static void	sig_window_change(int sign)
{
	(void)sign;
	g_signal.change_window = 1;
}

static void	sig_ctrl_z(int sign)
{
	(void)sign;
	g_signal.ctrl_z = 1;
}

static void	sig_ctrl_c(int sign)
{
	(void)sign;
	g_signal.ctrl_c = 1;
}

void catch_all_signal(void)
{
	signal(SIGWINCH, sig_window_change);
	signal(SIGTSTP, sig_ctrl_z);
	signal(SIGINT, sig_ctrl_c);
}