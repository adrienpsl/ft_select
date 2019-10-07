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

void print_in_underline(char *text)
{
	tputs(tgetstr("us", NULL), 1, ft_putchar);
	ft_printf(text);
	tputs(tgetstr("me", NULL), 1, ft_putchar);
}

void print_in_reverse(char *text)
{
	tputs(tgetstr("mr", NULL), 1, ft_putchar);
	ft_printf(text);
	tputs(tgetstr("me", NULL), 1, ft_putchar);
}

void print_in_underline_reverse(char *text)
{
	tputs(tgetstr("mr", NULL), 1, ft_putchar);
	tputs(tgetstr("us", NULL), 1, ft_putchar);
	ft_printf(text);
	tputs(tgetstr("me", NULL), 1, ft_putchar);
}
