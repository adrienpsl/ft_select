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

t_sct		*set_sct(t_sct *s)
{
	static t_sct *ptr = NULL;

	if (NULL != s)
		ptr = s;
	return (ptr);
}

t_sct		*get_sct(void)
{
	return (set_sct(NULL));
}

t_term		*get_term(void)
{
	return (&get_sct()->term);
}

t_wind	*get_win(void)
{
	return (&get_sct()->window);
}

t_array		*get_elements(void)
{
	return (get_sct()->elements);
}
