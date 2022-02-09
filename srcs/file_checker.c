/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:30:25 by abonniss          #+#    #+#             */
/*   Updated: 2022/02/09 17:37:56 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long.h"

void	check_file_access(const char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == BAD_FILE_DESCRIPTOR)
		exit_routine(NULL, ERR_BAD_FD);
	close(fd);
}

void	check_file_extension(const char *file_name)
{
	size_t	name_len;
	size_t	i;

	name_len = ft_strlen(file_name);
	i = 0;
	if (name_len <= EXTENSION_LEN)
		exit_routine(NULL, ERR_WRONG_EXTENSION);
	while (i <= EXTENSION_LEN)
	{
		if ((file_name[(name_len - EXTENSION_LEN) + i] != EXTENSION_NAME[i]))
		{
			exit_routine(NULL, ERR_WRONG_EXTENSION);
		}
		++i;
	}
}

void	check_file(const char *file_name)
{	
	check_file_access(file_name);
	check_file_extension(file_name);
}
