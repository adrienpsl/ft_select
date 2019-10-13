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

static char get_type(char *file_name)
{
	int i;
	struct stat fs;
	static char *char_type = "bcpdls-";
	static int filters[7] =
		{ S_IFBLK, S_IFCHR, S_IFIFO, S_IFDIR, S_IFLNK, S_IFSOCK, S_IFREG };

	if (OK != lstat(file_name, &fs))
		return (false);
	i = 0;
	while (i < 7)
	{
		if ((S_IFMT & fs.st_mode) == filters[i])
			return (char_type[i]);
		i++;
	}
	return (false);
}

void print_color_file(char *file_name)
{
	static char type;

	type = get_type(file_name);
	if (type == false)
		return;
	if (type == 'd')
		tputs(BLUE, 1, putchar_0);
	if (type == 'l')
		tputs(MAGENTA, 1, putchar_0);
	if (type == '-')
		return;
	if (type == 'c')
		tputs(GREEN, 1, putchar_0);
	if (type == 'b')
		tputs(YELLOW, 1, putchar_0);
}













