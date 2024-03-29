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

int		g_current(void)
{
	return (get_sct()->current);
}

int		*set_current(void)
{
	return (&get_sct()->current);
}

int		get_elements_length(void)
{
	return (get_elements()->length - 1);
}

char	*get_buffer(void)
{
	if (get_sct()->buffer == NULL)
		return (NULL);
	return (get_sct()->buffer);
}

char	**set_buffer(void)
{
	return (&get_sct()->buffer);
}
